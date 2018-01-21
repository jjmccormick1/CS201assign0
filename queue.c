//Jeremy McCormick
// queue.c
// CS201 Assignment 0
#include "list.h"

void pushQueue(void * indata)
{
    Node newNode;
    newNode.data = indata;
    
    if(isEmpty())
    {
        head = &newNode;
        //current = &newNode
        end = &newNode;
    }
    newNode.next = head;
    head = &newNode;
    return;
}
void * popQueue()
{
    void * data = end->data;
    end = end->prev;
    return data;
}
    
