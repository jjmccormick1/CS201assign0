// Jeremy McCormick
// sll.c
// CS201 Assignment 0


#include <stdio.h>
#include "sll.h"
#include "node.h"    
#include <assert.h>
#include <stdlib.h>
struct sll
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
void insertSLL(SLL *items,int index,void * value)
{
	NODE * newNode = newNODE(value,0);
    if (value !=  getNODEvalue(newNode))
        printf("Error! newNode value not equal to set value");
    
	setNODEnext(newNode,newNode); //set its next temp to the end for traversal purposes
    if(index == 0) //inserting at front
    {
        setNODEnext((NODE *)newNode, items->head); //set new Nodes next to current head
        items->head = (NODE *)newNode; //make newNode the new head
        
        if(items->size == 0)
            items->tail = (NODE *)newNode; //make newNode the tail if empty
        items->size += 1;
        
        return;
    }
    if(index == items->size) //Insert at end
    {
        setNODEnext(items->tail, (NODE *)newNode); //set current tails next to newnode
        items->tail = (NODE *)newNode; //make newNode the new tail
        if(items->size == 0)
            items->head=(NODE *)newNode; //if empty, make it head as well
        items->size += 1;
        return;
    }
    NODE * current  = (NODE *)newNODE(value,0);
    current = items->head; //Initialize a pointer for transversal of list. Visualize as splicing into
    current = (NODE *)getNODEnext(current);
    NODE * trailing = (NODE *)items->head;
    int i = 1; //set as 1 so current lags behind
    
    while(i < items->size)
    {
        if (i == index)
        {
            setNODEnext((NODE *)newNode,current); //set newNode to the current pointers  next
            setNODEnext(trailing,(NODE *)newNODE); //Set current nect to newNode
            items->size += 1;
            return;
        }
        current = getNODEnext(current);
        trailing = getNODEnext(trailing);
        i++;
    }
    return;
}

void * removeSLL(SLL *items,int index)
{
    NODE * current = items->head;
    int i = 0;
    while(current != 0 )
    {
        if((i) == index)
        {
            setNODEnext(current,getNODEnext(getNODEnext(current)));  
            //setNODEnext(current, getNODEnext(current->next));
            items->size-=1;
            return getNODEvalue(current);
        }
        current = getNODEnext(current);
        i++;
    }         
    return getNODEvalue(current);
}

void unionSLL(SLL *recipient,SLL *donor)
{
    setNODEnext(recipient->tail,donor->head);
    recipient->size += donor->size;
    //freeSLL(donor);
}
void *getSLL(SLL *items,int index)
{
    NODE * current = items->head;
    
    for(int i =0; i<items->size ; i++)
    {
        if(i == index && current != 0)
        {        
            return getNODEvalue(current);
        }
        current = getNODEnext(current);
        
    }
    return NULL;      
}
void *setSLL(SLL *items,int index,void *value)
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
    newNODE(value,current);
    return 0;      
}
int sizeSLL(SLL *items)
{
    return items->size;
}
void displaySLL(SLL *items,FILE *f)
{
    NODE * current = items->head;
    printf("Test: ");
    printf("{");
    for(int i =0; i < items->size ; i++)
    {
        void * val = getNODEvalue(current);
        items->display(val,f);
        current = getNODEnext(current);
    }
    printf("}");
}

void displaySLLdebug(SLL *items,FILE *file)
{
    NODE * current = items->head;
    printf("head->");
    
    printf("{");
    while(current != 0)
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


 
