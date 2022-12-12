#include "syntax_parser.h"
#include "print_info.h"
#include <stdio.h>

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        fprintf(stderr, "Podaj nazwy plikow.\n");
        return 1;
    }

    init_parser();
    
    int i;
    for (i = 1; i < argc; i++)
    {
        if (parse_file_syntax(argv[i]) != 0)
        {
            close_parser();
            fprintf(stderr, "Któryś z plików zawiera błąd.\n");
            return 1;
        }
    }

    print_all_funs_info();

    close_parser();
    return 0;
}

