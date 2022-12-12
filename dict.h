#ifndef ALEX_DICT_H
#define ALEX_DICT_H

typedef struct
{
    int size;
    int capacity;

    char** fun_names;
    int* counts;
}Dict;

void init_dict(Dict* dict);
void add_fun_name(Dict* dict, char* fun_name);
int get_count(Dict* dict, char* fun_name);
void delete_dict(Dict* dict);

#endif //ALEX_DICT_H
