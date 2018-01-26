//author: Divesh Uttamchandani
//2016A7PS0045P

typedef struct Key{
  int data;
} Key;

typedef struct Element{
  Key k;
  Element *next;
} Element;

typedef struct SeqList{
  Element *front;
  Element *rear;
} SeqList;



SeqList *newList();
SeqList *insertInOrder(SeqList *sl, Element *e);
SeqList *insertAtFront(SeqList *sl, Element *e);
SeqList *insertAtEnd(SeqList *sl, Element *e);
SeqList *delete(SeqList *sl, Element *e);
SeqList *deleteAtFront(SeqList *sl);
Element *find(SeqList *sl, Key k);
