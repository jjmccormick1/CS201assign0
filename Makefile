CC=gcc
CFLAGS=  -Wall -c -pedantic -ansi -std=c99
include integer/makefile

all:	sll.o dll.o node.o
	ar rc liblistlib.a node.o sll.o dll.o
	ranlib liblistlib.a

node.o: 
	$(CC) $(CFLAGS)  node.c node.h
	
sll.o:	node.o
	$(CC) $(CFLAGS) sll.c sll.h
	
dll.o:	node.o
	$(CC) $(CFLAGS) dll.c dll.h
	
	
test-sll: sll.o node.o integer.o
	$(CC) $(CFLAGS) -c test-sll.c 
	$(CC) $(CFLAGS) test-sll.o sll.o node.o integer/integer.o -o test-sll

	
clean:
	rm *.o
