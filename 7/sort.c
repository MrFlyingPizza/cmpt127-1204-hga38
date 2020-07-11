#include "list.h"
#include <stdlib.h>
#include <stdio.h>

void list_sort(list_t* list)
{
    element_t *el = list->head;
    unsigned short sorted = 0;
    while (sorted == 0)
    {
        sorted = 1;
        el = list->head;
        while (el->next)
        {
            //printf("%d %d\n", el->val, el->next->val);
            if (el->next->val < el->val)
            {
                int temp = el->next->val;
                el->next->val = el->val;
                el->val = temp;
                sorted = 0;
            }
            //printf("# %d %d\n", el->val, el->next->val);
            el = el->next;
        }
        list_print(list);
    }
    
}

// int main()
// {
//     list_t *list = list_create();
//     for (int i = 0; i < 5; i++)
//     {
//         list_append(list, rand()%1000);
//     }
//     list_print(list);
//     list_sort(list);
//     return 0;
// }
