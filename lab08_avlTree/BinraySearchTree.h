enum TRAV_RET
{ RETURN, RIGHT, LEFT };

enum COMP_RET
{ LESSTHAN, GREATERTHAN, EQUALTO };

#ifndef __PATH
#define __PATH
typedef struct Stack *PATH;
#endif

BinaryTree add (BinaryTree root, BinaryTree val);
BinaryTree find (BinaryTree root, BinaryTree val);
BinaryTree delete (BinaryTree root, BinaryTree val);
void inOrder (BinaryTree root, void (*f) (BinaryTree));     //passing a function pointer
void preOrder (BinaryTree root, void (*f) (BinaryTree));
void postOrder (BinaryTree root, void (*f) (BinaryTree));
void compare (value val1, value val2);

//you can pass a function to traverse to direct traversing it returns a path
PATH traverse (BinaryTree root, enum TRAV_RET (*f) (BinaryTree, ...), ...);