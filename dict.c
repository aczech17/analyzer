#include "dict.h"
#include <stdlib.h>
#include <string.h>

/*
 * typedef struct
{
    int size;
    int capacity;

    char** fun_names;
    int* counts;
}Dict;
 */

void init_dict(Dict* dict)
{
    dict->size = 0;
    dict->capacity = 10;

    dict->fun_names = calloc(dict->capacity, sizeof(char*));
    dict->counts = malloc(dict -> capacity * sizeof(int));
}

static void resize(Dict* dict)
{
    dict->capacity *= 2;

    dict->fun_names = realloc(dict->fun_names, dict->capacity * sizeof(char*));
    int i;
    for (i = dict->size; i < dict->capacity; i++)
    {
        dict->fun_names[i] = NULL;
    }

    dict->counts = realloc(dict->counts, dict->capacity * sizeof(int));
}

void add_fun_name(Dict* dict, char* fun_name)
{
    int i;
    for (i = 0; i < dict->size; i++)
    {
        if (strcmp(dict->fun_names[i], fun_name) == 0)
        {
            dict->counts[i]++;
            return;
        }
    }

    if (dict->size == dict->capacity)
        resize(dict);

    dict->fun_names[dict->size] = malloc((strlen(fun_name) + 1) * sizeof(char));
    strcpy(dict->fun_names[dict->size], fun_name);

    dict->counts[dict->size] = 1;
    dict->size++;
}

int get_count(Dict* dict, char* fun_name)
{
    int i;
    for (i = 0; i < dict->size; i++)
    {
        if (strcmp(dict->fun_names[i], fun_name) == 0)
            return dict->counts[i];
    }
    return 0;
}

void delete_dict(Dict* dict)
{
    int i;
    for (i = 0; i < dict->capacity; i++)
    {
        free(dict->fun_names[i]);
    }

    free(dict->fun_names);
    free(dict->counts);
}
