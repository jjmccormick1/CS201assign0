// Jeremy McCormick
// SingleLinkedList.h
// CS201 Assignment 0

#ifndef SINGLELINKEDLIST_H
#define SINGLELINKEDLIST_H
struct NodeTag;
typedef struct NodeTag Node;

Node * head;
Node * current;
Node * end;

void * nextNode();
void addFront(void * data);
void addEnd(void * data);

#endif
