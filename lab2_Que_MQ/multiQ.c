#include "mulitq.h"

MultiQ
createMQ (int num)
{
  MultiQ mq;
  Queue *q = (Queue) malloc (sizeof (Queue q) * num);
  mq.q = q;
  mq.size = num;
  return mq;
}


MultiQ
addMQ (MultiQ mq, Task t)
{
  Queue *tempq = mq.q;
  Element e = newElement (t);
  tempq[t.p] = tempq[t.p].addQ (e);
}


//considering 0 as the highest priority
Task
nextMQ (MultiQ mq)
{
  int maxPriority = mq.size - 1;
  for (int i = 0; i <= maxPriority; i++)
    {
      if (isEmptyQ (mq.q[i]) == false)
        return (Task)
        {
        mq.q[i].front (), i};
    }
}

MultiQ
delNextMQ (MultiQ mq)
{
  int maxPriority = mq.size - 1;
  for (int i = 0; i <= maxPriority; i++)
    {
      if (!isEmptyQ (mq.q[i]))
        mq.q[i] = delQ (mq.q[i]);
    }
  return mq;
}

Boolean
isEmptyMQ (MultiQ mq)
{
  Boolean Empty = TRUE;
  for (int i = 0; i < mq.size; i++)
    {
      if (!isEmpty (mq.q[i]))
        {
          Empty = FALSE;
          break;
        }
    }
  return Empty;
};


int
sizeMQ (MultiQ mq)
{
  int size = 0;
  for (int i = 0; i < N; i++)
    {
      size += sizeQ (mq.q[i]);
    }
  return size;
}

int
sizeMQbyPriority (MultiQ mq, Priority p)
{
  return sizeQ (mq.q[p]);
}

Queue
getQueueFromMQ (MultiQ mq, Priority p)
{
  return mq.q[p];
}
