#include <stdio.h>
#include <stdlib.h>

#include "list.h"
#include <limits.h>
#include <assert.h>
#include <string.h>

int test_element_create()
{
  int test_val = 1942;
  element_t *test_element = malloc(sizeof(element_t));
  assert(test_element);
  memset(test_element, 0xFF, sizeof(element_t));
  free(test_element);

  test_element = element_create(test_val);
  assert(test_element);

  if (test_element->next)
  {
    puts("element_create(): test_element->next not NULL.");
    return 1;
  }

  if (test_element->val != test_val)
  {
    puts("element_create(): test_element->val not correct.");
    return 1;
  }
  
  return 0;
}

int test_list_append()
{
  int success = 0;

  list_t *list = list_create();
  success = list_append(list, 299);
  if (success == 1)
  {
    return 1;
  }
  
  if (list->head == NULL || list->tail == NULL)
  {
    return 1;
  }
  
  if (list->head->val != 299)
  {
    return 1;
  }
  
  if (list->head != list->tail)
  {
    return 1;
  }
  
  success = list_append(list, 300);
  if (success == 1)
  {
    return 1;
  }
  
  if (list->tail->val != 300)
  {
    return 1;
  }

  if (list->head->next != list->tail)
  {
    return 1;
  }
  
  success = list_append(list, 301);
  if (success == 1)
  {
    return 1;
  }
  
  if (list->tail->val != 301)
  {
    return 1;
  }
  
  if (list->head->next->next != list->tail)
  {
    return 1;
  }

  if (list->tail->next != NULL)
  {
    return 1;
  }

  return 0;
}

int test_list_prepend()
{
  list_t *list = list_create();

  int len = 5;
  int vals[len];
  int temp = 0;
  for (int i = len - 1; i >= 0; i--)
  {
    temp = rand();
    vals[i] = temp;
    list_prepend(list, temp);
  }

  element_t *temp_el = list->head;
  for (int i = 0; i < len - 1; i++)
  {
    if (temp_el->next == NULL)
    {
      return 1;
    }
    
    if (temp_el->val != vals[i])
    {
      return 1;
    }
    temp_el = temp_el->next;
  }

  if (temp_el != list->tail) // final index check
  {
    return 1;
  }
  
  if (temp_el->next != NULL)
  {
    return 1;
  }
  
  if (temp_el->val != vals[4])
  {
    return 1;
  }

  return 0;
}

int test_list_destroy()
{
  list_t *list = list_create();
  list_destroy(list);
  list_t *list2 = list_create();
  if (list != list2)
  {
    return 1;
  }
  
  return 0;
}

int test_list_index()
{
  list_t *list = list_create();
  if (list_index(list, 10))
  {
    return 1;
  }
  

  element_t *el = element_create(INT_MAX);
  if (el == NULL)
  {
    printf("\tFailed el create\n");
    return 1;
  }
  
  list->head = el;
  list->tail = el;
  printf("\ttesting index 0\n");
  if (list_index(list, 0) != el)
  {
    return 1;
  }
  printf("\ttesting index 1\n");
  if (list_index(list, 1) != NULL)
  {
    return 1;
  }
  
  return 0;
}

int main( int argc, char* argv[] )
{
  puts("------ running test -----");
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

  // test element create
  puts("test element create\n");
  if (test_element_create() == 1)
    return 1;

  puts("test list append\n");
  if (test_list_append() == 1)
    return 1;

  puts("test list prepend");
  if (test_list_prepend() == 1)
    return 1;

  puts("test list destroy");
  if (test_list_destroy() == 1)
    return 1;

  puts("test list index");
  if (test_list_index() == 1)
    return 1;
  

  return 0;
}
