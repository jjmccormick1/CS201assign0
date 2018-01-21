//Jeremy McCormick
// queue.h
// CS201 Assignment 0

#ifndef __QUEUE_INCLUDED__
#define __QUEUE_INCLUDED__

typedef struct queue QUEUE;

extern QUEUE *newQUEUE(void (*d)(void *,FILE *),void (*f)(void *));
extern void enqueue(QUEUE *items,void *value);
extern void *dequeue(QUEUE *items);
extern void *peekQUEUE(QUEUE *items);
extern int sizeQUEUE(QUEUE *items);
extern void displayQUEUE(QUEUE *items,FILE *);
extern void displayQUEUEdebug(QUEUE *items,FILE *);
extern void freeQUEUE(QUEUE *items);

    #endif
