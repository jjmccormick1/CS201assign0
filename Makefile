
CC=gcc
CFLAGS=  -Wall -Wextra -c -ggdb -pedantic -std=c99 -D_XOPEN_SOURCE=600 -O0
LFLAGS=  -Wall -Wextra -pedantic  -std=c99 -ggdb
COREOBJS= node.o sll.o dll.o stack.o queue.o

all:	lib

lib:	
	@$(CC) $(CFLAGS) node.c node.h sll.c sll.h dll.c dll.h stack.c stack.h queue.c queue.h
	
		
string: 
	@$(CC) $(CFLAGS) string.c string.h
	
test-node : 
	@$(CC) $(CFLAGS) nodetest.c node.c node.h
	@$(CC) $(LFLAGS) nodetest.o node.o -o nodetest

integer.o: 
	@$(CC) $(CFLAGS) integer.c integer.h
	
	
test-sll: all integer.o 
	@$(CC) $(CFLAGS)  sll-0-0.c
	@$(CC) $(LFLAGS) sll-0-0.o integer.o sll.o node.o -o test-sll

test-dll: all integer.o
	@$(CC) $(CFLAGS)  dll-0-0.c
	@$(CC) $(LFLAGS) dll-0-0.o integer.o sll.o dll.o node.o -o test-dll

test-stack: all integer.o
	@$(CC) $(CFLAGS)  stack-0-0.c
	@$(CC) $(LFLAGS) $(COREOBJS) stack-0-0.o integer.o -o test-stack
	
test-queue: all integer.o
	@$(CC) $(CFLAGS)  queue-0-0.c
	@$(CC) $(LFLAGS) $(COREOBJS) queue-0-0.o integer.o -o test-queue
	
test: clean  test-sll test-dll test-stack test-queue
	@echo "Testing SLL .. \n"
	@./test-sll
	@echo "Testing DLL .. \n"
	@./test-dll
	@echo "Testing Stack .. \n"
	@./test-stack
	@echo "Testing Queue .. \n"
	@./test-queue
	
valgrind: test
	@./valgrind test-sll
	@./valgrind test-dll
	@./valgrind test-stack
	@./valgrind test-queue
	
clean:
	@rm -f *.o || true
	@rm -f *.a || true
	@rm -f *.gch || true
