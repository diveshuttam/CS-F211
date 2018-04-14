#include "BinarySearchTree.h"
#include "BinaryTree.h"

#define __STACKELEMENT
typedef BinarySearchTree StackElement;
#include "includes/Stack.h"
#include <stdlib.h>

//greater than right
//LESSTHAN to left

typedef struct Stack *PathStack;

#ifndef __COMPARE
#define __COMPARE
COMP_RET compare(Key k1, Key k2)
{
	if(k1<k2)
		return LESSTHAN;
	else if(k1>k2)
		return GREATERTHAN;
	else
		return EQUALTO;
}
#endif

PathStack traverseStack(BinarySearchTree bst, Key k)
{
	PathStack p=newStack();
	COMP_RET ret;
	BinarySearchTree cur=bst;
	while(!isEmpty(cur))
	{
		p=push(p,cur);
		ret=compare(k,getRoot(cur)->k);
		if(ret==GREATERTHAN)
			cur=getRight(cur);
		else if(ret==LESSTHAN)
			cur=getLeft(cur);
		else if(ret==EQUALTO)
			break;
	}
	if(ret!=EQUALTO)
	  return NULL;
	else
	  return p;
}

Element find(BinarySearchTree bst, Key k)
{
  //empty case
  if(isEmpty(bst))
    return NULL;//NOT_FOUND
  Element r=getRoot(bst);  
  //base case (root)
  if(compare(r->k,k)==EQUALTO)
    return r;
  //case right
  else if(compare(k, r->k)==GREATERTHAN)
    return find(getRight(bst), k);
  //case left
  else
    return find(getLeft(bst), k);
}

//if the Key is already there then update
BinarySearchTree add(BinarySearchTree bst, Element e)
{
  //case empty
  if(isEmpty(bst))
  	return mkBTNode(e);
  
  Element r=getRoot(bst);
  
  //case equal --> update
  if(compare(e->k,r->k)==EQUALTO)
  		return setRoot(bst,e);
  //case right
  else if(compare(e->k,r->k)==GREATERTHAN)
      return setRight(bst,add(getRight(bst),e));
  //case left
  else
  		return setLeft(bst, add(getLeft(bst), e));
}

//returns successor
PathStack inOrderSuccessor(BinarySearchTree bst,Key k)
{
  PathStack p=traverseStack(bst, k);
	BinarySearchTree E,E1,cur,curparent;
	E=top(p);
	
  //if has a right sub tree, then go left left
  if(!isEmpty(getRight(E)))
  {
    cur=getRight(E);
    while(!isEmpty(cur))
    {
      p=push(p,cur);
      cur=getLeft(cur);
    }
		return p;
  }
  //find the first parent who has this as a left subtree
  else
  {
    cur=top(p);
    p=pop(p);
    curparent=top(p);
    while(curparent!=NULL)//stack is not empty
    {
      if(getLeft(curparent)==cur)
        break;
      cur=top(p);
      p=pop(p);
      curparent=top(p);
    }
    if(curparent==NULL)
      return NULL;
    else
			return p;
	}
}

BinarySearchTree delete(BinarySearchTree bst, Key k)
{
	PathStack p=traverseStack(bst, k);
	BinarySearchTree E;
	
	if(p!=NULL){//path is not empty	i.e element is found
	  E=top(p);
	  
	  //swap if none of the child is empty
	  if(!isEmpty(getRight(E)) && !isEmpty(getLeft(E)))
	  {
	    PathStack pios=inOrderSuccessor(bst,k);
	    //swap successor and self
	    Element a=getRoot(top(p));
	    setRoot(top(p),getRoot(top(pios)));
	    setRoot(top(pios),a);
	    //change p to pios	
	    p=pios;
	  }
		E=top(p);
  
    //deletes actually here
	  //right is empty
	  if(isEmpty(getRight(E)))
	  {
	    p=pop(p);
			if(top(p)==NULL)
			{
				return getLeft(E);
			}
	    BinarySearchTree parent=top(p);
	    if(E==getRight(parent))
	    {
	      setRight(parent,getLeft(E));
	    }
	    else
	    {
	      setLeft(parent,getLeft(E));
	    }
	  }
	  //left is empty
	  else if(isEmpty(getLeft(E)))
	  {
		  //override parent's right/left with my non empty child
		  p=pop(p);
			if(top(p)==NULL)
				return getRight(E);
	    BinarySearchTree parent=top(p);
	    if(E==getRight(parent))
	    {
	      setRight(parent,getRight(E));
	    }
	    else
	    {
	      setLeft(parent,getRight(E));
	    }
	  }
	}
	return bst;
}
