#include "syntax_parser.h"
#include <stdio.h>
#include <string.h>
#include "alex.h"       // analizator leksykalny
#include "fun_stack.h"  // stos funkcji
#include "fun_info.h"

void init_parser()
{
    init_proto_vec();
    init_def_vec();
    init_call_vec();

    init_stack();
}

void close_parser()
{
    delete_proto_vec();
    delete_def_vec();
    delete_call_vec();

    delete_stack();
}

int parse_file_syntax(char* inpname)
{
    FILE* in = fopen(inpname, "r");


    if (in == NULL)
    {
        fprintf(stderr, "Nie otwarto pliku %s.\n", inpname);
        return 1;
    }

  	int nbra = 0;   // bilans nawiasów klamrowych {}
  	int npar = 0;   // bilans nawiasów zwykłych ()

    alex_init4file(in); // init lexem analyzer

  	lexem_t lex;
  	lex = alex_nextLexem();      // pobierz następny leksem

  	while (lex != EOFILE)
	{
    		switch (lex)
		    {
    			case IDENT:
			    {
        			char *iname = alex_ident();   // zapamiętaj identyfikator i patrz co dalej
        			lexem_t nlex = alex_nextLexem();
        			if (nlex == OPEPAR) // nawias otwierający - to zapewne funkcja
				    {
          				npar++;
          				put_on_fun_stack(npar, iname);       // odłóż na stos funkcji
                                                // stos f. jest niezbędny, aby poprawnie obsłużyć sytuacje typu
                                                // f1( 5, f2( a ), f3( b ) )
        			}
        			else // nie nawias, czyli nie funkcja
				    {
          				lex = nlex;
          				continue;
        			}
      			}
      			break;


    			case OPEPAR:
                {
                    npar++;
                    break;
                }

    			case CLOPAR: // zamykający nawias - to może być koniec prototypu, nagłówka albo wywołania
			    {
        			if (get_stack_size() > 0 &&
                        top_of_funstack() == npar) // sprawdzamy, czy liczba nawiasów bilansuje się z wierzchołkiem stosu funkcji
				    {
                        // jeśli tak, to właśnie wczytany nawias jest domknięciem nawiasu otwartego
                        // za identyfikatorem znajdującym się na wierzchołku stosu

                        char* new_fun = get_from_fun_stack();
          				lexem_t nlex = alex_nextLexem();     // bierzemy nast leksem

          				if (nlex == OPEBRA && nbra == 0)   // nast. leksem to klamra a więc mamy do czynienia z def. funkcji
                        {
                              nbra++;
                              store_add_def(new_fun, alex_getLN(), inpname);
                        }
          				else if (nbra == 0)   // nast. leksem to nie { i jesteśmy poza blokami - to musi być prototyp
                        {
                              store_add_proto(new_fun, alex_getLN(), inpname);
                        }
                        else                  // nast. leksem to nie { i jesteśmy wewnątrz bloku - to zapewne wywołanie
                        {
                            char* calling_function_name = get_last_def_name();
                            store_add_call(new_fun, alex_getLN(), inpname, calling_function_name);
                        }
        			}
        			npar--;
      			}
      			break;

    			case OPEBRA:
                    nbra++;
      				break;
    
			case CLOBRA:
      				nbra--;
      				break;
    
			case ERROR:
			{
                fclose(in);
				return 1;
            }
            break;
    
			default:
                break;
    		}

		    lex = alex_nextLexem();
    }

    fclose(in);

    return 0;
}

