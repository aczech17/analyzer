#include "vector.h"
#include <stdlib.h>
#include <string.h>

/*
typedef struct
{
	int size, capacity;

	int* line_numbers;
	char** fun_names;
	char** file_names;
}Vector;
 */

void init_vector(Vector* v)
{
    v->size = 0;
    v->capacity = 10;

    v->line_numbers = malloc(v->capacity * sizeof(*v->line_numbers));
    v->fun_names = calloc(v->capacity, sizeof(*v->fun_names));
    v->file_names = calloc(v->capacity, sizeof(*v->file_names));
}

void add_triple(Vector* v, int line_number, char* fun_name, char* file_name)
{
    if (v->size == v->capacity)
    {
        v->capacity *= 2;

        v->line_numbers = realloc(v->line_numbers, v->capacity * sizeof(*v->line_numbers));

        v->fun_names = realloc(v->fun_names, v->capacity * sizeof(*v->fun_names));
        v->file_names = realloc(v->file_names, v->capacity * sizeof(*v->file_names));

        int i;
        for (i = v->size; i < v->capacity; i++)
        {
            v->file_names[i] = v->fun_names[i] = NULL;
        }
    }

    v->line_numbers[v->size] = line_number;

    v->fun_names[v->size] = malloc((strlen(fun_name) + 1) * sizeof(char));
    strcpy(v->fun_names[v->size], fun_name);

    v->file_names[v->size] = malloc((strlen(file_name) + 1) * sizeof(char));
    strcpy(v->file_names[v->size], file_name);

    v->size++;
}

int get_line_number(Vector* v, int index)
{
    return v->line_numbers[index];
}

char* get_fun_name(Vector* v, int index)
{
    return v->fun_names[index];
}

char* get_file_name(Vector* v, int index)
{
    return v->file_names[index];
}

void delete_vector(Vector* v)
{
    int i;
    for (i = 0; i < v->capacity; i++)
    {
        free(v->fun_names[i]);
        free(v->file_names[i]);
    }

    free(v->fun_names);
    free(v->file_names);

    free(v->line_numbers);
}

int get_size(const Vector* v)
{
    return v->size;
}
