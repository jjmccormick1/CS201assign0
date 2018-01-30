CC=gcc
CFLAGS=  -Wall -Wextra -c -ggdb -pedantic -std=c99 -D_XOPEN_SOURCE=600 -O0
LFLAGS=  -Wall -Wextra -pedantic  -std=c99 -ggdb
COREOBJS=  sll.o dll.o stack.o queue.o

all:	
	@$(CC) $(CFLAGS) sll.c sll.h 
	@$(CC) $(CFLAGS) dll.c dll.h 
	@$(CC) $(CFLAGS) stack.c stack.h 
	@$(CC) $(CFLAGS) queue.c queue.h

lib: all
	@ar rc liblistlib.a $(COREOBJS)
	@ranlib liblistlib.a
	@echo "Static Library Created.\n"
	
string: 
	@$(CC) $(CFLAGS) string.c string.h
	
integer.o:
	@$(CC) $(CFLAGS) integer.c integer.h
	
test-sll: all integer.o 
	@$(CC) $(CFLAGS)  sll-0-0.c 
	@$(CC) $(LFLAGS)  sll.o sll-0-0.o integer.o -o test-sll

	
test-dll: all integer.o 
	@$(CC) $(CFLAGS)  dll-0-0.c
	@$(CC) $(LFLAGS)  dll.o dll-0-0.o integer.o -o test-dll
	
test-stack: all integer.o
	@$(CC) $(CFLAGS)  stack-0-0.c
	@$(CC) $(LFLAGS)  dll.o stack.o stack-0-0.o integer.o -o test-stack
	
test-queue: all integer.o
	@$(CC) $(CFLAGS)  queue-0-0.c
	@$(CC) $(LFLAGS)  sll.o queue.o queue-0-0.o integer.o -o test-queue

test: clean test-dll test-sll test-stack test-queue
	@echo "Testing SLL .. \n"
	@./test-sll
	@echo "Testing DLL .. \n"
	@./test-dll
	@echo "Testing Stack .. \n"
	@./test-stack
	@echo "Testing Queue .. \n"
	@./test-queue

valgrind:
	@valgrind ./test-sll --leak-check=full
	@valgrind ./test-dll --leak-check=full
	@valgrind ./test-stack --leak-check=full
	@valgrind ./test-queue --leak-check=full
	
clean:
	@rm -f *.o || true
	@rm -f *.a || true
	@rm -f *.gch || true
	@rm -f test-sll
	@rm -f test-dll
	@rm -f test-stack
	@rm -f test-queue
	@rm -f nodetest
	@rm -f test-integer
