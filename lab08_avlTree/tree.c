#include "tree.h"
#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>
#include"Stack.h"

void
printNode (NODE root)
{
  if (root != NULL)
    printf ("%d\n", root->val);
}

NODE
newNode (value val)
{
  NODE n = malloc (sizeof (struct node));
  n->val = val;
  n->left = NULL;
  n->right = NULL;
  n->balance = 0;
  return n;
}

void
inOrder (NODE root, void (*f) (NODE))
{
  if (f == NULL)
    f = printNode;
  if (root == NULL)
    return;
  inOrder (root->left, f);
  f (root);
  inOrder (root->right, f);
}

void
preOrder (NODE root, void (*f) (NODE))
{
  if (f == NULL)
    f = printNode;
  if (root == NULL)
    return;
  f (root);
  preOrder (root->right, f);
  preOrder (root->left, f);
}

void
postOrder (NODE root, void (*f) (NODE))
{
  if (f == NULL)
    f == printNode;
  if (root == NULL)
    return;
  postOrder (root->right, f);
  postOrder (root->left, f);
  f (root);
}

enum TRAV_RET
match (NODE root, int val)
{
  if (root == NULL)
    return RETURN;
  if (val > root->val)
    return RIGHT;
  if (val < root->val)
    return LEFT;
}

//traverse traverses a path in the tree and maintains stack according to
//given function condition i.e if f returns RIGHT then traverse right
//if f returns LEFT then traverse left
//if f returns RETURN return the pointer to PATH stack
//default function is match

PATH traverse (NODE root, enum TRAV_RET (*f) (NODE, ...), ...);
{
  if (f == NULL)
    f = match;
  if (root == NULL)
    return NULL;
  if (f (NODE) == RIGHT)
    NODE (N)}

    NODE add (NODE root, NODE val)
    {
      if (root == NULL)
        return newNode (val);

      if (val < root->val)      //insert in left
        {
          if ((x = add (root->left)) == NULL)
            {
              return NULL;
            }
          else
            {
              root->left = root;
              root->balance -= 1;
            }
        }

      if (val > t->root->val)   //insert in right
        {
          if ((x = add (root = root->right)) == NULL)
            {
              return NULL;
            }
          else
            {
              root->right = root;
              root->balance += 1;
            }
        }
      else
        {
          //already exists don't insert
          return NULL;
        }
      return root;
    }

  NODE find (TREE t, value val)
  {
    while (t->root != NULL)
      {
        if (val < t->root->val)
          t->root = t->root->left;
        else if (val > t->root->val)
          t->root = t->root->right;
        else
          return t->root;
      }
    return NULL;                //not found
  }

/*TREE
delete (TREE t, value val)
{
  if
}*/
