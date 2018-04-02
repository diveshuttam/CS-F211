#ifndef __TREE_H
#define __TREE_H

#ifndef __VALUE
#define __VALUE
typedef int value;
#endif

enum TRAV_RET
{ RETURN, RIGHT, LEFT };

#ifndef __NODE
#define __NODE
typedef struct node *NODE;
struct node
{
  value val;
  NODE right;
  NODE left;
  int balance:2;
};
#endif

typedef struct Stack *PATH;

//functions declaration start here
NODE createTree ();
NODE add (NODE root, value val);
NODE find (NODE root, value val);
NODE delete (NODE root, value val);
void inOrder (NODE root, void (*f) (NODE));     //passing a function pointer
void preOrder (NODE root, void (*f) (NODE));
void postOrder (NODE root, void (*f) (NODE));
void printNode (NODE root);
PATH traverse (NODE root, enum TRAV_RET (*f) (NODE, ...), ...);
#endif
