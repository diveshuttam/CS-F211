#include "merge_sort.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

//compare is used for the sorting condition
int
compare (Element E1, Element E2)
{
  return E1.CGPA > E2.CGPA;
}


//merge is the function that implements merge operation
void
merge (Element Ls1[], int sz1, Element Ls2[], int sz2, Element Ls[])
{
  int p1 = 0;
  int p2 = 0;
  int p = 0;

  while (p1 < sz1 && p2 < sz2)
    {
      if (compare (Ls1[p1], Ls2[p2]))
        {
          Ls[p++] = Ls2[p2++];
        }
      else
        {
          Ls[p++] = Ls1[p1++];
        }
    }

  if (p1 < sz1)
    {
      while (p1 != sz1)
        {
          Ls[p++] = Ls1[p1++];
        }
    }
  else
    {
      while (p2 != sz2)
        {
          Ls[p++] = Ls2[p2++];
        }
    }
  return;
}

void
printElements (Element Ls[], int size)
{
  for (int i = 0; i < size; i++)
    {
      printf ("%s %f\n", Ls[i].Name, Ls[i].CGPA);
    }
}
