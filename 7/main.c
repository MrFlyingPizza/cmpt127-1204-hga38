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
  list_t *list = list_create();

  int len = 5;
  int vals[len];
  int temp = 0;
  for (int i = 0; i < len; i++)
  {
    temp = rand();
    vals[i] = temp;
    list_append(list, temp);
  }

  // val loop check if vals match in list and array
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

int test_list_prepend()
{
  return 0;
}

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

  // test element create
  if (test_element_create() == 1)
    return 1;

  if (test_list_append() == 1)
    return 1;

  if (test_list_prepend() == 1)
    return 1;
  
  


  return 0;
}
