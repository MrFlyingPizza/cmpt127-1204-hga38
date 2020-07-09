#include <stdio.h>
#include <stdlib.h>

#include "list.h"

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

  // destroy test
  const unsigned int len = 200;
  int test_arr[len];
  for (unsigned int i = 0; i < len; i++)
  {
    test_arr[i] = rand();
  }
  printf("ga\n");
  list_destroy(list);
  element_t *test_ptr = list_index(list, 0);
  printf("%p", test_ptr);
  if (test_ptr != NULL)
  {
    return 1;
  }
  
  
  return 0; // tests pass
}
