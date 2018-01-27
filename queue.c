 //Jeremy McCormick
 //queue.c
 //CS 201 Assignment 0
 
#include <stdio.h>
#include <assert.h>
#include "sll.h"

struct queue {
    SLL * sll;
};

QUEUE *newQUEUE(void (*d)(void *,FILE *),void (*f)(void *))
{
    QUEUE * items = malloc(sizeof(QUEUE));
    items->sll = newSLL(d,f);
    return items;
}
void enqueue(QUEUE *items,void *value)
{
        insertSLL(items->sll, 0, value); //insert into sll at front
}

void *dequeue(QUEUE *items)
{
        return removeSLL(items->sll,sizeSLL(items->sll));
}

void *peekQUEUE(QUEUE *items)
{
        return getSLL(items->sll, sizeSLL(items->sll));
}
int sizeQUEUE(QUEUE *items)
{
    return sizeSLL(items->sll);
}

void displayQUEUE(QUEUE *items,FILE * fp)
{
    fprintf("<",fp);
        for(int i = 0; i < sizeSLL(items->sll) ; i++)
        {
            items->sll->display(getSLL(i), fp);
            fprintf(",",fp)
        }
        fprintf(">",fp);
}
void displayQUEUEdebug(QUEUE *items,FILE *)
{
    displaySLLdebug(items->sll)
}

void freeQUEUE(QUEUE *items)
{
    freeSLL(items->sll);
    free(items);
