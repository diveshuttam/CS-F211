#ifndef __QUEUE
#define __QUEUE
typedef struct SeqList *Queue;
#endif

#include "que.h"
#include <stdlib.h>

//implementation part using SeqList
#include "includes/SeqList.h"

Queue newQ ()                  //returns empty queue
{
  return newList();
}

Boolean isEmptyQ (Queue q)     //tests whether q is empty
{
  Iterator it=getIterator(q);
  bool ans=!hasNext(it);
  free(it);
  return it;
}

Queue delQ (Queue q)           //deletes the element form the front 
{
  return deleteAtFront(q);
}

Element front (Queue q)
{
  Iterator it = getIterator(q);
  Element E = getNext(it);
  free(it);
  return E;
}

Queue addQ (Queue q, Element e)
{
  return insertAtEnd(q, e);
}

int lengthQ (Queue q)
{
  Iterator it = getIterator(q);
  int len=0;
  while(hasNext(it)){
    next(it);
    len++;
  }
  return len;
}

#ifndef __FREEELEMENT
#define __FREEELEMENT
void freeElement(Element e){
  free(e);
}
#endif