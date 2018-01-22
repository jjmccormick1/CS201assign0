
CC=gcc
CFLAGS=  -Wall -Wextra -c -ggdb -pedantic -std=c99 -O0
LFLAGS=  -Wall -Wextra -pedantic  -std=c99 -ggdb
COREOBJS= node.o sll.o dll.o

all:	lib

lib:	
	@$(CC) $(CFLAGS) node.c node.h sll.c sll.h dll.c dll.h
	@ar rc liblistlib.a $(COREOBJS)
	@ranlib liblistlib.a

	
string: 
	@$(CC) $(CFLAGS) string.c string.h

test-sll.o:
	@$(CC) $(CFLAGS)  test-sll.c 
	
test-sll: all integer.o test-sll.o
	@$(CC) $(LFLAGS) test-sll.o integer.o -L. -llistlib -o test-sll

test-dll.o: 
	@$(CC) $(CFLAGS)  test-dll.c
	
test-dll: all integer.o test-dll.o
	@$(CC) $(LFLAGS) test-dll.o integer.o -L. -llistlib -o test-dll

test: clean test-dll test-sll
	@echo "Testing SLL .. \n"
	@./test-sll
	@echo "Testing DLL .. \n"
	@./test-dll
clean:
	@rm -f *.o || true
	@rm -f *.a || true
