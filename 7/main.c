#include <stdio.h>
#include <stdlib.h>

#include "list.h"
#include "limits.h"

int main( int argc, char* argv[] )
{
  // test the create function
  list_t* list = list_create();

  // check to see if the create function did everything it was supposed to
  if( list == NULL )
    {
      printf( "create: create failed to malloc\n" );
      return 1;
    }

  if( list->head != NULL )
    {
      printf( "create: head is not null!\n" );
      return 1;
    }

  if( list->tail != NULL )
    {
      printf( "create: tail is not null!\n" );
      return 1;
    }

  // now test all the other functions (except list_print) to see if
  // they do what they are supposed to

  // you code goes here
  int test_vals[4] = {0, 0, INT_MAX, INT_MIN};

  printf("testing destroy, ptr check\n");
  list_destroy(list);
  element_t *test_ptr = list_index(list, 0);
  printf("%p\n", test_ptr);
  if (test_ptr != NULL)
  {
    return 1;
  }

  printf("tesing create element, null return check\n");
  element_t* test_element = element_create(INT_MAX);
  if (test_element == NULL) {
    return 1;
  }

  printf("testing create element, int max store check.\n");
  if (test_element->val != INT_MAX)
  {
    return 1;
  }
  
  printf("testing create element, null next check\n");
  if (test_element->next != NULL)
  {
    return 1;
  }
  free(test_element);

  printf("Creating test list\n");
  list_t *test_list = list_create();
  
  int append_success = list_append(test_list, INT_MAX);
  printf("testing list appended, append success check\n");
  if (append_success == 1)
  {
    printf("append failed, expected success!\n");
    return 1;
  }

  printf("testing list appended, tail check\n");
  if (test_list->tail->next != NULL) {
    printf("failed to set");
    return 1;
  }

  printf("testing list appended, head check\n");
  if (test_list->head == NULL)
  {
    return 1;
  }
  
  printf("testing  list appended, head val check\n");
  if (test_list->head->val != INT_MAX)
  {
    return 1;
  }
  
  printf("testing list appended, head next val check\n");
  append_success = list_append(test_list, INT_MIN);
  if (test_list->head->next->val != INT_MIN)
  {
    return 1;
  }
  
  printf("testing list appended, tail val check\n");
  if (test_list->tail->val != INT_MIN)
  {
    return 1;
  }
  
  printf("testing list append, tail next null check\n");
  if (test_list->tail->next != NULL)
  {
    return 1;
  }
  
  int some_val = rand();
  test_vals[1] = some_val;
  list_prepend(test_list, some_val);
  printf("testing list prepend, head val\n");
  if (test_list->head->val != some_val)
  {
    return 1;
  }
  
  printf("testing list prepend, head next");
  if (test_list->head->next->val != INT_MAX)
  {
    return 1;
  }
  
  printf("testing list prepend, tail val\n");
  if (test_list->tail->val != INT_MIN)
  {
    return 1;
  }

  printf("testing list prepend, another value head\n");
  some_val = rand();
  test_vals[0] = some_val;
  list_prepend(test_list, some_val);
  if (test_list->head->val != some_val)
  {
    return 1;
  }

  printf("testing list prepend, another value tail\n");
  if (test_list->tail->val != INT_MIN)
  {
    return 1;
  }

  printf("testing list prepend, another value tail next\n");
  if (test_list->head->next == NULL || test_list->head->next->next == NULL ||
      test_list->head->next->next->next == NULL ||
      test_list->head->next->next->next->next != NULL)
  {
    return 1;
  }
  
  printf("testing list index, out of range\n");
  if (list_index(test_list, INT_MAX) != NULL)
  {
    return 1;
  }
  
  printf("testing list index, vals\n");
  for (unsigned int i = 0; i < 4; i++)
  {
    if (list_index(test_list, i)->val != test_vals[i])
    {
      return 1;
    }
    
  }
  
  printf("testing list index, next pointers");
  for (unsigned int i = 0; i < 4; i++)
  {
    if (i < 3)
    {
      if (list_index(test_list, i)->next == NULL)
      {
        return 1;
      }
      
    }
    else
    {
      if (list_index(test_list, i)->next != NULL)
      {
        return 1;
      }
      
    }
    
  }
  
  return 0; // tests pass
}
