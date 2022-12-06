#ifndef ALEX_VECTOR
#define ALEX_VECTOR

typedef struct
{
	int size, capacity;
	int* line_numbers;
	char** fun_names;
	char** file_names;
}Vector;

void init_vector(Vector* v);
void add_triple(Vector* v, int line_number, char* fun_name, char* file_name);
int get_line_number(Vector* v, int index);
char* get_fun_name(Vector* v, int index);
char* get_file_name(Vector* v, int index);
void delete_vector(Vector* v);
int get_size(const Vector* v);

#endif // ALEX_VECTOR
