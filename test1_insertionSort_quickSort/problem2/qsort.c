#include "qsort.h"

void
printArray (int *studArray, int arrSize)
{
  // printing the array
  int i = 0;
  for (i = 0; i < arrSize; i++)
    {
      printf ("Arr[%d] is %d\n", i, studArray[i]);
    }
}


int *
readData (char *fileName)
{
  FILE *f = fopen (fileName, "r");
  fscanf (f, "%d", &size);
  int *Arr = (int *) malloc (sizeof (int) * size);
  char *s;
  for (int i = 0; i < size; i++)
    {
      fscanf (f, "%ms %d", &s, &Arr[i]);
      free (s);
    }
  return Arr;
}


//returning temp values for compiling and running
KeyStruct
extractKeys (int *Ls, int lsSize, int loKey, int hiKey)
{
  KeyStruct k = (KeyStruct) malloc (sizeof (struct keyStruct));
  int *isThere = (int *) malloc (sizeof (int) * (hiKey - loKey + 1));

  k->Keys = malloc (sizeof (int) * (size));
  k->keysSize = 0;
  int i, j;
  for (i = 0, j = 0,)

    return k;
}

int
part2Loc (int *Ls, int lo, int hi, int piv)
{
  return 0;
}

void
quickSortKnownKeyRange (int *Ls, int size, int loKey, int hiKey)
{
  return;
}
