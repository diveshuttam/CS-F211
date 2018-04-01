#include "SeqListIO.h"
#include "SeqList.h"
#include <stdio.h>
#include <stdlib.h>

void
printElement (Element e)
{
  //printf ("Key:%d Next:%p\n", e->k->data, e->next);
  printf ("%d -> ", e->k->data);
}

void
printList (SeqList sl)
{
  Element ptr = sl->front;
  if (ptr == NULL)
    {
      printf ("There are no element in the list\n");
      return;
    }
  printf ("Printing the list:\n");
  while (ptr != NULL)
    {
      printElement (ptr);
      ptr = ptr->next;
    }
  printf("NULL\n");
}

Key
askKey ()
{
  int data;
  fprintf (stderr,"Please enter the data value:");
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
  e->next = NULL;
  return e;
}
