CC=gcc
CFLAGS=  -Wall -c -pedantic -ansi -std=c99

all:	node sll dll
	ar rc liblistlib.a node.o sll.o dll.o
	ranlib liblistlib.a

node: 
	$(CC) $(CFLAGS)  node.c node.h
sll:
	$(CC) $(CFLAGS) sll.c sll.h
dll:
	$(CC) $(CFLAGS) dll.c dll.h

clean:
	rm *.o
