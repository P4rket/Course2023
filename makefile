CC = gcc -Wall -Werror -Wextra 
CO = gcc -c -Wall -Werror -Wextra 

all: main

main: palindrome.o main.o
	$(CC) lib/palindrome.o main.o -o palindrome

palindrome.o: 
	$(CO) lib/palindrome.c -o lib/palindrome.o

main.o: 
	$(CO) main.c -o main.o

rebuild: clean all

clean:
	rm -rf *.o *.a lib/*.o palindrome