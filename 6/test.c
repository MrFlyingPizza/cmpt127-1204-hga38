#include <stdio.h>
#include "intarr.h"

int t1()
{
    intarr_t* intar = intarr_create(5);
    char* filename = "test_save";

    for (unsigned int i = 0; i < intar->len; i++)
    {
        intar->data[i] = i*i;
        printf("data set in intar at %u : %d\n", i, intar->data[i]);
    }
    
    printf("Save code: %d\n", intarr_save_binary(intar, filename));
    intarr_t *read = intarr_load_binary(filename);

    printf("%p\n", read);
    printf("data read in intar len: %u\n", read->len);
    for (unsigned int i = 0; i < read->len; i++)
    {
        printf("data read in intar at %u : %d\n", i, read->data[i]);
    }
    
    return 0;
}

int main(int argc, char const *argv[])
{
    (t1() == 0) ? printf("t1 success\n"): printf("t1 failed\n");
    return 0;
}
