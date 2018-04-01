#include "SeqListUses.h"
#include <stdlib.h>
#include "SeqList.h"

SeqList
merge (SeqList sl1, SeqList sl2)
{
  SeqList sl = newList ();
  while (sl1->front != NULL || sl2->front != NULL)
    {
      if (sl1->front != NULL
          && (sl2->front == NULL
              || compare ((sl1->front)->k, (sl2->front)->k) == LESSTHAN))
        {
          sl = insertAtEnd (sl, (sl1->front));
          sl1 = deleteAtFront (sl1);
        }
      else
        {
          sl = insertAtEnd (sl, (sl2->front));
          sl2 = deleteAtFront (sl2);
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
      sl1 = deleteAtFront (sl1);
      sl = insertInOrder (sl, E);
    }
  return sl;
}
