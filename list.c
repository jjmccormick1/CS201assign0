//Jeremy McCormick
// SingleLinkedList.c
// CS201 Assignment 0

typedef struct Node Node;

struct Node
{
    Node * next;
    Node * prev;
    void * data;
};

Node * head = 0;
Node * current;
Node * end;

int isEmpty()
{
    if(head == 0)
        return 1;
    return 0;
}
