//Jeremy McCormick
// stack.c
// CS201 Assignment 0

#include "sll.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

    typedef struct stack
    {
    	SLL * sll;
    }STACK;

extern STACK *newSTACK(void (*d)(void *,FILE *),void (*f)(void *))
{
	STACK *items = malloc(sizeof(STACK));
	assert(items!=0);
	items->sll = newSLL(d,f);
	return items;
}
extern void push(STACK *items,void *value)
{
	insertSLL(items->sll,sizeSTACK(),value);
}
extern void *pop(STACK *items)
{
	return removeSLL(items,sizeSTACK());
}
extern void *peekSTACK(STACK *items)
{
	return getSLL(items->sll);
}
extern int sizeSTACK(STACK *items)
{
	return sizeSLL(items->sll);
}
extern void displaySTACK(STACK *items,FILE *)
{
	displaySLL(items->sll);
}
extern void displaySTACKdebug(STACK *items,FILE *)
{
	displaySLLdebug(items->sll);
}
extern void freeSTACK(STACK *items)
{
	freeSLL(items->sll);
	free(items);
}
