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
    element_t *el_a = list_a->head, *el_b = list_b->head;
    
    while (el_a != NULL && el_b != NULL)
    {
        if (el_a->val < el_b->val)
        {
            if (list_append(result, el_a->val) == 1) puts("it no work");
            el_a = el_a->next;
        }
        else
        {
            if (list_append(result, el_b->val) == 1) puts("it no work");
            el_b = el_b->next;
        }
        
    }

    while (el_a != NULL)
    {
        if (list_append(result, el_a->val) == 1) puts("it no work");
        el_a = el_a->next;
    }
    
    while (el_b != NULL)
    {
        if (list_append(result, el_b->val) == 1) puts("it no work");
        el_b = el_b->next;
    }

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
            if (list_append(list_a, list_index(list, i)->val) != 0) puts("it no work");
        }
        else
        {
            if (list_append(list_b, list_index(list, i)->val) != 0) puts("it no work");
        }
        
    }

    list_sort(list_a);
    list_sort(list_b);

    list_t* result = list_merge(list_a, list_b);
    
    list_destroy(list);
    list = list_create();

    list->head = result->head;
    list->tail = result->tail;
}

int main()
{
    list_t *list = list_create();
    int len = 7;
    for (int i = 0; i < len; i++)
    {
        list_append(list, rand() % 1000);
    }
    puts("testing...");
    list_sort(list);

    for (int i = 0; i < len - 1; i++)
    {
        printf("CHECKING INDEX: %d\n", i);
        if (list_index(list, i)->val > list_index(list, i + 1)->val)
        {
            printf("Failed check at index: %d\n", i);
        }
        
    }

    list_print(list);
    
    return 0;
}
