/* -------------------------------------------------------------- */

/* LAB 6 TASK 1 */

/*
  Save the entire array ia into a file called 'filename' in a binary
  file format that can be loaded by intarr_load_binary(). Returns
  zero on success, or a non-zero error code on failure. Arrays of
  length 0 should produce an output file containing an empty array.

  Make sure you validate the parameters before you use them.
*/
#include <stdio.h>
#include <stdlib.h>
#include "intarr.c"

/*
  Load a new array from the file called 'filename', that was
  previously saved using intarr_save_json(). The file may contain an array
  of length 0. Returns a pointer to a newly-allocated intarr_t on
  success (even if that array has length 0), or NULL on failure.

  Make sure you validate the parameter before you use it.
*/
intarr_t* intarr_load_json( const char* filename )
{
    if (filename == NULL)
    {
        printf("ERROR: null filename.\n");
        return NULL;
    }
    
    FILE* f = fopen(filename, "r");

    if (f == NULL)
    {
        printf("ERROR: failed open file.\n");
        return NULL;
    }
    
    unsigned int len = 0;
    if (fscanf(f, "[\n%u,", &len) != 1)
    {
        printf("ERROR: failed read length.\n");
        return NULL;
    }

    intarr_t *intar = intarr_create(len);
    if (intar == NULL)
    {
        printf("ERROR: failed intarr_create.\n");
        return NULL;
    }
    
    for (unsigned int i = 0; i < intar->len; i++)
    {
        if (fscanf(f, "%d,\n", &(intar->data[i])) != 1)
        {
            printf("ERROR: failed read data, i: %u.\n", intar->len);
            return NULL;
        }
        
    }
    
    return intar;
}