#ifndef __BST_H
#define __BST_H

#ifndef __VALUE
#define __VALUE
typedef int value;
#endif

#ifndef __ELEMENT
#define __ELEMENT
typedef struct Element{
    value val;
}*Element;
#endif

typedef struct BinaryTree *BinarySearchTree;

enum COMP_RET
{ LESSTHAN, GREATERTHAN, EQUALTO };

BinarySearchTree add (BinarySearchTree root, BinarySearchTree val);
BinarySearchTree find (BinarySearchTree root, BinarySearchTree val);
BinarySearchTree delete (BinarySearchTree root, BinarySearchTree val);
void compare (value val1, value val2);
#endif