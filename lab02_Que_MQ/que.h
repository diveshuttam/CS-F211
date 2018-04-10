//this is the header file for the queue implementation
#ifndef __QUE_H
#define __QUE_H
#include <stdbool.h>

typedef bool Boolean;

#ifndef __KEY
#define __KEY
typedef int Key;
#endif


#ifndef __ELEMENT 
#define __ELEMENT
typedef struct Element
{
  Key k;
} *Element;
#endif


#ifndef __QUEUE
#define __QUEUE
typedef struct Queue *Queue;
#endif


Queue newQ ();                  //returns empty queue
Boolean isEmptyQ (Queue q);     //tests whether q is empty
Queue delQ (Queue q);           //deletes the element from the front 
Element front (Queue q);
Queue addQ (Queue q, Element e);
int lengthQ (Queue q);

//override free element if you define your own Element structure
//override this by defining __FREEELEMENT while compiling que.c
//this is called by delelte etc. to free the element else can lead to memory leaks
void freeElement(Element e);
#endif