 //Jeremy McCormick
 //queue.c
 //CS 201 Assignment 0
 

#include <assert.h>
#include <stdlib.h>
#include "sll.h"
#include "queue.h"

struct queue {
    SLL * sll;
    void (*display)(void *, FILE *);
    void (*free)(void *);
};

QUEUE *newQUEUE(void (*d)(void *,FILE *),void (*f)(void *))
{
    QUEUE * items = malloc(sizeof(QUEUE));
    items->sll = newSLL(d,f);
    items->display = d;
    items->free = f;
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
    printf("<");
        for(int i = 0; i < sizeSLL(items->sll) ; i++)
        {
            items->display(getSLL(items->sll, i), fp);
            printf(",");
        }
        printf(">");
}
void displayQUEUEdebug(QUEUE *items,FILE * fp)
{
    displaySLLdebug(items->sll, fp);
}

void freeQUEUE(QUEUE *items)
{
    freeSLL(items->sll);
    free(items);
}
