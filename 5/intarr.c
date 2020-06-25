/* 
 * intarr.h
 *
 * Provides a bounds-checked, resizable array of integers with
 * random-access and stack interfaces, and several utility functions
 * that operate on them.
 * 
 */

/* DO NOT CHANGE THIS FILE - YOUR CODE WILL BE COMPILED AGAINST THE
   ORIGINAL. NON-COMPILING CODE WILL FAIL ALL THE TASKS!

   FOR TASKS WITH MORE THAN ONE FUNCTION, YOU MUST IMPLEMENT ALL
   FUNCTIONS TO PASS THE TASK.
*/
#include <stdio.h>
#include <stdlib.h>
/* Structure type that encapsulates our safe int array. */
typedef struct {
  int* data;
  unsigned int len;
} intarr_t;

/* A type for returning status codes */
typedef enum {
  INTARR_OK,
  INTARR_BADARRAY,
  INTARR_BADINDEX,
  INTARR_BADALLOC,
  INTARR_NOTFOUND
} intarr_result_t;

/* LAB 5 TASK 1 */

// Create a new intarr_t with initial size len.  If successful
// (i.e. memory allocation succeeds), returns a pointer to a
// newly-allocated intarr_t.  If unsuccessful, returns a null pointer.
intarr_t* intarr_create( unsigned int len )
{
    intarr_t *new_intarr = malloc(sizeof(intarr_t));
    if (new_intarr == NULL)
        return NULL;

    (*new_intarr).len = len;
    (*new_intarr).data = malloc(len * sizeof(int));
    return new_intarr;
}

// Frees all memory allocated for ia. If the pointer is null, do
// nothing. If the ia->data is null, do not attempt to free it.
void intarr_destroy( intarr_t* ia )
{
    if (ia != NULL)
    {
        // free data if exist
        if ((*ia).data != NULL)
        {
            free(ia);
        }

    }

}

/* LAB 5 TASK 2 */

// If index is valid, set the value at ia->data[index] to val and return
// INTARR_OK. Otherwise, leave the array unmodified and return
// INTARR_BADINDEX. If ia is null, return INTARR_BADARRAY.
intarr_result_t intarr_set( intarr_t* ia, 
							unsigned int index, 
							int val )
{
    if (ia == NULL)
    {
        return INTARR_BADARRAY;
    }
    
    if (index >= (*ia).len)
    {
        return INTARR_BADINDEX;
    }
    
    (*ia).data[index] = val;
    return INTARR_OK;
}

// If index is valid and val is non-null, set *val to ia->data[index] and return
// INTARR_OK. Otherwise do not modify *val and return
// INTARR_BADINDEX. If ia is null, return INTARR_BADARRAY.
intarr_result_t intarr_get( const intarr_t* ia, 
							unsigned int index, 
							int* val )
{
    if (ia == NULL)
    {
        return INTARR_BADARRAY;
    }

    if (index >= ((*ia).len))
    {
        return INTARR_BADINDEX;
    }
    
    *val = (*ia).data[index];

    return INTARR_OK;
}
/* LAB 5 TASK 3 */

// Return a duplicate of ia, allocating new storage for the duplicate
// data (we call this a "deep copy"). If unsuccessful (i.e. memory
// allocation for the copy fails, or ia is null), return a null pointer. 
intarr_t* intarr_copy( const intarr_t* ia )
{

    intarr_t *new_intarr = intarr_create((*ia).len);
    if (new_intarr == NULL)
    {
        return NULL;
    }
    
    for (size_t i = 0; i < (*new_intarr).len; i++)
    {
        (*new_intarr).data[i] = (*ia).data[i];
    }
    
    return new_intarr;
}
/* LAB 5 TASK 4 */

// Sort ia by value smallest-to-largest, so that data[i] < data[i+1]
// for all valid i, then return INTARR_OK. Works in-place: contents of
// ia are sorted on return. If ia is null, return INTARR_BADARRAY.
int compare_ints(const void *p, const void *q)
{
    return (q > p);
}

intarr_result_t intarr_sort( intarr_t* ia )
{
    if (ia == NULL)
    {
        return INTARR_BADARRAY;
    }
    
    qsort((*ia).data, (*ia).len, sizeof((*ia).data[0]), compare_ints);
    
    return INTARR_OK;
}

/* LAB 5 TASK 5 */

// Find the first occurrence of the target in the array, searching from
// index 0. If the target is found and i is non-null, set *i to the
// location index and return INTARR_OK. If target does not occur in
// the array, leave *i unmodified and return INTARR_NOTFOUND. If ia is
// null, return INTARR_BADARRAY.
intarr_result_t intarr_find( intarr_t* ia, int target, int* i )
{
    if (ia == NULL)
    {
        return INTARR_BADARRAY;
    }

    for (size_t index = 0; index < (*ia).len; index++)
    {
        if ((*ia).data[index] == target)
        {
            if (i != NULL)
            {
                *i = index;
            }
            
            return INTARR_OK;
        }
        
    }
    
    return INTARR_NOTFOUND;
}

/* LAB 5 TASK 6 */

// HINT: First, do TASK 7, since you will need to resize your array
//       by +1 in order to successfully push val.
// Append val to the end of ia (allocating space for it). If
// successful, return INTARR_OK, otherwise return
// INTARR_BADALLOC. If ia is null, return INTARR_BADARRAY.
intarr_result_t intarr_push( intarr_t* ia, int val )
{
    return INTARR_OK;
}

// HINT: You will need to decrement len so that it always represents
//       the number of int's stored in the array data.
// If the array is not empty, remove the value with the highest index
// from the array, and, if i is non-null, set *i to the removed value,
// then return INTARR_OK. If the array is empty, leave *i unmodified
// and return INTARR_BADINDEX. If ia is null, return INTARR_BADARRAY.
intarr_result_t intarr_pop( intarr_t* ia, int* i )
{
    return INTARR_OK;
}

/* LAB 5 TASK 7 */

// HINT: Do this task before doing TASK 6.
// Resize ia to contain newlen values. If newlen is less than the
// original array length, the end of the array is discarded. 
// If newlen is greater than the original array length, the values 
// of the new integers will be undefined 
// (see https://en.cppreference.com/w/c/memory/realloc). 
// If the allocation is successful, return INTARR_OK, otherwise 
// return INTARR_BADALLOC. If ia is null, return INTARR_BADARRAY.
intarr_result_t intarr_resize( intarr_t* ia, unsigned int newlen )
{
    if (ia == NULL)
    {
        return INTARR_BADARRAY;
    }

    int *new_alloc = realloc((*ia).data, newlen * sizeof((*ia).data[0]));
    if (new_alloc == NULL)
    {
        return INTARR_BADALLOC;
    }
    else
    {
        (*ia).data = new_alloc;
    }
    return INTARR_OK;
}
/* LAB 5 TASK 8 */

// Get a deep copy of a portion of ia from index 'first' to index 'last'
// inclusive. If successful, return a pointer to a newly-allocated
// intarr_t containing a copy of the specified section. If an error
// occurs, i.e. ia is null, 'first' or 'last' are out of bounds, 
// 'last' < 'first', or memory allocation fails, return a null pointer.
intarr_t* intarr_copy_subarray( intarr_t* ia, 
								unsigned int first, 
								unsigned int last )
{
    if (ia == NULL)
    {
        return NULL;
    }

    if (last >= (*ia).len)
    {
        return NULL;
    }
    return NULL;
}