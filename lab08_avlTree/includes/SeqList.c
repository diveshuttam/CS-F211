#include "SeqList.h"
#include <stdio.h>
#include <stdlib.h>

//TODO: use this later
//Free other unused memory like the Iterators
#ifndef __FREEELEMENT
#define __FREEELEMENT
void
freeElement (SeqListElement e)
{
  free (e->k);
  free (e);
}
#endif

typedef struct Node
{
  SeqListElement e;
  struct Node *next;
} *Node;

typedef struct SeqList
{
  Node front;
  Node rear;
} *SeqList;

typedef struct Iterator
{
  Node previous;
  Node current;
} *Iterator;

Iterator
getIterator (SeqList sl)
{
  Iterator it = malloc (sizeof (struct Iterator));
  it->previous = NULL;
  it->current = sl->front;
  return it;
}

SeqListElement
getNext (Iterator it)
{
  if (it->current != NULL)
    {
      SeqListElement e = it->current->e;
      return e;
    }
  else
    return NULL;
}

Iterator
next (Iterator it)
{
  if (it->current != NULL)
    {
      it->previous = it->current;
      it->current = it->current->next;
    }
  return it;
}

bool
hasNext (Iterator it)
{
  if (it->current != NULL)
    {
      return true;
    }
  else
    {
      return false;
    }
}

SeqList
insertBefore (SeqList sl, Iterator it, SeqListElement E)
{
  Node n = malloc (sizeof (struct Node));
  n->e = E;

  n->next = it->current;

  if (it->previous != NULL)
    it->previous->next = n;
  else                          //insert at front
    sl->front = n;
  it->previous = n;             //n will become previous node now

  if (n->next == NULL)          //insert at End
    sl->rear = n;
  return sl;
}

SeqList
deleteAfter (SeqList sl, Iterator it)
{
  Node temp;
  if (it == NULL)               //DELETE at front
    {
      it = getIterator (sl);
      temp = sl->front;
      if (temp == NULL)
        return sl;
      it->current = NULL;
      it->previous = NULL;
    }
  else
    {
      if (it->current == NULL || it->current->next == NULL)     //end of list
        return sl;
      temp = it->current->next;
      it->current->next = it->current->next->next;
    }
  if (temp == sl->front)        //if front node was deleted
    sl->front = temp->next;
  if (temp == sl->rear)         //if last node was deleted
    sl->rear = it->current;
  free (temp);
  return sl;
}

//compare function may be changed by the user
#ifndef __COMPARE
#define __COMPARE
//compare first is less than second
int
compare (Key k1, Key k2)
{
  if (k1->data < k2->data)
    return LESSTHAN;
  if (k1->data > k2->data)
    return GREATERTHAN;
  if (k1->data == k2->data)
    return EQUALTO;
}
#endif

SeqList
newList ()
{
  SeqList sl = malloc (sizeof (struct SeqList));
  sl->front = NULL;
  sl->rear = NULL;
  return sl;
}

SeqList
clearList (SeqList sl)
{
  Iterator it = getIterator (sl);
  while (hasNext (it))
    {
      it = next (it);
      sl = deleteAtFront (sl);
    }
  return sl;
}


SeqList
insertInOrder (SeqList sl, SeqListElement e)
{
  //case NULL and case before front
  Iterator it = getIterator (sl);
  if (!hasNext (it) || compare (e->k, getNext (it)->k) == LESSTHAN)
    {
      return insertAtFront (sl, e);
    }
  else
    {
      //rest cases
      Iterator it = getIterator (sl);
      //move the pointer to the location before which to insert
      while (hasNext (it) && (compare (e->k, getNext (it)->k) == GREATERTHAN))
        it = next (it);
      sl = insertBefore (sl, it, e);
      return sl;
    }
}

SeqList
insertAtFront (SeqList sl, SeqListElement e)
{
  Iterator it = getIterator (sl);
  sl = insertBefore (sl, it, e);
}

SeqList
insertAtEnd (SeqList sl, SeqListElement e)
{
  Iterator it = getIterator (sl);
  while (hasNext (it))
    {
      it = next (it);
    }
  insertBefore (sl, it, e);
  return sl;
}

SeqList
SeqList_delete (SeqList sl, SeqListElement e)
{
  Iterator it = getIterator (sl);
  //case null
  if (!hasNext (it))
    return sl;

  //case front
  while (compare (getNext (it)->k, e->k) == EQUALTO)
    {
      it = next (it);
      deleteAtFront (sl);
    }

  //rest cases
  {
    //it2 is being deleted
    //it2 is just after it1 (1 ahead) 
    Iterator it1 = getIterator (sl);
    Iterator it2 = next (getIterator (sl));
    while (hasNext (it2))
      {
        if (compare (getNext (it2)->k, e->k) == EQUALTO)
          {
            sl = deleteAfter (sl, it1);
          }
        it1 = next (it1);
        it2 = next (it2);
      }
  }
  return sl;
}

SeqList
deleteAtFront (SeqList sl)
{
  sl = deleteAfter (sl, NULL);
}
/*
Element
find (SeqList sl, Key k)
{
  Iterator it = getIterator (sl);
  while (hasNext (it))
    {
      Element e = getNext (it);
      if (compare (e->k, k) == EQUALTO)
        return e;
      it = next (it);
    }
  //not found return null
  return NULL;
}
*/