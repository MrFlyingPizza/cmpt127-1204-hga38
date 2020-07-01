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
#include "intarr.h"

int intarr_save_binary( intarr_t* ia, const char* filename )
{
    if (filename == NULL)
    {
        return 1;
    }

    FILE *f = fopen(filename, "w");
    if (f == NULL)
    {
        return 2;
    }

    if (ia == NULL)
    {
        return 3;
    }
    
    if (fwrite(&ia->len, sizeof(unsigned int), 1, f) != 1)
    {
        return 4;
    }
    
    if (fwrite(ia->data, sizeof(int), ia->len, f) != ia->len)
    {
        return 5;
    }

    fclose(f);

    return 0;
}

/*
  Load a new array from the file called 'filename', that was
  previously saved using intarr_save_binary(). Returns a pointer to a
  newly-allocated intarr_t on success, or NULL on failure.

  Make sure you validate the parameter before you use it.
*/
intarr_t* intarr_load_binary( const char* filename )
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

    if (fread(&len, sizeof(unsigned int), 1, f) != 1)
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
    
    
    if (fread(intar->data, sizeof(int), len, f) != len)
    {
        printf("ERROR: failed read data, len: %u.\n", intar->len);
        return NULL;
    }

    fclose(f);

    return intar;
}

