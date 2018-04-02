//the main function for the SeqList program is contained in this file
#include <signal.h>
#include <stdlib.h>
#include "SeqListIO.h"
#include "SeqList.h"
#include<stdio.h>

SeqList sl;

//handling the signals for clearing and exit
void
sigint_handler (int dummy)
{
  printf ("\nYou chose to exit!\n");
  printf ("\nClearing the list first\n");
  sl = clearList (sl);
  printf ("Bye!");
  exit (0);
}

void
sigquit_handler (int dummy)
{
  printf ("\nClearing the SeqList now\n");
  sl = clearList (sl);
  printf ("List has been cleared\n");
}

//end of signal handling

int
main ()
{
  //handle ctrl+c in driver itself
  signal (SIGQUIT, sigquit_handler);
  signal (SIGINT, sigint_handler);
  int choice;
  sl = newList ();
  //printning menu to stderr as well as the input statements
  //printing ouput of the functions to stdout
  setRedirection ();
  do
    {
      if (checkRedirect)
        clrerr ();
      fprintf (stderr, "\n-----------------------------------\n\
Main Menu:\n\
 0.printlist()\n\
 1.insertInOrder()\n\
 2.insertAtFront()\n\
 3.insertAtEnd()\n\
 4.delete()\n\
 5.deleteAtFront()\n\
 6.find()\n\
 7.randomInsertInOrder()\n\
 8.randomInsertAtFront()\n\
 9.randomInsertAtEnd()\n\
Please enter a choice[0-9]\n\
[Ctrl+\\ to clear the list, Ctrl+C to exit (asynchronously)]\n\
-----------------------------------\n");

      scanf ("%d", &choice);
      Key k;
      Element e;
      int noOfElements;
      switch (choice)
        {
        case 0:
          printList (sl);
          break;
        case 1:
          e = askElement ();
          sl = insertInOrder (sl, e);
          break;
        case 2:
          e = askElement ();
          sl = insertAtFront (sl, e);
          break;
        case 3:
          e = askElement ();
          sl = insertAtEnd (sl, e);
          break;
        case 4:
          e = askElement ();
          sl = delete (sl, e);
          break;
        case 5:
          sl = deleteAtFront (sl);
          break;
        case 6:
          k = askKey ();
          e = find (sl, k);
          if (e != NULL)
            {
              printf ("Element found\n");
              printElement (e);
            }
          else
            printf ("Element was not found in the list");
          break;
        case 7:
          fprintf (stderr, "enter the no of elements to insert");
          scanf ("%d", &noOfElements);
          printf ("inserting elements\n");
          sl = randomElements (sl, noOfElements, insertInOrder);
          printf ("Done");
          break;
        case 8:
          fprintf (stderr, "enter the no of elements to insert");
          scanf ("%d", &noOfElements);
          printf ("inserting elements\n");
          sl = randomElements (sl, noOfElements, insertAtFront);
          printf ("Done");
          break;
        case 9:
          fprintf (stderr, "enter the no of elements to insert");
          scanf ("%d", &noOfElements);
          printf ("inserting elements\n");
          sl = randomElements (sl, noOfElements, insertAtEnd);
          printf ("Done");
          break;
        default:
          fprintf (stderr, "invalid choice");
        }
    }
  while (1);
  return 0;
}
