#include "SeqListUses.h"
#include <stdlib.h>
#include "SeqList.h"

SeqList
merge (SeqList sl1, SeqList sl2)
{
  SeqList sl = newList ();
  Element E;
  while (sl1->front != NULL || sl2->front != NULL)
    {
      if (sl1->front != NULL
          && (sl2->front == NULL
              || compare (sl1->front->k, sl2->front->k) == LESSTHAN))
        {
          E=sl1->front;
          sl1->front=sl1->front->next;
          sl = insertAtEnd (sl, E);
        }
      else
        {
          E=sl2->front;
          sl2->front=sl2->front->next;
          sl = insertAtEnd (sl, E);
        }
    }
  return sl;
}

SeqList
insertionSort (SeqList sl1)
{
  SeqList sl = newList ();
  Element E;
  while (sl1->front != NULL)
    {
      E = (sl1->front);
      sl1->front=sl1->front->next;
      sl = insertInOrder (sl, E);
    }
  return sl;
}
