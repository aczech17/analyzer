#ifndef FUN_STACK_H
#define FUN_STACK_H

#include <stdio.h>



int top_of_funstack( void );  // zwraca par_level - "zagłębienie nawiasowe" przechowywane na szczycie
void put_on_fun_stack( int par_level, char *funame ); // odkłada na stos parę (funame,par_level)
char *get_from_fun_stack( void ); // usuwa z wierzchołka parę (funame,par_level), zwraca zdjętą funame
int get_stack_size();

void init_stack();
void delete_stack();

#endif // FUN_STACK_H

