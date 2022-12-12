#include <stdlib.h>
#include "fun_stack.h"
#include <string.h>
#include <stdio.h>

struct
{
        size_t size;
        size_t capacity;

        int* arr_par;
        char** funame;
}stack;

void init_stack()
{
	stack.size = 0;
	stack.capacity = 10;

	stack.arr_par = malloc(stack.capacity * sizeof(unsigned int));
	stack.funame = calloc(stack.capacity, sizeof(char*));
}

void put_on_fun_stack(int par_level, char* funame)
{
    size_t i;
    for (i = stack.size; i < stack.capacity; i++)
	{
		free(stack.funame[i]);
        stack.funame[i] = NULL;
	}
    
	if (stack.size == stack.capacity)
	{
		stack.capacity *= 2;
		stack.arr_par = realloc(stack.arr_par, stack.capacity * sizeof(unsigned int));
		stack.funame = realloc(stack.funame, stack.capacity * sizeof(char*));
		
		for (i = stack.size; i < stack.capacity; i++)
		{
			stack.funame[i] = NULL;
		}
	}

	stack.arr_par[stack.size] = par_level;

	stack.funame[stack.size] = malloc((strlen(funame) + 1) * sizeof(char));
	strcpy(stack.funame[stack.size], funame);

	stack.size++;
}

char* get_from_fun_stack()
{
    if (stack.size == 0)
        return NULL;


    stack.size--;

    return stack.funame[stack.size];
}

int get_stack_size()
{
    return stack.size;
}

int top_of_funstack()
{
	return stack.arr_par[stack.size - 1];
}

void delete_stack()
{
	unsigned i;
	for (i = 0; i < stack.capacity; i++)
	{
		free(stack.funame[i]);
        	stack.funame[i] = NULL; // not to be deleted again by new owner
	}
	free(stack.funame);
	free(stack.arr_par);
}

