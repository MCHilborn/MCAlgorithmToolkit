CC=gcc
main: main.o
	$(CC) -o main main.o
clean: 
	rm -f main