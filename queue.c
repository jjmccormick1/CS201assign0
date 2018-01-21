//Jeremy McCormick
// queue.c
// CS201 Assignment 0

#include <stdio.h>
#include "dll.h"

typedef struct queue
{
	DLL *dll;

}QUEUE;

QUEUE *newQUEUE(void (*d)(void *,FILE *),void (*f)(void *))
{
	QUEUE *items = malloc(sizeof(QUEUE));
	assert(items!=0);
	items->dll = newDLL(d,f);
	return items;
}

void enqueue(QUEUE *items,void *value)
{
	insertDLL(items->dll,0,value);
}

void *dequeue(QUEUE *items);
{
	return removeDLL(items->dll, sizeDLL(items->dll));
}

void *peekQUEUE(QUEUE *items);
{
	return getDLL(items->dll, sizeDLL(items->dll));
}

int sizeQUEUE(QUEUE *items);
{
	sizeDLL(items->dll)l
}
void displayQUEUE(QUEUE *items,FILE *);
{
	displayDLL(items->dll);
}
void displayQUEUEdebug(QUEUE *items,FILE *);
{
	displayDLLdebug(items->dll);
}
void freeQUEUE(QUEUE *items);
{
	freeDLL(items->dll);
	free(items);
}
