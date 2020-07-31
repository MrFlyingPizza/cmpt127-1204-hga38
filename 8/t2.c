#include <stdlib.h>
#include "point_array.h"
#include <assert.h>

// Safely initalize an empty array structure.
void point_array_init( point_array_t* pa )
{
    assert(pa);
    point_array_t* new_pa = malloc(sizeof(point_array_t));
    if (new_pa)
    {
        new_pa->points = malloc(10*sizeof(point_t));
        if (new_pa->points)
        {
            new_pa->len = 0;
            new_pa->reserved = 10;
            pa = new_pa;
        }
        else
        {
            free(new_pa->points);
            free(new_pa);
        }

    }

}

// Resets the array to be empty, freeing any memory allocated if necessary.
void point_array_reset( point_array_t* pa )
{
    assert(pa);
    point_t* new_pts = malloc(10 * sizeof(point_t));
    if (new_pts)
    {
        free(pa->points);
        pa->points = new_pts;
        pa->reserved = 10;
        pa->len = 0;

    }
    
}

// Append a point to the end of an array. If successful, return 0, else return 1.
int point_array_append( point_array_t* pa, point_t* p )
{
    assert(pa);
    assert(p);
    point_t* pts = NULL;
    if (pa->len == pa->reserved)
    {
        pts = realloc(pa->points, pa->reserved * 2);
    }

    if (pts)
    {
        pa->points = pts;
        pa->points[pa->len] = *p;
        pa->reserved *= 2;
        pa->len += 1;
    }
    else
    {
        return 1;
    }
    return 0;
}

// Remove the point at index i from the array, reducing the number of elements
// stored in the array by one. The order of points in the array may change.
// If successful, return 0, else return 1. 
int point_array_remove( point_array_t* pa, unsigned int i )
{
    assert(pa);
    if (i >= pa->len) return 1;
    if (pa->len < 1) return 1;

    point_t* pts = NULL;
    if (pa->len - 1 <= pa->reserved / 2 && pa->reserved/2 >= 10)
    {
        pts = realloc(pa->points, pa->reserved/2);
    }

    if (pts)
    {
        pa->points = pts;
    }
    else
    {
        return 1;
    }
    
    for (unsigned int index = i; index < pa->len - 1; index++)
    {
        pa->points[index] = pa->points[index + 1];
    }

    pa->len -= 1;
    pa->reserved /= 2;
    
    return 0;
}


