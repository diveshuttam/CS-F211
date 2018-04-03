//multiq.h is the header file for multiq
#ifndef MULTIQ_H
#define MULTIQ_H

#ifndef __ELEMENT
#define __ELEMENT
typedef struct Task *Element;
#endif

#ifndef __KEY
#define __KEY
typedef TaskID Key;
#endif

#include "que.h"
#include<stdbool.h>

typedef bool Boolean;

#ifndef __PRIORITY
#define __PRIORITY
typedef int Priority;
#endif

#ifndef __TASKID
#define __TASKID
typedef int TaskID;
#endif

#ifndef __TASK
#define __TASK
typedef struct Task
{
  TaskID tid;
  Priority p;
} *Task;
#endif

#ifndef __MULTIQ
#define __MULTIQ
typedef struct MultiQ *MultiQ;
#endif


MultiQ createMQ (int num);     //creates a list of num Queues, each of which is empty 
MultiQ addMQ (MultiQ mq, Task t); //adds t to the Queue corresponding to priority p in mq.
Task nextMQ (); //returns the front of the non-empty Queue in mq with the highest priority.
MultiQ delNextMQ (MultiQ mq); //deletes the front of the non-empty Queue in mq with the highest priority; returns modified MultiQ
Boolean isEmptyMQ (MultiQ mq);//tests whether all the queues in MultiQ are empty
int sizeMQ (MultiQ mq); // returns total number of items in MultiQ
int sizeMQbyPriority (MultiQ mq, Priority p); // returns the number of items in mq with the priority p;
Queue getQueueFromMQ (MultiQ mq, Priority p);// returns the queue with the priority p
int getPriority(Priority p);//return a priority within [0,num). This allows me to have non integer priorities also, user just has to update this function; 
void freeTask(Task T);
#endif