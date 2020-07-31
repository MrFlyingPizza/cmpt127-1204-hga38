#include <stdlib.h>
#include "point_array.h"
#include <assert.h>

// Safely initalize an empty array structure.
void point_array_init( point_array_t* pa )
{
    assert(pa);
    pa = malloc(sizeof(point_array_t));
    if (pa)
    {
        pa->len = 0;
        pa->reserved = 0;
        pa->points = NULL;
    }
    
}

// Resets the array to be empty, freeing any memory allocated if necessary.
void point_array_reset( point_array_t* pa )
{
    assert(pa);
    if (pa->points) free(pa->points);
    free(pa);
    point_array_init(pa);
}

// Append a point to the end of an array. If successful, return 0, else return 1.
int point_array_append( point_array_t* pa, point_t* p )
{
    assert(pa);
    assert(p);
    point_t* new_pts = realloc(pa->points, (pa->len + 1)*sizeof(point_t));
    if (new_pts)
    {
        pa->len += 1;
        pa->reserved += 1;
        pa->points[pa->len - 1] = *p;
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

    point_t* pts = realloc(pa->points, pa->len-1 * sizeof(point_t));
    if (pts)
    {
        for (unsigned int index = i; index < pa->len-1; index++)
        {
            pa->points[index] = pa->points[index+1];
        }
        pa->points = pts;
        pa->len -= 1;
        pa->reserved -= 1;
    }
    else
    {
        return 1;
    }
    
    return 0;
}


