
CC=gcc
CFLAGS=  -Wall -c -pedantic -ansi -std=c99
LFLAGS=  -Wall  -pedantic -ansi -std=c99


all:	sll.o dll.o node.o
	ar rc liblistlib.a node.o sll.o dll.o
	ranlib liblistlib.a

node.o: 
	$(CC) $(CFLAGS)  node.c node.h
	
sll.o:	node.o
	$(CC) $(CFLAGS) sll.c sll.h
	
dll.o:	node.o
	$(CC) $(CFLAGS) dll.c dll.h
	
integer.o:
	$(CC) $(CFLAGS) integer.c integer.h
	
	
test-sll: sll.o node.o integer.o
	$(CC) $(CFLAGS)  test-sll.c 
	$(CC) $(LFLAGS) test-sll.o integer.o sll.o node.o -o test-sll

	
clean:
	rm *.o
