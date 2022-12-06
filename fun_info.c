#include "fun_info.h"

#include <stdio.h> // DEBUG

void store_add_proto(char* fun_name, int line, char* file_name)
{
    //puts("ADD PROTO");
    add_triple(&fun_protos, line, fun_name, file_name);
}
void store_add_def(char* fun_name, int line, char* file_name)
{
    //puts("ADD DEF");
    add_triple(&fun_defs, line, fun_name, file_name);
}
void store_add_call(char* fun_name, int line, char* file_name)
{
    //puts("ADD CALL");
    add_triple(&fun_calls, line, fun_name, file_name);
}
