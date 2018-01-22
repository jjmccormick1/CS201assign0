 
// Jeremy McCormick
// dll.c
// CS201 Assignment 0
#include <stdio.h>
#include "dll.h"
#include "node.h"    
#include <assert.h>
#include <stdlib.h>

struct dll
{
    NODE *head;
    NODE *tail;
    int size;
    void (*display)(void *,FILE *);
    void (*free)(void *);
};

//d is the display function
//f is the freeing function
DLL *newDLL(void (*d)(void *,FILE *),void (*f)(void *))
{
    DLL *items = malloc(sizeof(DLL));
        assert(items != 0);
        items->head = 0;
        items->tail = 0;
        items->size = 0;
        items->display = d;
        items->free = f;
        return items;
}
void insertDLL(DLL *items,int index,void *value)
{
    NODE * newNode = newNODE(value,0);
    //setNODEnext(newNode,newNode); //set new now next to itself
    if(items->size == 0)
    {
        items->head = newNode;
        items->tail = items->head;
        items->size++;
        return;
    }
    if(index == items->size) //insert at tail
    {
        
        setNODEnext(items->tail,newNode);
        setNODEprev(newNode, items->tail);
        items->tail = newNode;
        return;
    }
    NODE * current = items->head;
    for(int i = 1;i<index;i++)
    {
        if(i == index)
        {
            NODE * currentNext = getNODEnext(current);           
            setNODEnext(current,newNode);
            setNODEprev(newNode,current);
            setNODEnext(newNode,currentNext);
            setNODEprev(currentNext, newNode);
            return;
        }
        current = getNODEnext(current);
    }
    return;       

}

void *removeDLL(DLL *items,int index)
{
    NODE * current = items->head;
    items->size--;
    for(int i = 0;i<=index; i++)
    {
        if((i+1) == index)
        {
            void * tmp = getNODEvalue(current);
            setNODEnext(current,getNODEnext(getNODEnext(current)));  
            setNODEprev( getNODEnext(current),current);
            return tmp;
        }
        current= getNODEnext(current);
    }
    return getNODEvalue(items->head);          
}

void unionDLL(DLL *recipient,DLL *donor)
{
    setNODEnext(recipient->tail,donor->head);
}
void *getDLL(DLL *items,int index)
{
    NODE * current = items->head;
    for(int i = 0;i<=index; i++)
    {
        if((i+1) == index)
        {        
            return getNODEvalue(current);
        }
    }
    return getNODEvalue(items->head);      
}
void *setDLL(DLL *items,int index,void *value)
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
     return getNODEvalue(items->head);     
}
int sizeDLL(DLL *items)
{
    return items->size;
}
void displayDLL(DLL *items,FILE *file)
{
    NODE * current = items->head;
    printf("{");
    for(int i = 0; i<items->size; i++)
    {
        items->display(getNODEvalue(current),file);
    }
    printf("}");
}

void displayDLLdebug(DLL *items,FILE *file)
{
	NODE * current = items->head;
	    printf("{");
	    for(int i = 0; i<items->size-1; i++)
	    {
	    	void * tmp = getNODEvalue(current);
	        items->display(tmp,file);
	        current = getNODEnext(current);
	    }
	    printf("}, tail->{");
	    items->display(getNODEvalue(current),file);
	    printf("};");
}
void freeDLL(DLL *items)
{
    NODE * current = items->head;
    for(int i = 1; i<items->size; i++)
    {
        items->free(getNODEvalue(current));
        current = getNODEnext(current);
    }
    free(items);
    return;
}



 
