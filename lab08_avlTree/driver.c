#include<stdio.h>
#include"tree.h"
#include<stdlib.h>
#include<includes/TreeIO.h>

NODE
populateTree (NODE root)
{
  int i = 0;
  int max = 100000;

  while (i < max)
    {
      i++;
      root = add (root, 150 + (random () % 21));
    }
  return root;
}

int
main ()
{
  NODE root = NULL;
  int ch, val;
  do
    {
      printf ("Main Menu\n"
              "1. ADD a NODE\n"
              "2. Print tree\n"
              "3. find a node\n"
              "4. populate tree with random [150-170]\n"
              "Enter your choice:\t");
      scanf ("%d", &ch);
      switch (ch)
        {
        case 1:
          printf ("Enter the value:");
          scanf ("%d", &val);
          root = add (root, val);
          break;
        case 2:
          printTree (root);
          break;
        case 3:
          printf ("Enter the value:");
          scanf ("%d", &val);
          if (find (root, val) != NULL)
            printf ("value found\n");
          else
            printf ("value not found\n");
          break;
        case 4:
          //add 10000 random no. between 150 and 170
          root = populateTree (root);
          break;
        default:
          exit (0);
        }
    }
  while (1);
}