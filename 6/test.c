#include <stdio.h>
#include "intarr.h"

intarr_t * generate_intarr(unsigned int len)
{
    intarr_t* intar = intarr_create(len);

    for (unsigned int i = 0; i < intar->len; i++)
    {
        intar->data[i] = i*i;
        printf("data set in intar at %u : %d\n", i, intar->data[i]);
    }
    return intar;
}

void read_intar(intarr_t* intar)
{
    printf("data read in intar len: %u\n", intar->len);
    for (unsigned int i = 0; i < intar->len; i++)
    {
        printf("data read in intar at %u : %d\n", i, intar->data[i]);
    }
}

int t1()
{
    intarr_t *intar = generate_intarr(10);

    char* filename = "test_save";
    
    printf("Save code: %d\n", intarr_save_binary(intar, filename));
    intarr_t *read = intarr_load_binary(filename);

    printf("%p\n", read);

    read_intar(read);
    
    return 0;
}

int t2()
{
    intarr_t *intar = generate_intarr(10);

    char* filename = "test_save_json.json";

    printf("Save code: %d\n", intarr_save_json(intar, filename));

    intarr_t *read = intarr_load_json(filename);
    printf("%p\n", read);
    read_intar(read);

    return 0;
}

int main(int argc, char const *argv[])
{
    (t1() == 0) ? printf("t1 success\n"): printf("t1 failed\n");
    (t2() == 0) ? printf("t2 success\n"): printf("t2 failed\n");
    return 0;
}
