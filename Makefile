CC=gcc
CFLAGS=  -Wall -c -pedantic -ansi -std=c99

all:	single 
	ar rc liblistlib.a list.o  stack.o queue.o
	ranlib liblistlib.a

single: 
	$(CC) $(CFLAGS)  list.c list.h stack.c stack.h queue.c queue.h

clean:
	rm *.o
