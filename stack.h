//Jeremy McCormick
// stack.h
// CS201 Assignment 0


#ifndef __STACK_H__
    #define __STACK_H__

    typedef struct stack STACK;

    extern STACK *newSTACK(void (*d)(void *,FILE *),void (*f)(void *));
    extern void push(STACK *items,void *value);
    extern void *pop(STACK *items);
    extern void *peekSTACK(STACK *items);
    extern int sizeSTACK(STACK *items);
    extern void displaySTACK(STACK *items,FILE *);
    extern void displaySTACKdebug(STACK *items,FILE *);
    extern void freeSTACK(STACK *items);

    #endif
