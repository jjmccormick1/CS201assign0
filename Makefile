
CC=gcc
CFLAGS=  -Wall -Wextra -c -g -pedantic -std=c99 -O0
LFLAGS=  -Wall -Wextra -pedantic  -std=c99 -g


all:	lib

lib:	$(COREOBJS)
	ar rc liblistlib.a $(COREOBJS)
	ranlib liblistlib.a

node.o: 
	$(CC) $(CFLAGS)  node.c node.h
	
sll.o:	node.o
	$(CC) $(CFLAGS) sll.c sll.h
	
dll.o:	node.o
	$(CC) $(CFLAGS) dll.c dll.h 

test-sll.o:
	$(CC) $(CFLAGS)  test-sll.c 
	
test-sll: all integer.o test-sll.o
	$(CC) $(LFLAGS) test-sll.o integer.o -L. -llistlib -o test-sll

test-dll.o: 
	$(CC) $(CFLAGS)  test-dll.c
	
test-dll: all integer.o test-dll.o
	$(CC) $(LFLAGS) test-dll.o integer.o -L. -llistlib -o test-dll

test: test-dll test-sll
	echo "Testing SLL .. \n"
	./test-sll
	echo "Testing DLL .. \n"
	./test-dll
clean:
	rm *.o
