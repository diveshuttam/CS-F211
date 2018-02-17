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

int
min (int a, int b)
{
  return (a < b) ? a : b;
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


//recursive version of merge sort that calls itself as well as merge
void
mergeSortRecursive (Element Ls[], int start, int end)
{
  if (start == end)
    return;
  int mid = (start + end) / 2;
  mergeSortRecursive (Ls, start, mid);
  mergeSortRecursive (Ls, mid + 1, end);
  Element *New = (Element *) malloc (sizeof (Element) * (end - start + 1));
  merge (Ls + start, mid - start + 1, Ls + mid + 1, end - mid, New);
  memcpy (Ls + start, New, sizeof (Element) * (end - start + 1));
  free (New);
}


//print the entire array
void
printElements (Element Ls[], int size)
{
  for (int i = 0; i < size; i++)
    {
      printf ("%s %f\n", Ls[i].Name, Ls[i].CGPA);
    }
}

void
swap (Element ** a, Element ** b)
{
  Element *temp = *a;
  *a = *b;
  *b = temp;
}

void
mergeSortIterative (Element Ls1[], int start, int end)
{
  int size = end - start + 1;
  int arr_size = 1;
  Element *Ls2 = (Element *) malloc (sizeof (Element) * size);
  Element *currentMainArr = Ls1, *currentNewArr = Ls2;
  for (arr_size = 1; arr_size < size; arr_size *= 2)
    {
      int arr1 = 0;
      int arr2 = arr_size;
      while (arr2 <= end)
        {
          fflush (stdout);
          merge (currentMainArr + arr1, arr_size, currentMainArr + arr2,
                 min (arr_size, end - arr2 + 1), currentNewArr + arr1);
          arr1 += 2 * arr_size;
          arr2 += 2 * arr_size;
        }
      swap (&currentMainArr, &currentNewArr);
    }
  //copy new back into the original array
  if (currentMainArr != Ls1)
    {
      memcpy (Ls1, currentMainArr, sizeof (Element) * size);
    }
}
