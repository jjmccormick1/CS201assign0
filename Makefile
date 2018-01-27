
CC=gcc
CFLAGS=  -Wall -Wextra -c -ggdb -pedantic -std=c99 -O0
LFLAGS=  -Wall -Wextra -pedantic  -std=c99 -ggdb
COREOBJS= node.o sll.o dll.o stack.o queue.o

all:	lib

lib:	
	@$(CC) $(CFLAGS) node.c node.h sll.c sll.h dll.c dll.h stack.c stack.h queue.c queue.h
	@ar rc	 liblistlib.a $(COREOBJS)
	@ranlib liblistlib.a

	
string: 
	@$(CC) $(CFLAGS) string.c string.h
	
test-node : 
	@$(CC) $(CFLAGS) nodetest.c node.c node.h
	@$(CC) $(LFLAGS) nodetest.o node.o -o nodetest

integer.o: 
	@$(CC) $(CFLAGS) integer.c integer.h

string.o:
	@$(CC) $(CFLAGS) string.c string.h
	
test-sll: all integer.o string.o
	@$(CC) $(CFLAGS)  test-sll.c 
	@$(CC) $(LFLAGS) test-sll.o integer.o sll.o node.o -o test-sll

test-dll: all integer.o string.o
	@$(CC) $(CFLAGS)  test-dll.c
	@$(CC) $(LFLAGS) test-dll.o integer.o sll.o dll.o node.o -o test-dll
	
test-stack: all integer.o string.o 
	@$(CC) $(CFLAGS) test-stack.c
	@$(CC) $(LFLAGS) $(COREOBJS) test-stack.o string.o integer.o -o test-stack
	
test-queue: all integer.o string.o 
	@$(CC) $(CFLAGS) test-queue.c
	@$(CC) $(LFLAGS) $(COREOBJS) test-queue.o string.o integer.o -o test-queue

test: clean  test-sll test-dll
	@echo "Testing SLL .. \n"
	@./test-sll
	@echo "Testing DLL .. \n"
	@./test-dll
clean:
	@rm -f *.o || true
	@rm -f *.a || true
	@rm -f *.gch || true
