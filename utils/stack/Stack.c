#ifndef __STACK
#define __STACK
typedef struct SeqList *Stack;
#endif

#include "Stack.h"
#include "SeqList.h"
#include <stdlib.h>

Stack clearStack(Stack s){
  while(top(s)!=NULL){
    s=pop(s);
  }
  return s;
}

Stack newStack(){
  Stack s=malloc(sizeof(struct SeqList));
  s=newList();
  return s;
}

Stack pop(Stack s){
   return deleteAtFront(s);
}

Element top(Stack s);
Stack push(Stack s, Element E){
   return insertAtFront(s, E);
}

Element top(Stack s){
  return s->front;
}
