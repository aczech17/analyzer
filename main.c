#include "syntax_parser.h"
#include "fun_info.h"
#include <stdio.h>
#include "fun_stack.h"
#include <string.h>

#include "vector.h"
#include "dict.h"


int gets_called_by( char* funame )
{
    int is_calling = 0;

    Dict dict;
    init_dict(&dict);

    int i;
    for (i = 0; i < fun_calls.size; i++)
    {
        if( strcmp( fun_calls.mother_fun[i], funame ) == 0 )
        {
            add_fun_name(&dict, fun_calls.fun_names[i]);
            is_calling = 1;
        }
    }

    for (i = 0; i < dict.size; i++)
    {
        int count = dict.counts[i];
        printf("        %s", dict.fun_names[i]);
        if (count > 1)
        {
            printf(" (%d razy)", count);
        }
        printf("\n");
    }

    delete_dict(&dict);
    return is_calling;
}



void print_fun_info( char* funame )
{
    int counter;

    printf("Funkcja %s:\n", funame);
    printf("    Prototyp:\n");
    int i;

    counter = 0;
    for( i = 0; i < fun_protos.size; i++ )
    {
        if( strcmp( fun_protos.fun_names[i], funame ) == 0 )
        {
            printf("        Plik %s od linii %d\n", fun_protos.file_names[i], fun_protos.line_numbers[i] );
            counter++;
            break;
        }
    }
    if( counter == 0 )
    {
        printf("        Brak\n");
    }

    counter = 0;

    printf("    Definicja:\n");
    for( i = 0; i < fun_defs.size; i++ )
    {
        if( strcmp( fun_defs.fun_names[i], funame ) == 0 )
        {
            printf("        Plik %s od linii %d\n", fun_defs.file_names[i], fun_defs.line_numbers[i] );
            counter++;
            break;
        }
    }
    if( counter == 0 )
    {
        printf("        Brak\n");
    }

    counter = 0;

    printf("    Użycie:\n");
    for( i = 0; i < fun_calls.size; i++ )
    {
        if( strcmp( fun_calls.fun_names[i], funame ) == 0 )
        {
            printf("        Plik %s od linii %d\n", fun_calls.file_names[i], fun_calls.line_numbers[i] );
            counter++;
        }
    }
    if( counter == 0 )
    {
        printf("        Brak\n");
    }

    counter = 0;
    printf("    Wywołuje:\n");
    
    if( gets_called_by( funame ) == 0 )
        printf("        Brak\n");
    printf("\n");

}

void print_funs(Vector* vec)
{
    int size = get_size(vec);
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%s ", get_fun_name(vec, i));
        printf("%d ", get_line_number(vec, i));
        printf("%s\n", get_file_name(vec, i));

        //if( strcmp( get_mother_fun( vec, i ), "" ) != 0 )
        //    printf("Funkcja matka funkcji %s to %s\n", get_fun_name( vec, i ), get_mother_fun(vec, i));
    }
}

int main(int argc, char** argv)
{
    printf("\n\n");
    if (argc < 2)
    {
        fprintf(stderr, "Podaj nazwy plikow.\n");
        return 1;
    }

    init_parser();

    int i;
    for (i = 1; i < argc; i++)
    {
        parse_file_syntax(argv[i]);
    }

    /* gets_called_by("main");

    puts("\nprotos:");
    print_funs(&fun_protos);

    puts("\ndefs:");
    print_funs(&fun_defs);

    puts("\ncalls:");
    print_funs(&fun_calls);

    */ 

    for( i = 0; i < fun_defs.size; i++ )
    {
        print_fun_info( fun_defs.fun_names[i] );
    }
    close_parser();
    return 0;
}
