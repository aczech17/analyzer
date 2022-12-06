#include "syntax_parser.h"
#include "fun_info.h"
#include <stdio.h>
#include "fun_stack.h"

#include "vector.h"

void print_funs(Vector* vec)
{
    int size = get_size(vec);
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%s ", get_fun_name(vec, i));
        printf("%d ", get_line_number(vec, i));
        printf("%s\n", get_file_name(vec, i));
    }
}

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        fprintf(stderr, "Podaj nazwy plików.\n");
        return 1;
    }

    init_parser();

    int i;
    for (i = 1; i < argc; i++)
    {
        parse_file_syntax(argv[i]);
    }

    puts("\nprotos:");
    print_funs(&fun_protos);

    puts("\ndefs:");
    print_funs(&fun_defs);

    puts("\ncalls:");
    print_funs(&fun_calls);

    close_parser();
    return 0;
}
