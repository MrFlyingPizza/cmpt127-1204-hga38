#include <stdio.h>
#include <stdlib.h>

#include "list.h"
#include <limits.h>
#include <assert.h>
#include <string.h>


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
  unsigned int len = 200;
  int test_vals[len];
  for (unsigned int i = 0; i < len; i++)
  {
    test_vals[i] = rand();
  }
  
  // testing list append
  list_t *test_list = list_create();
  for (unsigned int i = 0; i < len; i++)
  {
    list_append(test_list, test_vals[i]);
  }
  
  element_t *test_element_ptr = test_list->head;
  for (unsigned int i = 0; i < len - 1; i++)
  {
    if (test_element_ptr == NULL)
    {
      return 1;
    }

    if (test_element_ptr->next == NULL)
    {
      return 1;
    }
    
    if (test_element_ptr->val != test_vals[i])
    {
      return 1;
    }
    //printf("test_el: %d | test_vals: %d\n", test_element_ptr->val, test_vals[i]);
    test_element_ptr = test_element_ptr->next;
  }
  
  if (test_element_ptr->next != NULL)
  {
    return 1;
  }
  

  // testing element_create()
  element_t *el = malloc(sizeof(element_t));
  assert(el);

  memset(el, 0xFF, sizeof(element_t));
  free(el);

  el = element_create(INT_MAX);
  assert(el);

  if (el->next)
  {
    puts("element_create(): el->next not NULL");
    return 1;
  }

  if (el->val != INT_MAX)
  {
    puts("element_create(): el->value wrong");
    return 1;
  }

  return 0;
}
