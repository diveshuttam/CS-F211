#include "SeqListUses.h"
#include <stdlib.h>
#include "SeqList.h"

SeqList
merge (SeqList sl1, SeqList sl2)
{
  SeqList sl = newList ();
  Element E;
  Iterator it1=getIterator(sl1);
  Iterator it2=getIterator(sl2);
  Element e1, e2;
  e1=getNext(it1);
  e2=getNext(it2);
  while (hasNext(it1) || hasNext(it2))
    {
      Element elementToInsert = NULL;
      if(e1==NULL)  
        elementToInsert = e2;
      else if(e2 ==NULL)
        elementToInsert = e1;
      else if(compare(e2->k, e1->k)==LESSTHAN)
        elementToInsert = e2;
      else
        elementToInsert = e1;
      insertAtEnd(sl, elementToInsert);
      if(elementToInsert==e1)
        {
          it1=next(it1);
          e1=getNext(it1);
        }
      else
      {
        it2=next(it2);
        e2=getNext(it2);
      }
    }
  return sl;
}

SeqList
insertionSort (SeqList sl1)
{
  SeqList sl = newList ();
  Element E;
  Iterator it = getIterator(sl1);
  while (hasNext(it))
    {
      E = getNext(it);
      sl = insertInOrder (sl, E);
      it=next(it);
    }
  return sl;
}
