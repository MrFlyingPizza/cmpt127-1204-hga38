/*
 * imgops.c - Simple operations on images
 *
 * C laboratory exercises.
 * Richard Vaughan, 2014.
 */

#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*-------------------------------------------------
  PART 0: OPERATIONS ON A PIXEL 
*/

// get the value in the array at coordinate (x,y)
uint8_t get_pixel(const uint8_t array[],
                  unsigned int cols,
                  unsigned int rows,
                  unsigned int x,
                  unsigned int y)
{
    assert(x < cols);
    assert(y < rows);
    return array[y * cols + x];
}

// set the pixel at coordinate {x,y} to the specified color
void set_pixel(uint8_t array[],
               unsigned int cols,
               unsigned int rows,
               unsigned int x,
               unsigned int y,
               uint8_t color)
{
    assert(x < cols);
    assert(y < rows);
    array[y * cols + x] = color;
}

/*-------------------------------------------------
  PART 1: OPERATIONS ON THE WHOLE IMAGE 
*/

/* TASK 1 - Easy functions to get started */

// Set every pixel to 0 (black)
void zero(uint8_t array[],
          unsigned int cols,
          unsigned int rows)
{
    memset(array, 0, cols * rows * sizeof(array[0]));
}

// Returns a pointer to a freshly allocated array that contains the
// same values as the original array, or a null pointer if the
// allocation fails. The caller is responsible for freeing the array
// later.
uint8_t *copy(const uint8_t array[],
              unsigned int cols,
              unsigned int rows)
{
    uint8_t *copy_ptr;
    copy_ptr = malloc(cols * rows * sizeof(array[0]));
    if (copy_ptr != NULL)
    {
        return copy_ptr;
    }

    return NULL;
}

// Return the darkest color that appears in the array; i.e. the
// smallest value
uint8_t min(const uint8_t array[],
            unsigned int cols,
            unsigned int rows)
{
    uint8_t darkest = 255;
    for (size_t i = 0; i < cols * rows; i++)
    {
        if (array[i] < darkest)
        {
            darkest = array[i];
        }
    }

    return darkest;
}

// Return the lightest color that appears in the array; i.e. the
// largest value
uint8_t max(const uint8_t array[],
            unsigned int cols,
            unsigned int rows)
{
    uint8_t lightest = 0;
    for (size_t i = 0; i < cols * rows; i++)
    {
        if (array[i] > lightest)
        {
            lightest = array[i];
        }
    }
    return lightest;
}

// TASK 2

//  Replace every instance of pre_color with post_color.
void replace_color(uint8_t array[],
                   unsigned int cols,
                   unsigned int rows,
                   uint8_t pre_color,
                   uint8_t post_color)
{
    for (size_t i = 0; i < cols * rows; i++)
    {
        if (array[i] == pre_color)
        {
            array[i] = post_color;
        }
    }
}

/* TASK 3  - two functions */

// flip the image, left-to-right, like in a mirror.
void flip_horizontal(uint8_t array[],
                     unsigned int cols,
                     unsigned int rows)
{
    unsigned int lindex;
    unsigned int rindex;
    unsigned int absRowStartIndex;
    unsigned int absLindex;
    unsigned int absRindex;
    unsigned int pivot = cols/2;

    uint8_t temp;

    for (size_t row = 0; row < rows; row++) // relative indexing
    {
        for (size_t col = 0; col < pivot; col++) // relative indexing
        {
            lindex = col;
            rindex = cols - col - 1;

            // absolute indexing:
            absRowStartIndex = row * cols;
            absLindex = absRowStartIndex + lindex;
            absRindex = absRowStartIndex + rindex;

            // value swapping:
            temp = array[absLindex];
            array[absLindex] = array[absRindex];
            array[absRindex] = temp;
        }
        
    }
    
}
/*
###
###
###
*/

// flip the image top-to-bottom.
void flip_vertical(uint8_t array[],
                   unsigned int cols,
                   unsigned int rows)
{
    unsigned int pivot = rows/2;

    unsigned int upper = 0;
    unsigned int lower = 0;

    uint8_t temp = 0;

    for (size_t offset = 0; offset < cols; offset++)
    {
        for (size_t rowNum = 0; rowNum < pivot; rowNum++)
        {
            upper = rowNum * cols + offset;
            lower = (rows - 1 - rowNum) * cols + offset;
            temp = array[upper];
            array[upper] = array[lower];
            array[lower] = temp;
        }
        
    }
    
}

/* TASK 4 */

// Find the first coordinate of the first pixel with a value that
// equals color. Search from left-to-right, top-to-bottom. If it is
// found, store the coordinates in *x and *y and return 1. If it is
// not found, return 0.
int locate_color(const uint8_t array[],
                 unsigned int cols,
                 unsigned int rows,
                 uint8_t color,
                 unsigned int *x,
                 unsigned int *y)
{
    unsigned int row, col, found = 0, current = 0;

    row = 0;
    while (found != 1 && row < rows)
    {
        col = 0;
        while (found != 1 && col < cols)
        {
            current = row * cols + col;
            if (array[current] == color)
            {
                found = 1;
            }
            col++;
        }
        row++;
    }

    if (found == 1)
    {
        *x = col - 1;
        *y = row - 1;
        return 1;
    }
    return 0;
}

/* TASK 5 */

// Invert the image, so that black becomes white and vice versa, and
// light shades of grey become the corresponding dark shade.
void invert(uint8_t array[],
            unsigned int cols,
            unsigned int rows)
{
    for (size_t absIndex = 0; absIndex < cols * rows; absIndex++)
    {
        array[absIndex] = 255 - array[absIndex];
    }
    
}

/* TASK 6 */

// Multiply every pixel by scale_factor, in order to brighten or
// darken the image. Resulting values are rounded to the nearest
// integer (0.5 rounded up) and any resulting value over 255 is
// thresholded to 255.
void scale_brightness(uint8_t array[],
                      unsigned int cols,
                      unsigned int rows,
                      double scale_factor)
{
    unsigned int scaled_color;
    for (size_t i = 0; i < cols * rows; i++)
    {
        scaled_color = round(array[i] * scale_factor);
        if (scaled_color > 255)
        {
            scaled_color = 255;
        }
        array[i] = (uint8_t) scaled_color;
    }
    
}

/* TASK 7 */

// Normalize the dynamic range of the image, i.e. Shift and scale the
// pixel colors so that that darkest pixel is 0 and the lightest pixel
// is 255. Hint: you already wrote min() and max().
void normalize(uint8_t array[],
               unsigned int cols,
               unsigned int rows)
{
    uint8_t minColor = min(array, cols, rows);
    unsigned int len = cols * rows;
    
    for (size_t i = 0; i < len; i++)
    {
        array[i] -= minColor;
    }
    
    uint8_t maxColor = max(array, cols, rows);

    for (size_t i = 0; i < len; i++)
    {
        array[i] = array[i] * (255 / (double) maxColor) + 1;
    }
    maxColor = max(array, cols, rows);
}

/* TASK 8 */

// Return a new image of size rows/2 by cols/2 If the original image
// has an odd number of columns, ignore its rightmost column. If the
// original image has an odd number of rows, ignore its bottom row.
// The value of a pixel at (p,q) in the new image is the average of
// the four pixels at (2p,2q), (2p+1,2q), (2p+1,2q+1), (2p,2q+1) in
// the original image.
uint8_t *half(const uint8_t array[],
              unsigned int cols,
              unsigned int rows)
{
    // make image even (ignore bottom edge & right edge):
    if (cols % 2 != 0)
        cols--;

    if (rows % 2 != 0)
        rows--;

    // compute new img size to allocate memory
    unsigned int half_cols = cols / 2;
    unsigned int half_rows = rows / 2;

    uint8_t* new_img = malloc(half_cols * half_rows * sizeof(uint8_t));

    // compute new img
    unsigned int offset = 2;
    unsigned int pixel_sum = 0;

    uint8_t avg_color = 0;

    for (size_t col = 0; col < cols; col += offset)
    {
        for (size_t row = 0; row < rows; row += offset)
        {
            // sum pixel values and compute average
            pixel_sum = get_pixel(array, cols, rows, col, row);
            pixel_sum += get_pixel(array, cols, rows, col + 1, row);
            pixel_sum += get_pixel(array, cols, rows, col, row + 1);
            pixel_sum += get_pixel(array, cols, rows, col + 1, row + 1);
            avg_color = pixel_sum / (offset * offset);
            set_pixel(new_img, half_cols, half_rows, col/2, row/2, avg_color + 1);
        }
        
    }
    return new_img;
}

/*-------------------------------------------------
  PART 2: OPERATIONS ON IMAGE SUB-REGIONS

  These functions operate only on a rectangular region of the array
  defined by a (left,top) corner (i.e. closer to the image origin) and
  (right,bottom) corner (i.e. further from the image origin).

  The rectangle edges of a rectangular region are aligned with the x,y axes. 
  
  The region includes all the columns from [left, right-1] inclusive,
  and all the rows from [top, bottom-1] inclusive.
  
  In every case, you may assume that left <= right and top <= bottom:
  do not need to test for this.

  The area of the region is right-left * bottom-top pixels, which
  implies that if left == right or top == bottom, the region has no
  area and is defined as "empty". Each function notes how to handle
  empty regions.
 
  In every function, you can use assert() to test bounds on the region
  corners.
*/

/* TASK 9 */

// Set every pixel in the region to color. If the region is empty, the
// image must remained unchanged.
void region_set(uint8_t array[],
                unsigned int cols,
                unsigned int rows,
                unsigned int left,
                unsigned int top,
                unsigned int right,
                unsigned int bottom,
                uint8_t color)
{
    unsigned int right_limit, bottom_limit;
    right_limit = (right < cols) ? right : cols;
    bottom_limit = (bottom < rows) ? bottom : rows;
    for (size_t y = top; y < bottom_limit; y++)
    {
        for (size_t x = left; x < right_limit; x++)
        {
            set_pixel(array, cols, rows, x, y, color);
        }
        
    }
    
}

/* TASK 10 */

// Return the sum of all the pixels in the region. Notice the large
// return type to handle potentially large numbers. Empty regions
// return the sum 0.
unsigned long int region_integrate(const uint8_t array[],
                                   unsigned int cols,
                                   unsigned int rows,
                                   unsigned int left,
                                   unsigned int top,
                                   unsigned int right,
                                   unsigned int bottom)
{
    unsigned int left_limit, right_limit, top_limit, bottom_limit;
    right_limit = (right < cols) ? right : cols;
    bottom_limit = (bottom < rows) ? bottom : rows;

    unsigned int sum = 0;

    for (size_t y = top; y < bottom_limit; y++)
    {
        for (size_t x = left; x < right_limit; x++)
        {
            sum += get_pixel(array, cols, rows, x, y);
        }
        
    }
    return sum;
}

/* TASK 11 */

// Get a new image which is a copy of the region. Empty regions return
// a null pointer. If memory allocation fails, return a null
// pointer. The caller is responsible for freeing the returned array
// later.
uint8_t *region_copy(const uint8_t array[],
                     unsigned int cols,
                     unsigned int rows,
                     unsigned int left,
                     unsigned int top,
                     unsigned int right,
                     unsigned int bottom)
{
    // your code here
    return NULL;
}
