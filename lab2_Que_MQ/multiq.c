#ifndef __MULTIQ
#define __MULTIQ
typedef struct MultiQ
{
  Queue * ques;
  int size;
} *MultiQ;
#endif


#include "multiq.h"
#include <stdlib.h>

void freeElement(Element e)
{
  Task t=e;
  freeElement(t);
}

MultiQ
createMQ (int num)
{
  MultiQ mq=malloc(sizeof(MultiQ));
  if(num>0){
    Queue q = newQ();
    mq->ques=malloc(sizeof(q)*num);
    mq->ques[0]=q;
    for(int i=1;i<num;i++){
      Queue q = newQ();
      mq->ques[i]=q;
    }
    mq->size = num;
    return mq;
  }
}


MultiQ
addMQ (MultiQ mq, Task t)
{
  Queue *ques = mq->ques;
  ques[t->p] = addQ (ques[t->p],t);
  return mq;
}


//considering 0 as the highest priority
Task
nextMQ (MultiQ mq)
{
  int maxPriority = mq->size - 1;
  for (int i = 0; i <= maxPriority; i++)
    {
      if (!isEmptyQ (mq->ques[i]))
        return front(mq->ques[i]);
    }
  return NULL;
}

MultiQ
delNextMQ (MultiQ mq)
{
  int maxPriority = mq->size - 1;
  for (int i = 0; i <= maxPriority; i++)
    {
      if (!isEmptyQ (mq->ques[i]))
        mq->ques[i] = delQ (mq->ques[i]);
    }
  return mq;
}

Boolean
isEmptyMQ (MultiQ mq)
{
  Boolean Empty = true;
  for (int i = 0; i < mq->size; i++)
    {
      if (!isEmpty (mq->ques[i]))
        {
          Empty = false;
          break;
        }
    }
  return Empty;
};


int
sizeMQ (MultiQ mq)
{
  int size = 0;
  for (int i = 0; i < mq->size; i++)
    {
      size += sizeQ (mq->ques[i]);
    }
  return size;
}

int
sizeMQbyPriority (MultiQ mq, Priority p)
{
  return sizeQ (mq->ques[p]);
}

Queue
getQueueFromMQ (MultiQ mq, Priority p)
{
  return mq->ques[p];
}

#ifndef __FREETASK
#define __FREETASK
void freeTask(Task t){
  free (t);
}
#endif