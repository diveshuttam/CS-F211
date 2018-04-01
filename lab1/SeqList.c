#include "SeqList.h"
#include<stdio.h>
#include<stdlib.h>

//compare function may be changed by the user
#ifndef __COMPARE
#define __COMPARE
//compare first is less than second
bool
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
  while (sl->front != NULL)
    {
      sl = deleteAtFront (sl);
    }
  return sl;
}


SeqList
insertInOrder (SeqList sl, Element e)
{
  //case NULL and case before front
  if (sl->front == NULL || compare (e->k, sl->front->k) == LESSTHAN)
    {
      return insertAtFront (sl, e);
    }
  else
    {
      //rest cases
      Element ptr = sl->front;
      //move the pointer to the location after which to insert
      while (ptr->next != NULL
             && (compare ((ptr->next)->k, e->k) == LESSTHAN
                 || compare ((ptr->next)->k, e->k) == EQUALTO))
        {
          ptr = ptr->next;
        }
      Element e1 = malloc (sizeof (struct Element));
      e1->k = e->k;
      e1->next = ptr->next;
      ptr->next = e1;

      //update sl if inserting at end
      if (e1->next == NULL)
        {
          sl->rear = e1;
        }
      return sl;
    }
}

SeqList
insertAtFront (SeqList sl, Element e)
{
  Element e1 = malloc (sizeof (e));
  e1->next = NULL;
  e1->k = e->k;
  //case list is NULL
  if (sl->rear == NULL)
    {
      sl->rear = sl->front = e1;
    }
  else
    {
      e1->next = sl->front;
      sl->front = e1;
    }
  return sl;
}

SeqList
insertAtEnd (SeqList sl, Element e)
{
  Element e1 = e;
  e1->next = NULL;
  //case list is NULL
  if (sl->rear == NULL)
    {
      sl->rear = sl->front = e1;
    }
  //rest cases
  else
    {
      sl->rear->next = e1;
      sl->rear = e1;
    }
  return sl;
}

SeqList
delete (SeqList sl, Element e)
{
  //case null
  if (sl->rear == NULL)
    return sl;

  //case front
  if (compare (sl->front->k, e->k) == EQUALTO)
    {
      return deleteAtFront (sl);
    }

  //rest cases
  else
    {
      Element ptr = sl->front;
      Element ptr1 = NULL;
      while (ptr->next != NULL)
        {
          if (compare (ptr->next->k, e->k) == EQUALTO)
            {
              ptr1 = ptr->next;
              ptr->next = ptr1->next;
              free (ptr1);
              if (ptr->next == NULL)
                sl->rear = ptr;
              break;
            }
          ptr = ptr->next;
        }
    }
  return sl;
}

SeqList
deleteAtFront (SeqList sl)
{
  //case NULL
  if (sl->front == NULL)
    {
      return sl;
    }
  //case only one element
  if (sl->front == sl->rear)
    {
      free (sl->front);
      sl->front = sl->rear = NULL;
      return sl;
    }

  else
    {
      Element ptr = sl->front;
      sl->front = sl->front->next;
      free (ptr);
      return sl;
    }
}

Element
find (SeqList sl, Key k)
{
  Element ptr = sl->front;
  while (ptr != NULL)
    {
      if (compare (ptr->k, k) == EQUALTO)
        return ptr;
      ptr = ptr->next;
    }
  //not found return null
  return NULL;
}
