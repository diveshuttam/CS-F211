#include "stack.h"
#include<stdlib.h>
Stack newStack(Stack s){
  return Stack {.top=NULL};
}

Stack isEmpty(Stack s){
  return (s.top==NULL);
}

Pair top(Stack s){
  return Pair{.hi=s.hi, .lo=s.lo, .next=NULL}
}

Stack pop(Stack s){
  if(s.top==NULL){
    return s;
  }
  Pair *temp=s.top;
  s.top=s.top->next;
  free(temp);
  return s;
}

Stack push(Stack s,Pair p){
  p.next=s.top;
  Pair *temp=malloc(sizeof(p));
  *temp=p;
  s.top=temp;
  return s;
}
