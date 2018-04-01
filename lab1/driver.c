//the main function for the SeqList program is contained in this file
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>
#include "SeqListIO.h"
#include "SeqList.h"
#include<stdio.h>
#include<string.h>
SeqList sl;


/// THESES LINES ARE FOR CONVIENENENCE NOT RELATED TO THE SEQLIST
int checkRedirect;
void
clrerr(){
  fprintf (stderr,"\033[2J\033[H");
}

void setRedirection(){
    char link[256];
    ssize_t rval;
    rval = readlink("/proc/self/fd/1", link, sizeof(link));
    link[rval] = '\0';

    char link1[256];
    rval = readlink("/proc/self/fd/2", link1, sizeof(link1));
    link1[rval] = '\0';
    //printf("%s\n%s", link1, link);

    if (strcmp(link, link1)!=0) {
      checkRedirect=1;
    } else {
      checkRedirect=0;
    }
}

void
sigint_handler (int dummy)
{
  printf ("\nYou chose to exit!\n");
  exit (0);
}

void
sigquit_handler (int dummy)
{
  printf ("\nClearing the SeqList now\n");
  sl = clearList (sl);
  printf ("List has been cleared\n");
}
/// END OF EXTRA LINES

SeqList randomElements(SeqList sl, int noOfElements, SeqList (*f)(SeqList sl, Element e)){
  for(int i=0;i<noOfElements;i++){
    Element e=malloc(sizeof(struct Element));
    Key k=malloc(sizeof(struct Key));
    k->data=random()%1000;
    e->k=k;
    sl=f(sl,e);
  }
  return sl;
}

int
main ()
{
  //handle ctrl+c in driver itself
  signal (SIGQUIT, sigquit_handler);
  signal (SIGINT, sigint_handler);
  int choice;
  sl = newList ();
  setRedirection();
  do
    {
      if(checkRedirect)
        clrerr();
      fprintf (stderr,"\n-----------------------------------\n\
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
          if(e !=NULL)
          {
            printf("Element found\n");
            printElement (e);
          }
          else
            printf("Element was not found in the list");
          break;
        case 7:
          fprintf(stderr, "enter the no of elements to insert");
          scanf("%d", &noOfElements);
          printf("inserting elements\n");
          sl=randomElements(sl,noOfElements,insertInOrder);
          printf("Done");
          break;
        case 8:
          fprintf(stderr, "enter the no of elements to insert");
          scanf("%d", &noOfElements);
          printf("inserting elements\n");
          sl=randomElements(sl,noOfElements,insertAtFront);
          printf("Done");
          break;
        case 9:
          fprintf(stderr,"enter the no of elements to insert");
          scanf("%d", &noOfElements);
          printf("inserting elements\n");
          sl=randomElements(sl,noOfElements,insertAtEnd);
          printf("Done");
          break;
        default:
          fprintf (stderr,"invalid choice");
        }
    }
  while (1);
  return 0;
}
