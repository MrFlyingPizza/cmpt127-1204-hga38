#include "list.h"
#include <stdlib.h>
#include <stdio.h>

element_t* merge_sorted(element_t* a, element_t* b)
{
    element_t* result = NULL;

    if (a == NULL)
    {
        return b;
    }
    else if (b == NULL)
    {
        return a;
    }
    
    if (a->val <= b->val)
    {
        result = a;
        result->next = merge_sorted(a->next, b);
    }
    else
    {
        result = b;
        result->next = merge_sorted(a, b->next);
    }
    return result;
}

void list_split(element_t* head, element_t** a, element_t** b)
{
    element_t *fast, *slow;
    slow = head;
    fast = head->next;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
        
    }
    
    *a = head;
    *b = slow->next;
    slow->next = NULL;
}

void _list_sort(element_t** headRef)
{
    element_t* head = *headRef, *a, *b;

    if (head == NULL || head->next == NULL)
    {
        return;
    }
    
    list_split(head, &a, &b);

    _list_sort(&a);
    _list_sort(&b);

    *headRef = merge_sorted(a, b);
}

void list_sort(list_t* list)
{
    _list_sort(&(list->head));
    element_t* el = list->head;
    while (el->next != NULL)
    {
        el = el->next;
    }
    list->tail = el;
}

// int main()
// {
//     list_t *list = list_create();
//     int len = 100000;
//     for (int i = 0; i < len; i++)
//     {
//         list_append(list, rand() % 1000);
//     }
//     puts("testing...");
//     list_sort(list);

//     for (int i = 0; i < len - 1; i++)
//     {
//         printf("CHECKING INDEX: %d\n", i);
//         if (list_index(list, i)->val > list_index(list, i + 1)->val)
//         {
//             printf("Failed check at index: %d\n", i);
//         }
        
//     }

//     list_print(list);
    
//     return 0;
// }
