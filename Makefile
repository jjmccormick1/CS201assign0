
CC=clang
CFLAGS=  -Wall -c -pedantic -std=c99 -O1 -g -fsanitize=address -fno-omit-frame-pointer
LFLAGS=  -Wall  -pedantic  -std=c99 -O1 -g -fsanitize=address -fno-omit-frame-pointer


all:	sll.o  node.o
	ar rc liblistlib.a node.o sll.o 
	ranlib liblistlib.a

node.o: 
	$(CC) $(CFLAGS)  node.c node.h
	
sll.o:	node.o
	$(CC) $(CFLAGS) sll.c sll.h
	
dll.o:	node.o
	$(CC) $(CFLAGS) dll.c dll.h
	
integer.o:
	$(CC) $(CFLAGS) integer.c integer.h

test-sll.o:
	$(CC) $(CFLAGS)  test-sll.c 
	
test-sll: all integer.o test-sll.o
	$(CC) $(LFLAGS) test-sll.o integer.o -L. -llistlib -o test-sll

	
clean:
	rm *.o
