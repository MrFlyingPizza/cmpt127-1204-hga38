#include "list.h"
#include <stdlib.h>
#include <stdio.h>

void append(list_t* list, element_t* el)
{
    
}

void merging(element_t* left_l, element_t* left_r, element_t* right_l, element_t* right_r)
{
    int temp_val = 0;
    element_t *temp_el_1 = NULL, *temp_el_2 = NULL;
    while (left_l != left_r->next && right_l != right_r->next)
    {
        if (left_l->val < right_l->val)
        {
            left_l = left_l->next;
        }
        else
        {
            temp_val = left_l->val;
            left_l->val = right_l->val;
            right_l->val = temp_val;

            temp_el_1 = left_l->next;
            left_l->next = right_l;

            temp_el_2 = right_l->next;
            right_l->next = temp_el_1;

            temp_el_1->next = temp_el_2;

            right_l = temp_el_2;
        }
        
        
    }
    
}

void sorting(element_t* left, element_t* right)
{
    element_t *moving_left = left, *moving_right = right;
    while (moving_right != right)
    {
        moving_right = moving_right->next;
        if (moving_right != right)
        {
            moving_left = moving_left->next;
            moving_right = moving_right->next;
        }

    }

    sorting(left, moving_left);
    sorting(moving_left->next, right);

    //merging(moving_left->next, right);
}

void list_sort(list_t* list)
{
    unsigned int size = list_size(list);
    printf("size: %u\n", size);
}

int main()
{
    list_t *list = list_create();
    int len = 100000;
    for (int i = 0; i < len; i++)
    {
        list_append(list, rand());
    }
    puts("testing...");
    list_sort(list);
    //list_print(list);

    for (int i = 0; i < len - 1; i++)
    {
        if (list_index(list, i) > list_index(list, i + 1))
        {
            printf("Failed check at index: %d", i);
        }
        
    }
    
    return 0;
}
