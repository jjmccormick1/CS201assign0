// Jeremy McCormick
// sll.c
// CS201 Assignment 0


#include <stdio.h>
#include "sll.h"
#include "node.h"    
#include <assert.h>
typedef struct sll
{
    NODE *head;
    NODE *tail;
    int size;
    void (*display)(void *,FILE *);
    void (*free)(void *);
};

//d is the display function
//f is the freeing function
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
    NODE * newNode = newNODE(value,0);
    items->size++;
    if(items->size == 0)
    {
        items->head = newNode;
        items->tail = items->head;
        return;
    }
    if(index == items->size)
    {
        
        setNODEnext(items->tail,newNode);
        items->tail = newNode;
        return;
    }
    NODE * current = items->head;
    for(int i = 0;i<items->size; i++)
    {
        if(i == index)
        {
            NODE * temp = getNODEnext(current);            
            setNODEnext(current,newNode);
            setNODEnext(newNode,temp);
            return;
        }
        if(items->size>1)
            current = getNODEnext(current);
    }
}

void * removeSLL(SLL *items,int index)
{
    NODE * current = items->head;
    for(int i = 0;i<index; i++)
    {
        if((i+1) == index)
        {
            setNODEnext(current,getNODEnext(getNODEnext(current)));  
            //setNODEnext(current, getNODEnext(current->next));
            return getNODEvalue(current);
        }
        current = getNODEnext(current);
    }         
    return getNODEvalue(current);
}

void unionSLL(SLL *recipient,SLL *donor)
{
    setNODEnext(recipient->tail,donor->head);
    recipient->size += donor->size;
    freeSLL(donor);
}
void *getSLL(SLL *items,int index)
{
    NODE * current = items->head;
    for(int i = 0;i<=index; i++)
    {
        if((i+1) == index)
        {        
            return getNODEvalue(current);
        }
    }
    return NULL;      
}
void *setSLL(SLL *items,int index,void *value)
{
    NODE * current = items->head;
    for(int i = 0;i<=index; i++)
    {
        if((i+1) == index)
        {      
            setNODEvalue(current,value);
            return getNODEvalue(current);
        }
        current = getNODEnext(current);
    }
    newNODE(value,current);
    return 0;      
}
int sizeSLL(SLL *items)
{
    return items->size;
}
void displaySLL(SLL *items,FILE *file)
{
    NODE * current = items->head;
    printf("{");
    for(int i =1; i<items->size;i++)
    {
        items->display(getNODEvalue(current),file);
        current = getNODEnext(current);
    }
    printf("}");
}

void displaySLLdebug(SLL *items,FILE *file)
{
    NODE * current = items->head;
    printf("head->");
    
    printf("{");
    for(int i =1; i<(items->size-1);i++)
    {
        items->display(getNODEvalue(current),file);
        current = getNODEnext(current);
    }
    printf("}, tail->{");
    if(items->size>0)
        items->display(getNODEvalue(current),file);
    printf("}");
}
void freeSLL(SLL *items)
{
    NODE * current = items->head;
    for(int i =0; i<items->size;i++)
    {
        items->free(getNODEvalue(current));
        current = getNODEnext(current);
        free(current);
    }
    free(items);
    return;
}



 
