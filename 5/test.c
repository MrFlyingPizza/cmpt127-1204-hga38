#include <stdio.h>
#include <stdlib.h>
#include "intarr.h"
#include <limits.h>

void test1()
{
    printf("- - - - test 1\n");
    intarr_t* intarr_ptr = intarr_create(100384);
    (*intarr_ptr).data[10] = 299;
    printf("data at 10: %d | len: %u\n", (*intarr_ptr).data[10], (*intarr_ptr).len);
    intarr_destroy(intarr_ptr);
    printf("ran destroy\n");

    intarr_t* p = intarr_create(INT_MAX);
    if (p != NULL)
    {
        printf("Not NULL p\n");
    }
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
    int success = intarr_get(intarr_ptr, 10, &val);
    printf("val gotten at 10: %d | success: %d\n", val, success);

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

void test5()
{
    printf("- - - - test 5\n");
    intarr_t* intarr = intarr_create(5);
    int index;
    printf("set val at 3 to 9\n");
    intarr->data[3] = 9;
    for (unsigned int i = 0; i < 5; i++)
    {
        printf("%d\n", intarr->data[i]);
    }
    
    puts("running intarr_find");
    intarr_result_t result = intarr_find(intarr, 9, &index);
    puts("finished intarr_find");
    printf("expected val: %d | result val: %d | success: %d\n", 3, index, result);
}

void test6()
{
    printf("- - - - test 6\n");
    intarr_t* intarr = intarr_create(2);
    int rand_num = rand() % 2000;;
    for (unsigned short i = 0; i < 2; i++)
    {
        printf("setting val at %hu to %d\n", i, rand_num);
        rand_num = rand() % 2000;
    }
    printf("appending %d to intarr\n", rand_num);
    intarr_result_t result = intarr_push(intarr, rand_num);
    printf("expected val: %d at %hu | result val: %d | result: %d\n", rand_num, 2, intarr->data[2], result);
}

void test7()
{
    printf("- - - - test 7\n");
    intarr_t* intarr_ptr = intarr_create(1);
    intarr_ptr->data[0] = 20;

    printf("resizing..\n");
    intarr_resize(intarr_ptr, 0);

    printf("len: %u | data: %d\n", intarr_ptr->len, intarr_ptr->data[0]);
}

void test8()
{
    printf("- - - - test 8\n");
    intarr_t* intarr = intarr_create(5);
    int rand_num = rand() % 2000;
    for (unsigned int i = 0; i < 5; i++)
    {
        printf("setting val %d at %u\n", rand_num, i);
        intarr->data[i] = rand_num;
        rand_num = rand() % 2000;
    }
    
    puts("cloning subarray ...");
    intarr_t* clone = intarr_copy_subarray(intarr, 1, 3);
    for (unsigned int i = 0; i < 3; i++)
    {
        printf("expect val: %d at orig index: %u | result val: %d at %u\n", intarr->data[i+1], i+1, clone->data[i], i);
    }
    
}

int main(int argc, char const *argv[])
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
}
