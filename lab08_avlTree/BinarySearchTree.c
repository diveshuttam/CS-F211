#include "BinarySearchTree.h"
#include "BinaryTree.h"

//for stack my element is a tree node
#define Element BinarySearchTree
#include "includes/Stack.h"
#undef Element

#include<stdarg.h> // for variable arguments

//greater than right
//lessthan Equal to left

typedef struct Stack *PathStack;

#ifndef __COMPARE
#define __COMPARE
COMP_RET compare(key k1, key k2)
{
	if(k1<k2)
		return LESSTHAN;
	else if(k1>k2)
		return GREATERTHAN;
	else
		return EQUALTO;
}
#endif

TRAV_RET tcompare(Element E, Element E1)
{
	if(compare(E->k,E1->k)==EQUALTO)
		return RETURN;
	else if(compare(E1->k, E->k)==GREATERTHAN)
		return LEFT;
	else
		return RIGHT;
}

PathStack traveseStack(bst, TRAV_RET (*tcompare) (Element E, void * args), void *args1)
{
	PathStack p=newStack();
	TRAV_RET ret;
	BinarySearchTree cur=bst;
	while(!isEmpty(cur))
	{
		p=push(p,cur);
		ret=tcompare(getRoot(cur),args1);
		if(ret==RIGHT)
			cur=getRight(curr);
		else if(ret==LEFT)
			cur=cur->left;
		else if(ret==RETURN)
			break;
		else
			break;
	}
	return PATH;
}

Element find(BinarySearchTree bst, Key k)
{
  //empty case
  if(isEmpty(bst))
    return NULL;//NOT_FOUND
  Element r=getRoot(bst);  
  //base case (root)
  if(compare(r->key,k)==EQUALTO)
    return r;
  //case right
  else if(compare(k, r->key)==GREATERTHAN)
    return find(getRight(bst), k);
  //case left
  else
    return find(getLeft(bst), k);
}

//if the key is already there then update
BinarySearchTree add(BinarySearchTree bst, Element e)
{
  //case empty
  if(isEmpty(bst))
  	return setRoot(bst,e);
  
  Element r=getRoot(bst);
  
  //case equal --> update
  if(compare(e->key,r->key)==EQUALTO)
  		return setRoot(bst,e);
  //case right
  else if(compare(e->key,r->key)==GREATERTHAN)
      return add(getRight(bst),e);
  //case left
  else
  		return add(getLeft(bst), e);
}


//free is a necessity
BinarySearchTree delete(BinarySearchTree bst, key k)
{
	PathStack p=traverseStack(bst, tcompare, E);
	
	while(pop(p))
	//case empty
	if(isEmpty(bst))
	 return bst;
	
	//case leaf
	if(isEmpty(getRight(bst)) && isEmpty(getLeft(bst)))
		//set parent's pointer to null
	
	//case half empty
	if(isEmpty(getRight(bst) || isEmpty(getLeft(bst))))
		//override parent's right/left with my non empty child
	
	//other cases
	else
		//replace the by successor and other stuff
		//do a traverse with stack
		E=getElement(k);
		
	
}