#include "list.h"
#include <stdlib.h>
#include <stdio.h>

unsigned int list_size(list_t* list)
{
    element_t* el = list->head;
    unsigned int size = 0;
    while (el != NULL)
    {
        ++size;
        el = el->next;
    }
    
    return size;
}

list_t* list_merge(list_t* list_a, list_t* list_b)
{
    list_t* result = list_create();
    element_t *el_a, *el_b;
    while (el_a != NULL && el_b != NULL)
    {
        if (el_a->val < el_b->val)
        {
            list_append(result, el_a->val);
            el_a = el_a->next;
        }
        else
        {
            list_append(result, el_b->val);
            el_b = el_b->next;
        }
        
    }
    
    while (el_a != NULL)
    {
        list_append(result, el_a->val);
        el_a = el_a->next;
    }
    
    while (el_b != NULL)
    {
        list_append(result, el_b->val);
        el_b = el_b->next;
    }

    list_destroy(list_a);
    list_destroy(list_b);

    return result;
}

void list_sort(list_t* list)
{
    if (list == NULL)
    {
        return;
    }

    if (list->head == list->tail)
    {
        return;
    }
    
    unsigned int size = list_size(list);
    unsigned int middle = size/2;
    
    list_t *list_a = list_create(), *list_b = list_create();
    for (unsigned int i = 0; i < size; i++)
    {
        if (i < middle)
        {
            list_append(list_a, list_index(list, i)->val);
        }
        else
        {
            list_append(list_b, list_index(list, i)->val);
        }
        
    }

    list_sort(list_a);
    list_sort(list_b);

    list_t* result = list_merge(list_a, list_b);
    
    list = result;
}

// int main()
// {
//     list_t *list = list_create();
//     int len = 10;
//     for (int i = 0; i < len; i++)
//     {
//         list_append(list, rand());
//     }
//     puts("testing...");
//     list_sort(list);
//     //list_print(list);

//     for (int i = 0; i < len - 1; i++)
//     {
//         if (list_index(list, i) > list_index(list, i + 1))
//         {
//             printf("Failed check at index: %d", i);
//         }
        
//     }
    
//     return 0;
// }
