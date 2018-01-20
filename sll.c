// Jeremy McCormick
// sll.c
// CS201 Assignment 0
#include <assert.h>
#include <stdio.h>
#include "sll.h"
#include "node.h"    

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
    if(items->size == 0)
    {
        items->head = newNode;
        items->tail = items->head;
        items->size++;
        return;
    }
    if(index == items->size)
    {
        
        setNODEnext(items->tail,newNode);
        items->tail = newNode;
        return;
    }
    NODE * current = items->head;
    for(int i = 0;i<=index; i++)
    {
        if(i == index)
        {
            NODE * temp = getNODEnext(current);            
            setNODEnext(current,newNode);
            setNODEnext(newNode,temp);
            return;
        }
        current = getNODEnext(current);
    }
    return;       

}

void *removeSLL(SLL *items,int index)
{
    NODE * current = items->head;
    for(int i = 0;i<=index; i++)
    {
        if((i+1) == index)
        {
            setNODEnext(current,getNODEnext(getNODEnext(current)));  
            //setNODEnext(current, getNODEnext(current->next));
            return;
        }
    }
    return;          
}

void unionSLL(SLL *recipient,SLL *donor)
{
    setNODEnext(recipient->tail,donor->head);
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
    return;      
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
    printf("\n\n{");
    for(int i = 0; i<items->size; i++)
    {
        items->display(getNODEvalue(current),file);
    }
    printf("{\n\n");
}

void displaySLLdebug(SLL *items,FILE *file)
{
    
}
void freeSLL(SLL *items)
{
    NODE * current = items->head;
    for(int i = 0; i<items->size; i++)
    {
        items->free(getNODEvalue(current));
    }
    return;
}



 
