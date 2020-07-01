#include <stdio.h>
#include "intarr.h"

void test1()
{
    printf("- - - - test 1\n");
    intarr_t* intarr_ptr = intarr_create(100384);
    (*intarr_ptr).data[10] = 299;
    printf("data at 10: %d | len: %u\n", (*intarr_ptr).data[10], (*intarr_ptr).len);
    intarr_destroy(intarr_ptr);
    printf("ran destroy\n");
}

void test2()
{
    printf("- - - - test 2\n");
    intarr_t* intarr_ptr = intarr_create(100384);

    printf("set val: 121 at 10\n");
    intarr_set(intarr_ptr, 10, 121);
    printf("data at 10: %d | len: %u\n", (*intarr_ptr).data[10], (*intarr_ptr).len);

    intarr_destroy(intarr_ptr);
    printf("ran destroy\n");
}

void test3()
{
    printf("- - - - test 3\n");
    intarr_t* intarr_ptr = intarr_create(100384);

    printf("set val: 121 at 10\n");
    intarr_set(intarr_ptr, 10, 121);
    printf("data at 10: %d | len: %u\n", (*intarr_ptr).data[10], (*intarr_ptr).len);

    printf("running get val at 10\n");
    int val;
    int ok = intarr_get(intarr_ptr, 10, &val);
    printf("val gotten at 10: %d | ok: %d\n", val, ok);

    intarr_destroy(intarr_ptr);
    printf("ran destroy\n");
}

void test4()
{
    printf("- - - - test 4\n");
    intarr_t* intarr_ptr = intarr_create(3);

    printf("set val: 121 at 0\n");
    intarr_set(intarr_ptr, 0, 121);
    printf("data at 0: %d | len: %u\n", (*intarr_ptr).data[0], (*intarr_ptr).len);

    printf("set val: 12 at 1\n");
    intarr_set(intarr_ptr, 1, 12);
    printf("data at 1: %d | len: %u\n", (*intarr_ptr).data[1], (*intarr_ptr).len);

    printf("set val: 121 at 2\n");
    intarr_set(intarr_ptr, 2, 1);
    printf("data at 2: %d | len: %u\n", (*intarr_ptr).data[2], (*intarr_ptr).len);

    printf("sorting\n");
    intarr_sort(intarr_ptr);
    for (size_t i = 0; i < 3; i++)
    {
        printf("val at %ld: %d\n", i, (*intarr_ptr).data[i]);
    }
    

    intarr_destroy(intarr_ptr);
    printf("ran destroy\n");
}

void test7()
{
    printf("- - - - test 7\n");
    intarr_t* intarr_ptr = intarr_create(1);
    intarr_ptr->data[0] = 20;

    printf("resizing..\n");
    intarr_resize(intarr_ptr, 0);

    printf("len: %u | data: %d", intarr_ptr->len, intarr_ptr->data[0]);
}

int main(int argc, char const *argv[])
{
    test1();
    test2();
    test3();
    test4();
    test7();
}
