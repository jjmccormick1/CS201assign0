// Jeremy McCormick
// sll.c
// CS201 Assignment 0

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
    NODE * newNode = newNODE(value,0)
    if(size == 0)
    {
        items->head = newNode;
        items->tail = head;
        items->size++;
        return;
    }
    if(index == size)
    {
        items->tail->next = newNode;
        items->tail = newNode;
        return;
    }
    NODE * current = head;
    for(int i = 0;i<=index; i++)
    {
        if(i == index)
        {
            NODE * temp = current->next;            
            current->next = newNode;
            newNode->next = temp;
            return
        }
    }
    return;       

}

void *removeSLL(SLL *items,int index);
void unionSLL(SLL *recipient,SLL *donor);
void *getSLL(SLL *items,int index);
void *setSLL(SLL *items,int index,void *value);
int sizeSLL(SLL *items);
void displaySLL(SLL *items,FILE *);
void displaySLLdebug(SLL *items,FILE *);
void freeSLL(SLL *items);

    #endif
 
