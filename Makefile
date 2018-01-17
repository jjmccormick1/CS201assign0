CC=clang
CFLAGS= -Wall

all:	lib
	ar rc liblistlib.a SingleLinkedList.o DoubleLinkedList.o 
	ranlib liblistlib.a

lib:
	$(CC) $(CFLAGS)  SingleLinkedList.h DoubleLinkedList.h

