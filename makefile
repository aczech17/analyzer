analyzer:	fun_stack.c vector.c fun_info.c alex.c syntax_parser.c main.c
	gcc -Wextra fun_stack.c vector.c fun_info.c alex.c syntax_parser.c main.c -o analyzer

clean:
	rm -F analyzer*

