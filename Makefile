CC=gcc
CFLAGS=  -Wall -pedantic -ansi -std=c99

all:	single double
	ar rc liblistlib.a SingleLinkedList.o DoubleLinkedList.o 
	ranlib liblistlib.a

single: 
	$(CC) $(CFLAGS)  SingleLinkedList.c SingleLinkedList.h
double:
	$(CC) $(CFLAGS) DoubleLinkedList.c DoubleLinkedList.h 
clean:
	rm *.o
