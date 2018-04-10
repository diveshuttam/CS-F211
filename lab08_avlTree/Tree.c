#include "Tree.h"
#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>
#include"includes/Stack.h"
#include"includes/TreeIO.h"

struct Tree
{
  value val;
  Tree right;
  Tree left;
  int balance:2;
};

Tree
newNode (value val)
{
  Tree n = malloc (sizeof (struct Tree));
  n->val = val;
  n->left = NULL;
  n->right = NULL;
  n->balance = 0;
  return n;
}

void
inOrder (Tree root, void (*f) (Tree)){
  if (f == NULL)
    f = printTree;
  if (root == NULL)
    return;
  inOrder (root->left, f);
  f (root);
  inOrder (root->right, f);
}

void
preOrder (Tree root, void (*f) (Tree))
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
postOrder (Tree root, void (*f) (Tree))
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
match (Tree root, int val)
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

PATH traverse (Tree root, enum TRAV_RET (*f) (Tree, ...), ...);
{
  if (f == NULL)
    f = match;
  if (root == NULL)
    return NULL;
  if (f (Tree) == RIGHT)
    Tree (N)}

    Tree add (Tree root, Tree val)
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
/*ot != NULL)
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
