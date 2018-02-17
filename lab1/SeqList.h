//author: Divesh Uttamchandani
//2016A7PS0045P

#ifndef _SEQLIST_H
#define _SEQLIST_H

#define GREATERTHAN 1
#define LESSTHAN -1
#define EQUAL 0

typedef int bool;

typedef struct Key{
  int data;
} Key;

typedef struct Element{
  Key k;
  struct Element *next;
} Element;

typedef struct SeqList{
  Element *front;
  Element *rear;
} SeqList;


SeqList newList();
bool compare(Element e1, Element e2);
SeqList clearList(SeqList sl);
SeqList insertInOrder(SeqList sl, Element e);
SeqList insertAtFront(SeqList sl, Element e);
SeqList insertAtEnd(SeqList sl, Element e);
SeqList delete(SeqList sl, Element e);
SeqList deleteAtFront(SeqList sl);
Element *find(SeqList sl, Key k);
Key askKey();
Element askElement();
void printElement(Element e);
void printList(SeqList sl);
#endif
