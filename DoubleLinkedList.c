//Jeremy McCormick
// DoubleLinkedList.c
// CS201 Assignment 0
typedef struct Node Node;

struct Node
{
    Node * next;
    Node * prev;
    void * data;
};

Node * head;
Node * current;
Node * end;

void * nextNode()
{
    current->prev = current;
    current = current->next;
    
    return current->data;
}

void addFront(void * indata)
{
    Node * newNode;
    newNode->data = indata;
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void addEnd(void * indata)
{
    Node * newNode;
    newNode->data = indata;
    newNode->prev = current;
    current->next = newNode;
}

