#include "merge_sort.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int
min (int a, int b)
{
  return (a < b) ? a : b;
}

void
swap (Element ** a, Element ** b)
{
  Element *temp = *a;
  *a = *b;
  *b = temp;
}

void
mergeSort (Element Ls1[], int start, int end)
{
  printf("in iterative");
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
