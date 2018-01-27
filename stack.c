 //Jeremy McCormick
 //stack.c
 //CS 201 Assignment 0

    #include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "dll.h"
#include "stack.h"

struct stack{
    DLL * dll;
};

STACK *newSTACK(void (*d)(void *,FILE *),void (*f)(void *))
{
    STACK * items = malloc(sizeof(STACK));
    stack->dll= newDLL(d,f);
    return items;
}

void push(STACK *items,void *value)
{
    insertDLL(items->dll, 0, value); //insert new item to front of DLL
}

void *pop(STACK *items)
{
    return removeDLL(items->dll, 0); //remove from front of DLL and return
}

void *peekSTACK(STACK *items)
{
    return getDLL(items->dll,0);
}

int sizeSTACK(STACK *items)
{
        return sizeDLL(items->dll);
}

void displaySTACK(STACK *items,FILE * fp)
{
        fprintf("|",fp);
        for(int i = 0; i < sizeDLL(items->dll) ; i++)
        {
            items->dll->display(getDLL(i), fp);
            fprintf(",",fp)
        }
        fprintf("|",fp);
            
}

void displaySTACKdebug(STACK *items,FILE * fp)
{
        displayDLLdebug(items->dll, fp);
}

void freeSTACK(STACK *items)
{
        freeDLL(items->dll);
        free(items);
}

