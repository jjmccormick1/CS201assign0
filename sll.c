//Jeremy McCormick
//sll.c 
//CS201 assignment 0

#include <stdlib.h>
#include <assert.h>
#include "node.h"
#include "sll.h"

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
        if(items->size == 1)
            items->head = newNode;
    }
    
    else if( index == items->size) //insert at end
    {
        setNODEnext(items->tail,newNode); //set tails next to new node
        items->tail = newNode; //make new node the tail
    }
    
    else
    {
        NODE * current = items->head; //Make a couple temp
        NODE * trailing = items->head;//pointers for insertion
        current = getNODEnext(current);//get current one step ahead
        
        for(int i = 1; i < items->size; i++)
        {
            if(i == index)
            {
                    setNODEnext(trailing,newNode);
                    setNODEnext(newNode, current);
                    return;
            }
            current = getNODEnext(current); //set both to next
            trailing = getNODEnext(trailing);
                
        }
    }
    return;
}
void * removeSLL(SLL *items,int index)
{
    items->size -= 1;
    if(index == 0) //remove at front
    {
        items->head = getNODEnext(items->head);
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
                    return val;
            }
            current = getNODEnext(current); //set both to next
            trailing = getNODEnext(trailing);
                
        }
    }
    return NULL;
}

void unionSLL(SLL *recipient,SLL *donor)
{
    setNODEnext(recipient->tail,donor->head);
    recipient->tail = donor->tail;
    recipient->size += donor->size;
    return;
}

void *getSLL(SLL *items,int index)
{
    
        NODE * current = items->head; //Make a couple temp
        for(int i = 0; i < items->size; i++)
        {
            if(i == index)
            {
                return getNODEvalue(current);
            }
            current = getNODEnext(current); //set both to next
                
        }
        return;
}

void setSLL(SLL *items,int index,void *value)
{
        NODE * current = items->head; //Make a couple temp
        for(int i = 0; i < items->size; i++)
        {
            if(i == index)
            {
                setNODEvalue(current,value);
                return;
            }
            current = getNODEnext(current); //set both to next
                
        }
        return;
}
int sizeSLL(SLL *items)
{
    return items->size;
}

void displaySLL(SLL *items,FILE * fp)
{
    NODE * current = items->head;
    printf("{");
    for(int i = 0; i < items->size; i++)
    {
            items->display(getNODEvalue(current), fp);
            current = getNODEnext(current);
    }
    printf("}\n");
    return;
    
}
void displaySLLdebug(SLL *items,FILE * fp)
{
    NODE * current = items->head;
    printf("head->{"); 
    for(int i = 0; i < items->size -1 ; i++)
    {
            items->display(getNODEvalue(current), fp);
    }
    printf("}, tail->{");
    items->display(getNODEvalue(items->tail),fp);
    printf("}\n");
    return;
}
void freeSLL(SLL *items)
{
    
    NODE * current = items->head;
    for(int i = 0; i < items->size; i++)
    {
            NODE * temp = getNODEnext(current);
            items->free(current);
            current = temp;
    }
    free(items);
    return;
}
