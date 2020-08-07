#include "image.hpp"
#include <exception>
#include <iostream>
#include <fstream>
#include <array>

Image::Image() : cols(0), rows(0), pixels(NULL)
{
}

Image::~Image()
{
    delete[] pixels;
}

/* Changes the size of an image, allocating memory as necessary, and
    setting all pixels to fillcolour. Returns 0 on success, or a
    non-zero error code.*/
int Image::resize(unsigned int width, unsigned int height, uint8_t fillcolour)
{
    try
    {
        delete[] pixels;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }

    try
    {
        pixels = new uint8_t[width*height*sizeof(uint8_t)];
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 2;
    }
    
    this->cols = width;
    this->rows = height;

    return 0;
}

/* Sets the colour of the pixel at (x,y) to colour. Returns 0 on
    success, else a non-zero error code. If (x,y) is not a valid
    pixel, the call fails and the image does not change.*/
int Image::set_pixel(unsigned int x, unsigned int y, uint8_t colour)
{
    if (x >= cols || y >= rows)
    {
        std::cerr << "Pixel target out of bounds.\n";
        return 1;
    }
    
    try
    {
        pixels[y * cols + x] = colour;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 2;
    }
    return 0;
}

/* Gets the colour of the pixel at (x,y) and stores at the address
    pointed to by colourp. Returns 0 on success, else a non-zero error
    code. */
int Image::get_pixel(unsigned int x, unsigned int y, uint8_t *colourp)
{
    if (x >= cols || y >= rows)
    {
        std::cerr << "Pixel target out of bounds.\n";
        return 1;
    }

    try
    {
        *colourp = pixels[y * cols + x];
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 2;
    }
    return 0;
}