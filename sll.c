//Jeremy McCormick
//sll.c 
//CS201 assignment 0

#include <stdlib.h>
#include <assert.h>
#include "node.h"

struct sll
{
    NODE * head;
    NODE * tail;
    int size;
    void (*display)(void *, FILE *);
    void (*free)(void *);
};

SLL *newSLL(void (*d)(void *,FILE *),void (*f)(void *))
{
        SLL *items = malloc(sizeof(SLL));
        assert(items != 0);
        items->head = 0;
        items->tail = 0;
        items->size = 0;
        items->display = d;
        items->free = f;
        return items;
}
void insertSLL(SLL *items,int index,void *value)
{
    NODE * newNode = newNODE(value, NULL); //Create new node with passed value
    items->size += 1;
    if(index == 0) //Insert at front
    {
        setNODEnext(newNode,items->head); //set new nodes next to current head
        items->head = newNode; //make new node the head
    }
    
    else if( index == items->size) //insert at end
    {
        setNODEnext(items->tail,newNode); //set tails next to new node
        items->tail = newNode; //make new node the tail
    }
    
    else
    {
        for(int i = 0; i < items->size; i++)
        {
            if(i == index)
                
        }
    }
}
extern void *removeSLL(SLL *items,int index);
extern void unionSLL(SLL *recipient,SLL *donor);
extern void *getSLL(SLL *items,int index);
extern void *setSLL(SLL *items,int index,void *value);
extern int sizeSLL(SLL *items);
extern void displaySLL(SLL *items,FILE *);
extern void displaySLLdebug(SLL *items,FILE *);
extern void freeSLL(SLL *items);
