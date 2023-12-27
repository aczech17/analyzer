analyzer: *.c
	gcc -Wall -Wextra *.c -o analyzer
  
clean:
	rm -f *.o analyzer
