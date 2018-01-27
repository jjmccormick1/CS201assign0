 
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
        items->size += 1;
        return;
    }
    if(index == items->size) //insert at tail
    {
        
        setNODEnext(items->tail,newNode);
        setNODEprev(newNode, items->tail);
        items->tail = newNode;
        items->size += 1;
        return;
    }
    NODE *trailing = items->head;
    NODE * current = items->head;
    current = getNODEnext(current);
    items->size += 1;
    for(int i = 1;i<items->size;i++)
    {
        if(i == index)
        {         
            setNODEnext(trailing,newNode);
            setNODEprev(newNode,trailing);
            setNODEnext(newNode,current);
            setNODEprev(current, newNode);
            return;
        }
        current = getNODEnext(current);
        trailing = getNODEnext(trailing);
    }
    
    return;       

}

void *removeDLL(DLL *items,int index)
{
 
    if(index == 0) //remove at front
    {
        void * val = getNODEvalue(items->head);
        items->head = getNODEnext(items->head);
        items->size -= 1;
        return val;
    }
    
    else
    {
        NODE * current = items->head; //Make a couple temp
        NODE * trailing = items->head;//pointers for insertion
        current = getNODEnext(current);//get current one step ahead
        
        for(int i = 1; i < items->size; i++) //dont start at front so current lags by one
        {
            if(i == index)
            {
                    void * val = getNODEvalue(current);
                    setNODEnext(trailing,getNODEnext(current));
                    setNODEprev(getNODEnext(current), trailing);
                    
                    items->size -= 1;
                    return val;
            }
            current = getNODEnext(current); //set both to next
            trailing = getNODEnext(trailing);
                
        }
    }
    
    return NULL;       
}

void unionDLL(DLL *recipient,DLL *donor)
{
    setNODEnext(recipient->tail,donor->head);
    setNODEprev(donor->head, recipient->tail);
    recipient->tail = donor->tail;
    recipient->size += donor->size;
}
void *getDLL(DLL *items,int index)
{
    NODE * current = items->head;
    for(int i = 0;i<=index; i++)
    {
        if((i) == index)
        {        
            return getNODEvalue(current);
        }
        current = getNODEnext(current);
    }
    return NULL;      
}
void *setDLL(DLL *items,int index,void *value)
{
    NODE * current = items->head;
    for(int i = 0;i<=index; i++)
    {
        if((i) == index)
        {      
            setNODEvalue(current,value);
            return getNODEvalue(current);
        }
        current = getNODEnext(current);
    }

     return NULL;     
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
        current = getNODEnext(current);
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
        if(items->size > 0)
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