#include "merge_sort.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int
min (int a, int b)
{
  return (a < b) ? a : b;
}

//recursive version of merge sort that calls itself as well as merge
void
mergeSort (Element Ls[], int start, int end)
{
  if (start == end)
    return;
  int mid = (start + end) / 2;
  mergeSort (Ls, start, mid);
  mergeSort (Ls, mid + 1, end);
  Element *New = (Element *) malloc (sizeof (Element) * (end - start + 1));
  merge (Ls + start, mid - start + 1, Ls + mid + 1, end - mid, New);
  memcpy (Ls + start, New, sizeof (Element) * (end - start + 1));
  free (New);
}
