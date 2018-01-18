CC=gcc
CFLAGS=  -Wall -c -pedantic -ansi -std=c99

all:	single 
	ar rc liblistlib.a list.o  
	ranlib liblistlib.a

single: 
	$(CC) $(CFLAGS)  list.c list.h

clean:
	rm *.o
