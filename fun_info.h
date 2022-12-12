#ifndef ALEX_FUN_INFO_H
#define ALEX_FUN_INFO_H

#include "vector.h"

void init_proto_vec();
void init_def_vec();
void init_call_vec();

void delete_proto_vec();
void delete_def_vec();
void delete_call_vec();

void store_add_proto(char* fun_name, int line, char* file_name);
void store_add_def(char* fun_name, int line, char* file_name);
void store_add_call(char* fun_name, int line, char* file_name, char* mother_fun);

char* get_last_def_name();

int get_proto_size();
int get_def_size();
int get_call_size();

char** get_mother_funs();

char** get_proto_names();
char** get_def_names();
char** get_call_names();

int* get_proto_line_numbers();
int* get_def_line_numbers();
int* get_call_line_numbers();

char** get_proto_file_names();
char** get_def_file_names();
char** get_call_file_names();

#endif //ALEX_FUN_INFO_H

