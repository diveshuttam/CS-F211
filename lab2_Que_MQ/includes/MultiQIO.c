#include "MultiQIO.h"
#include "SeqList.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int checkRedirect;
void
printElement (Element e)
{
  //printf ("Key:%d Next:%p\n", e->k->data, e->next);
  printf ("%d -> ", e->k->data);
}

void
printList (SeqList sl)
{
  Iterator it = getIterator (sl);
  if (!hasNext (it))
    {
      printf ("There are no element in the list\n");
      return;
    }
  printf ("Printing the list:\n");
  while (hasNext (it))
    {
      printElement (getNext (it));
      next (it);
    }
  printf ("NULL\n");
}

Key
askKey ()
{
  int data;
  fprintf (stderr, "Please enter the data value:");
  scanf ("%d", &data);
  Key k = malloc (sizeof (struct Key));
  k->data = data;
  return k;
}

Element
askElement ()
{
  Key K = askKey ();
  Element e = malloc (sizeof (struct Element));
  e->k = K;
  return e;
}

SeqList
randomElements (SeqList sl, int noOfElements,
                SeqList (*f) (SeqList sl, Element e))
{
  for (int i = 0; i < noOfElements; i++)
    {
      Element e = malloc (sizeof (struct Element));
      Key k = malloc (sizeof (struct Key));
      k->data = random () % 1000;
      e->k = k;
      sl = f (sl, e);
    }
  return sl;
}

/// THESES LINES ARE FOR CONVIENENENCE NOT RELATED TO THE SEQLIST
void
clrerr ()
{
  fprintf (stderr, "\033[2J\033[H");
}

void
setRedirection ()
{
  char link[256];
  ssize_t rval;
  rval = readlink ("/proc/self/fd/1", link, sizeof (link));
  link[rval] = '\0';

  char link1[256];
  rval = readlink ("/proc/self/fd/2", link1, sizeof (link1));
  link1[rval] = '\0';
  //printf("%s\n%s", link1, link);

  if (strcmp (link, link1) != 0)
    checkRedirect = 1;
  else
    checkRedirect = 0;
}

/// END OF EXTRA LINES
