//multiq.h is the header file for multiq

#include "que.h"

#ifndef MULTIQ_H
#define MULTIQ_H

typedef int Boolean;
#define TRUE 1;
#define FALSE 0;

typedef int Priority;
typedef Element TaskID;

typedef struct Task
{
  TaskID tid;
  Priority p;
} Task;

typedef struct MultiQ
{
  int size;
  Queue *q;                     //this will point to a queue array
} MultiQ;


MultiQ createMQ (int num);      //adds t to the Queue corresponding priority in MQ

MultiQ addMQ (MultiQ mq, Task t);

Task nextMQ ();

Task delNextMQ (MultiQ mq);

Boolean isEmptyMQ (MultiQ mq);

int sizeMQ (MultiQ mq);
int sizeMQbyPriority (MultiQ mq, Priority p);
Queue getQueueFromMQ (MultiQ mq, Priority p);
#endif
