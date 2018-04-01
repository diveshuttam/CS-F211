//author: Divesh Uttamchandani
//2016A7PS0045P

#ifndef __SEQLIST_H
#define __SEQLIST_H

#define GREATERTHAN 1
#define LESSTHAN -1
#define EQUALTO 0

typedef int bool;

#ifndef __KEY
#define __KEY
typedef struct Key
{
  int data;
} *Key;
#endif

#ifndef __ELEMENT
#define __ELEMENT
typedef struct Element
{
  Key k;
  struct Element *next;
} *Element;
#endif

#ifndef __SEQLIST
#define __SEQLIST
typedef struct SeqList
{
  Element front;
  Element rear;
} *SeqList;
#endif

SeqList newList ();
SeqList clearList (SeqList sl);
SeqList insertInOrder (SeqList sl, Element e);
SeqList insertAtFront (SeqList sl, Element e);
SeqList insertAtEnd (SeqList sl, Element e);
SeqList delete (SeqList sl, Element e);
SeqList deleteAtFront (SeqList sl);
Element find (SeqList sl, Key k);
bool compare (Key k1, Key k2);

#endif
