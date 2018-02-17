//this is the header file for the queue implementation
#ifndef QUE_H
#define QUE_H

typedef int Boolean;
#define TRUE 1;
#define FALSE 0;

typedef int Data;

typedef struct Element
{
  Data d;
  Element *next;
} Element;


typedef struct Queue
{
  Element *front;
  Element *last;
} Queue;


Queue newQ ();                  //returns empty queue
Boolean isEmptyQ (Queue q);     //tests whether q is empty
Queue delQ (Queue q);           //deletes the element form the front 
Element front (Queue q);
Queue addQ (Queue q, Element e);
int lengthQ (Queue q);
#endif
