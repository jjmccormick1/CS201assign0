CC=clang
CFLAGS= -Wall

all:	lib
	ar rc listlib.a SingleLinkedList.o DoubleLinkedList.o 
	ranlib listlib.a

lib:
	$(CC) $(CFLAGS)  SingleLinkedList.h DoubleLinkedList.h

