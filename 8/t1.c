#include <stdlib.h>
#include "point_array.h"
#include <assert.h>
#include <stdio.h>

// Safely initalize an empty array structure.
void point_array_init( point_array_t* pa )
{
    assert(pa);
    pa->len = 0;
    pa->reserved = 0;
    pa->points = NULL;
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
    point_t* pts = NULL;
    if (pa->len == pa->reserved)
    {
        pts = realloc(pa->points, (pa->len+1) * sizeof(point_t));
        if (pts == NULL) return 1;
        pa->reserved += 1;
    }
    
    pa->points = pts;
    pa->points[pa->len] = *p;
    pa->len += 1;

    return 0;
}

// Remove the point at index i from the array, reducing the number of elements
// stored in the array by one. The order of points in the array may change.
// If successful, return 0, else return 1. 
int point_array_remove( point_array_t* pa, unsigned int i )
{
    point_t to_remove = pa->points[pa->len-1];
    pa->points[pa->len-1] = pa->points[i];
    pa->points[pa->len-1] = to_remove;
    pa->len -= 1;
}


