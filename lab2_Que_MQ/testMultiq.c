#include<stdio.h>
#include<stdlib.h>
#include "multiq.h"
#include<sys/time.h>

typedef FILE *File;

MultiQ
testDel (int num)
{

}

MultiQ
loadData (File f)
{
  char buff[255];
  int taskid, priority;
  MultiQ mq = newMQ (10);
  while (fscanf (f, "%d,%d", &taskid, &priority))
    {
      Task t = (Task){taskid, priority};
      mq = insert (mq, t);
    }
  return mq;
}

int
main ()
{
  MultiQ mq;
  File f = fopen;
  mq = loadData ("100.txt");
  mq = testDel (10);
}
