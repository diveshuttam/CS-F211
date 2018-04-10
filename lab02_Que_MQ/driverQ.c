#include<stdio.h>
#include<stdlib.h>
#include "que.h"
#include<signal.h>

Queue q;

//handling the signals for clearing and exit
void
sigint_handler (int dummy)
{
  printf ("\nYou chose to exit!\n");
  exit (0);
}

void
sigquit_handler (int dummy)
{
  printf ("\nClearing the queue now\n");
  int i;
  int n=lengthQ(q);
  printf ("List has been cleared\n");
}
//end of signal handling


int
main ()
{
  //handle ctrl+c in driver itself
  signal (SIGQUIT, sigquit_handler);
  signal (SIGINT, sigint_handler);
  Queue q = newQ ();
  do
    {
      printf ("\n-----------------------------------\n\
      Main Menu\n\
      1. isEmpty\n\
      2. delQ\n\
      3. frontQ\n\
      4. addQ\n\
      5. lengthQ\n\
      6. printQ\n\
      [Ctrl+\\ to clear the list, Ctrl+C to exit (asynchronously)]\n\
-----------------------------------\n");
      int choice;
      scanf ("%d", &choice);
      switch (choice)
        {
        case 1:
          if (isEmptyQ ())
            printf ("queue is empty\n");
          else
            printf ("queue is not empty\n");
          break;
        case 2:
          q = delQ (q);
          printf ("deleted\n");
          break;
        case 3:
          Element e = frontQ (q);
          printf ("front of the queue is\n");
          print (e);
          break;
        case 4:
          int data;
          printf ("please enter the data you want in your ele\n");
          scanf ("%d", &data);
          Element e;
          e.data.key = data;
          q = addQ (q, e);
          printf ("added\n");
          break;
        case 5:
          printf ("length of the queue is\n", lengthQ (q));
        }
      while (choice <= 5 && choice >= 0);
    }
  }
