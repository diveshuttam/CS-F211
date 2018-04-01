#include "SeqList.h"
#include "SeqListUses.h"
#include "SeqListIO.h"
#include <stdio.h>
int
main ()
{
  SeqList sl1 = newList ();
  SeqList sl2 = newList ();
  SeqList sl = newList ();
  int i;
  printf ("enter elements for sl1\n");
  for (i = 1; i <= 5; i++)
    {
      printf ("enter element i=%d\n", i);
      Element E = askElement ();
      sl1 = insertAtEnd (sl1, E);
    }
  printf ("Enter elements for sl2\n");
  for (i = 1; i <= 5; i++)
    {
      printf ("enter element i=%d\n", i);
      Element E = askElement ();
      sl2 = insertAtEnd (sl2, E);
    }

  printf ("SL1 is\n");
  printList (sl1);
  printf ("calling insertion sort on list1\n");
  sl1 = insertionSort (sl1);
  printf ("SL1 is\n");
  printList (sl1);

  printf ("SL2 is\n");
  printList (sl2);
  printf ("calling insertion sort on list2\n");
  sl2 = insertionSort (sl2);
  printf ("SL2 is\n");
  printList (sl2);

  printf ("calling merge on lists sl1 and sl2\n");
  sl = merge (sl1, sl2);
  printf ("printing sl after merging\n");
  printList (sl);
}
