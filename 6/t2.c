
/* LAB 6 TASK 2 */

/*
  Save the entire array ia into a file called 'filename' in a JSON
  text file array file format that can be loaded by
  intarr_load_json(). Returns zero on success, or a non-zero error
  code on failure. Arrays of length 0 should produce an output file
  containing an empty array.

  Make sure you validate the parameters before you use them.
  
  The JSON output should be human-readable.

  Examples:

  The following line is a valid JSON array:
  [ 100, 200, 300 ]
  
  The following lines are a valid JSON array:
  [ 
   100, 
   200, 
   300 
  ]
*/
#include <stdio.h>
#include <stdlib.h>
#include "intarr.h"

int intarr_save_json( intarr_t* ia, const char* filename )
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

    fprintf(f, "[\n");
    if (ia->len > 0)
    {
        for (unsigned int i = 0; i < ia->len - 1; i++)
        {
            fprintf(f, "%d,\n", ia->data[i]);

        }
        fprintf(f, "%d\n]\n", ia->data[ia->len - 1]);
    }
    else
    {
        fprintf(f, "]\n");
    }
    
    fclose(f);
    return 0;
}


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
    
    int temp = 0;
    unsigned int count = 0;
    intarr_t *intar = intarr_create(0);
    if (intar == NULL)
    {
        printf("ERROR: failed intarr_create");
        return NULL;
    }

    fscanf(f, "[\n");
    while (fscanf(f, "%d,\n", &temp) == 1)
    {
        ++count;
        if (intarr_resize(intar, count) != INTARR_OK)
        {
            printf("ERROR: intarr_resize non-zero.\n");
            return NULL;
        }
        intar->data[count-1] = temp;
    }
    
    fclose(f);
    return intar;
}