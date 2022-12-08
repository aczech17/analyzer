#ifndef ALEX_FUN_INFO_H
#define ALEX_FUN_INFO_H

#include "vector.h"

Vector fun_protos;
Vector fun_defs;
Vector fun_calls;

void store_add_proto(char* fun_name, int line, char* file_name);
void store_add_def(char* fun_name, int line, char* file_name);
void store_add_call(char* fun_name, int line, char* file_name, char* mother_fun);

#endif //ALEX_FUN_INFO_H
