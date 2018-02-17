#include "merge_sort.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int
main ()
{
  int currentMaxSize = 2;
  int currentSize = 0;
  char name[20];
  Element *Ls = (Element *) malloc (currentMaxSize * sizeof (Element));
  float cgpa;

  FILE *fp = fopen ("1024000.txt", "r");
  while (fscanf
         (fp, "%m[^,]%*c%f\n", &Ls[currentSize].Name,
          &Ls[currentSize].CGPA) != EOF)
    {
      currentSize++;
      if (currentSize == currentMaxSize)
        {
          Ls =
            (Element *) realloc (Ls, (sizeof (Element) * currentMaxSize * 2));
          currentMaxSize *= 2;
          //printf("addr Ls %p\t\t| addr Ls[0].Name %p\n", Ls, Ls[0].Name);
        }
    }
  //printf ("Elements Before Sorting\n");
  //printElements (Ls, currentSize);
  mergeSort (Ls, 0, 1024000 - 1);
  //printf ("Elements After Sorting\n");
  //printElements (Ls, currentSize);
}
