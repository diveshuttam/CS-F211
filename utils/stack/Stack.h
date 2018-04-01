#ifndef __STACK_H
#define __STACK_H

#ifndef __STACK
#define __STACK
typedef struct Stack *Stack;
#endif

#ifndef __KEY
#define __KEY
typedef int Key;
#endif

typedef struct Element *Element;

Stack newStack ();
Stack pop (Stack s);
Stack push (Stack s, Element e);
Element top (Stack s);
Stack clearStack (Stack s);
#endif
