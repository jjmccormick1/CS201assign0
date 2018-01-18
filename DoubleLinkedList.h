//Jeremy McCormick
//DoubleLinkedList.h
// CS 201 Assignment 0

#ifndef SINGLELINKEDLIST_H
#define SINGLELINKEDLIST_H
typedef struct Node Node;
Node * head;
Node * current;
Node * end;

void * nextNodeDouble();
void addFrontDouble(void * data);
void addEndDouble(void * data);

#endif
