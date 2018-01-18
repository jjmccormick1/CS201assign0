//Jeremy McCormick
// stack.c
// CS201 Assignment 0
#include "list.h"

void pushStack(void * indata)
{
    Node newNode;
    newNode.data = indata;
    
    if(isEmpty())
    {
        head = &newNode;
        current = &newNode;
    }
    newNode.next = current;
    current = &newNode;
}
void * popStack()
{
    void * data = current->data;
    current = current->next;
}
    
