#ifndef __BINARYTREE_H
#define __BINARYTREE_H

#ifndef __VALUE
#define __VALUE
typedef int value;
#endif

#ifndef __TREE
#define __TREE
typedef struct BinaryTree *BinaryTree;
#endif

#ifndef __ELEMENT
#define __ELEMENT
typedef struct Element{
    Value val;
}*Element;
#endif

//functions declaration start here
BinaryTree createTree ();
BinaryTree isEmpty (BinaryTree t);
BinaryTree mkBTNode(Element e);
Element getRoot(BinaryTree t);
BinaryTree setRoot(BinaryTree bt, Element e);
BinaryTree getLeft(BinaryTree bt);
BinaryTree getRight(BinaryTree bt);
BinaryTree setLeft(BinartTree bt, BinaryTree lt);
BinaryTree setRight(BinartTree bt, BinaryTree rt);
BinaryTree compose(Element root, BinaryTree lt, BinaryTree right);
#endif