#ifndef __STACK_H
#define __STACK_H

typedef struct Pair{
  int lo;
  int hi;
  sturct Pair * next;
}Pair;

//implementing as a linked list
//unbounded stack
typedef struct Stack{
  Pair *top;
}Stack;

Stack newStack(Stack s);
Stack isEmpty(Stack s);
Pair top(Stack s);
Stack pop(Stack s);//pop frees
Stack push(Stack s);//push allocates
#endif
