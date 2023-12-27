#include "fun_info.h"
#include "dict.h"
#include <stdio.h>
#include <string.h>

static int print_called_by(char* mothername)
{
    int is_calling = 0;

    Dict dict;
    init_dict(&dict);

    char** mother_funs = get_mother_funs();

    int i;
    for (i = 0; i < get_call_size(); i++)
    {
        if(strcmp(mother_funs[i], mothername) == 0) // i-th calls mother is mothername
        {
            add_fun_name(&dict, get_call_names()[i]); // i-th function call
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


static void print_fun_info(char* funame)
{
    int counter;

    printf("Funkcja %s:\n", funame);
    printf("    Prototyp:\n");
    

    counter = 0;

    int i;
    for(i = 0; i < get_proto_size(); i++)
    {
        if(strcmp(get_proto_names()[i], funame) == 0) // i-th prototype name is funame
        {
            printf("        Plik %s od linii %d\n", get_proto_file_names()[i], get_proto_line_numbers()[i]);
            counter++;
            break;
        }
    }

    if(counter == 0)
    {
        printf("        Brak\n");
    }


    

    printf("    Definicja:\n");
    counter = 0;
    for(i = 0; i < get_def_size(); i++)
    {
        if(strcmp(get_def_names()[i], funame) == 0)
        {
            printf("        Plik %s od linii %d\n", get_def_file_names()[i], get_def_line_numbers()[i]);
            counter++;
            break;
        }
    }

    if(counter == 0)
    {
        printf("        Brak\n");
    }

    


    printf("    Użycie:\n");
    counter = 0;
    for(i = 0; i < get_call_size(); i++)
    {
        if(strcmp(get_call_names()[i], funame) == 0)
        {
            printf("        Plik %s od linii %d\n", get_call_file_names()[i], get_call_line_numbers()[i]);
            counter++;
        }
    }
    if(counter == 0)
    {
        printf("        Brak\n");
    }


    
    printf("    Wywołuje:\n");
    if(print_called_by(funame) == 0)
        printf("        Brak\n");
    printf("\n");
}

void print_all_funs_info()
{
    int i;
    for (i = 0; i < get_def_size(); i++)
    {
        print_fun_info(get_def_names()[i]);
    }
}

