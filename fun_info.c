#include "fun_info.h"

#include <stdio.h> //DEBUG

Vector fun_protos;
Vector fun_defs;
Vector fun_calls;

void store_add_proto(char* fun_name, int line, char* file_name)
{
    add_triple(&fun_protos, line, fun_name, file_name, "");
}
void store_add_def(char* fun_name, int line, char* file_name)
{
    //printf("dodano funkcję %s w pliku %s\n", fun_name, file_name);
    add_triple(&fun_defs, line, fun_name, file_name, "");
}
void store_add_call(char* fun_name, int line, char* file_name, char *mother_fun)
{
    add_triple(&fun_calls, line, fun_name, file_name, mother_fun);
}

void init_proto_vec()
{
    init_vector(&fun_protos);
}

void init_def_vec()
{
    init_vector(&fun_defs);
}

void init_call_vec()
{
    init_vector(&fun_calls);
}

void delete_proto_vec()
{
    delete_vector(&fun_protos);
}

void delete_def_vec()
{
    delete_vector(&fun_defs);
}

void delete_call_vec()
{
    delete_vector(&fun_calls);
}

char* get_last_def_name()
{
    return get_top_fun_name(&fun_defs);
}

int get_proto_size()
{
    return fun_protos.size;
}

int get_def_size()
{
    return fun_defs.size;
}

int get_call_size()
{
    return fun_calls.size;
}

char** get_mother_funs()
{
    return fun_calls.mother_fun;
}

char** get_proto_names()
{
    return fun_protos.fun_names;
}

char** get_def_names()
{
    return fun_defs.fun_names;
}

char** get_call_names()
{
    return fun_calls.fun_names;
}

int* get_proto_line_numbers()
{
    return fun_protos.line_numbers;
}

int* get_def_line_numbers()
{
    return fun_defs.line_numbers;
}

int* get_call_line_numbers()
{
    return fun_calls.line_numbers;
}

char** get_proto_file_names()
{
    return fun_protos.file_names;
}

char** get_def_file_names()
{
    return fun_defs.file_names;
}

char** get_call_file_names()
{
    return fun_calls.file_names;
}

