#include "list.h"
#include <stdlib.h>
#include <stdio.h>

// returns list size
int list_size(list_t* list)
{
    if (list == NULL) return -1;
    if (list->head == NULL) return 0;
    
    int size = 1;
    element_t *el = list->head;
    while (el->next != NULL)
    {
        size += 1;
        el = el->next;
    }
    
    return size;
}

// void arr_print(int arr[], unsigned int len)
// {
//     printf("[ ");
//     for (unsigned int i = 0; i < len; i++)
//     {
//         printf("%d", arr[i]);
//         (i != len-1) ? printf(", ") : printf("");
//     }
//     printf(" ]\n");
// }

void merge(list_t* list, int left, int right, int mid)
{
    element_t *head_l = list_index(list, left);
    element_t *head_r = list_index(list, mid + 1);
    element_t *el_l = head_l, *el_r = head_r;

    int merge_arr[right - left + 1];

    unsigned int count_l = 0, count_r = 0, size_l, size_r;
    size_l = mid - left + 1;
    size_r = right - mid;

    int rel_i = 0; // relative indexing
    while (count_l < size_l && count_r < size_r)
    {
        if (el_l->val <= el_r->val)
        {
            merge_arr[rel_i] = el_l->val;
            el_l = el_l->next;
            count_l++;
        }
        else
        {
            merge_arr[rel_i] = el_r->val;
            el_r = el_r->next;
            count_r++;
        }
        rel_i++;
    }

    if (count_l < size_l)
    {
        for (unsigned int i = count_l; i < size_l; i++)
        {
            merge_arr[rel_i] = el_l->val;
            el_l = el_l->next;
            //if (el_l == NULL) puts("!! null reached el_l");
            rel_i++;
        }
        
    }
    else
    {
        for (unsigned int i = count_r; i < size_r; i++)
        {
            merge_arr[rel_i] = el_r->val;
            el_r = el_r->next;
            //if (el_r == NULL) printf("!! null reached el_r i=%u\n", i);
            rel_i++;
        }
        
    }
    
    element_t *el = head_l;
    for (unsigned int i = 0; i < size_l + size_r; i++)
    {
        el->val = merge_arr[i];
        el = el->next;
        //if (el == NULL) puts("!! null reached el");
    }
    //arr_print(merge_arr, right - left + 1);
}

void sort(list_t* list, int left, int right)
{
    if (left >= right) return;

    int mid = (left + right) / 2;
    sort(list, left, mid);
    sort(list, mid + 1, right);

    merge(list, left, right, mid);
    
}

void list_sort(list_t* list)
{
    if (list == NULL) return;
    if (list->head == NULL) return;
    
    unsigned int size = list_size(list);
    unsigned int highest_index = size - 1;
    sort(list, 0, highest_index);
}

// int main()
// {
//     list_t *list = list_create();
//     for (int i = 0; i < 100000; i++)
//     {
//         list_append(list, rand());
//     }
//     puts("testing...");
//     list_sort(list);
//     list_print(list);
//     return 0;
// }
