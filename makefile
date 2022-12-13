analyzer: *.c
  gcc -Wextra *.c -o analyzer
  
clean:
  rm -f *.o analyzer
  
