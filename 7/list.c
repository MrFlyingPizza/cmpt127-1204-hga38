// t5.c

#include <stdio.h>
#include <stdlib.h>

#include "list.h"

list_t* list_create( void )
{
	list_t* new_list = malloc(sizeof(list_t));
	if (new_list)
	{
		new_list->head = NULL;
		new_list->tail = NULL;
	}
	return new_list;
}

void list_destroy( list_t* list )
{
	if (list == NULL)
	{
		return;
	}
	
	element_t* el = list->head, *next;
	while (el)
	{
		next = el->next;
		free(el);
		el = next;
	}
	
}

element_t* element_create( int i )
{
	element_t* el = malloc(sizeof(element_t));
	if (el)
	{
		el->next = NULL;
		el->val = i;
	}

	return el;
}

int list_append( list_t* list, int i )
{
	if (list == NULL)
	{
		return 1;
	}

	element_t* el = malloc(sizeof(element_t));
	if (el == NULL)
	{
		return 1;
	}

	el->val = i;
	el->next = NULL;

	if (list->head == NULL)
	{
		list->head = el;
		list->tail = el;
	}
	else
	{
		if (list->tail == NULL)
		{
			return 1;
		}
		

		list->tail->next = el;
		list->tail = el;
	}
	
	return 0;
	
}

int list_prepend( list_t* list, int i )
{
	if (list == NULL)
	{
		return 1;
	}

	element_t* el = malloc(sizeof(element_t));
	if (el == NULL)
	{
		return 1;
	}

	el->val = i;
	el->next = NULL;

	el->next = list->head->next;
	list->head = el;
	return 0;
}

element_t* list_index( list_t* list, unsigned int i )
{
	if (list == NULL)
	{
		return NULL;
	}

	if (list->head == NULL || list->tail == NULL)
	{
		return NULL;
	}
	
	
	unsigned int count = 0;
	element_t* result = NULL, *el = list->head;
	while (el != NULL && i < count)
	{
		if (count == i)
		{
			return el;
		}
		el = el->next;
		++count;
	}
	
	return el;
}

void list_print( list_t* list )
{
  printf( "{" );
  
  for( element_t* el = list->head;
       el;
       el = el->next )
    printf( " %d", el->val );

  printf( " }\n" );
}