#ifndef ALEX_VECTOR
#define ALEX_VECTOR

typedef struct
{
	int size, capacity;
	int* line_numbers;
	char** fun_names;
	char** file_names;
	char** mother_fun;
}Vector;

void init_vector(Vector* v);
char* get_top_fun_name(Vector *v);
void add_triple(Vector* v, int line_number, char* fun_name, char* file_name, char *mother_fun);
//char* get_mother_fun(Vector* v, int index);
//int get_line_number(Vector* v, int index);
//char* get_fun_name(Vector* v, int index);
//char* get_file_name(Vector* v, int index);
void delete_vector(Vector* v);
//int get_size(const Vector* v);

#endif // ALEX_VECTOR
