//Jeremy McCormick
// SingleLinkedList.c
// CS201 Assignment 0

typedef struct Node Node;

struct Node
{
    Node * next;
    void * data;
};

Node * head;
Node * current;
Node * end;

void * nextNode()
{
    current = current->next;
    return current->data;
}

void addFront(void * data)
{
    Node newNode;
    newNode.data = data;
    newNode.next = head;
    head = &newNode;
}

void addEnd(void * data)
{
    Node  newNode;
    newNode.data = data;
    current.next = &newNode;
}
int main ()
{}
