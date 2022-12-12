#include "alex.h"

#include <ctype.h>
#include <string.h>

static int  ln;
static char ident[256];
static FILE* ci = NULL;

int isalpha_or_floor( char c )
{
    if ( isalpha(c) )
        return 1;

    if ( c == '_')
        return 1;

    return 0;
}

int isalnum_or_floor( char c )
{
    if ( isalnum(c) )
        return 1;

    if ( c == '_')
        return 1;

    return 0;
}


int isKeyword(const char string[256])
{
	const char* keywords[] = {
		"auto",
        "break",
		"case",
		"char",
		"const",
		"continue",
		"default",
		"do",
		"double",
		"else",
		"enum",
		"extern",
		"float",
		"for",
		"goto",
		"if",
		"int",
		"long",
		"register",
		"return",
		"short",
		"signed",
		"sizeof",
		"static",
		"struct",
		"switch",
		"typedef",
		"union",
		"unsigned",
		"void",
		"volatile",
		"while",
	};
	const int count = 32;
	int i;
	for (i = 0; i < count; i++)
	{
		if (strcmp(string, keywords[i]) == 0)
			return 1;
	}

	return 0;
}

void alex_init4file(FILE *in)
{
   	ln = 1; // 0 or 1?
   	ci = in;
}

lexem_t alex_nextLexem()
{
  	int c;
  	while((c = fgetc(ci)) != EOF)
	{
          if (c == '\n')
          {
              ln++;
              continue;
          }

          if(isspace(c))
              continue;
          else if(c == '(')
              return OPEPAR;
          else if(c == ')')
          {
              //printf(")\n");
              return CLOPAR;
          }
          else if(c == '{')
              return OPEBRA;
          else if(c == '}')
              return CLOBRA;
          else if((isalpha_or_floor(c))) // Zakładamy, że nazwa funkcji może się składać tylko z liter i znaków "_"
          {
              ident[0] = (char)c;
              int i = 1;

              while( ( isalnum_or_floor(c = fgetc(ci)) ) )
                  ident[i++] = (char) c;

              ident[i] = '\0';

              //printf("ident %s\n", ident);
              fseek(ci, -1, SEEK_CUR); // step back


              if (isKeyword(ident))
                  return OTHER;

              return IDENT;
          }

          else if(c == '"')
          {
              int cp;
              while (1)
              {
                  cp = c;
                  c = fgetc(ci);

                  if (c == EOF)
                      return ERROR; // quotes not closed

                  if (cp != '\\' && c == '"')
                      return OTHER; // quotes
              }
          }

          else if(c == '/')
          {
              c = fgetc(ci);
              if (c == '*')
              {
                  int cp;
                  do
                  {
                      cp = c;
                      c = fgetc(ci);

                      if (c == '\n')
                          ln++;
                  } while (!(cp == '*' && c == '/'));

                  continue; // ignore the comment
              }
              else if (c == '/') // c++ style comment. Read until endl.
              {
                  while((c = fgetc(ci)) != '\n');
                  ln++; // endline reached. increment ln

                  continue; // ignore the comment
              }
          }

          if(isdigit(c) || c == '.')
          {
      			/* liczba */
          }

          else
          {
              return OTHER;
          }
    }

    return EOFILE;
}

char* alex_ident()
{
   	return ident;
}

int alex_getLN()
{
    return ln;
}

