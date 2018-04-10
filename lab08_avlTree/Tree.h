#ifndef __TREE_H
#define __TREE_H

#ifndef __VALUE
#define __VALUE
typedef int value;
#endif

enum TRAV_RET
{ RETURN, RIGHT, LEFT };

#ifndef __TREE
#define __TREE
typedef struct Tree *Tree;
#endif

#ifndef __PATH
#define __PATH
typedef struct Stack *PATH;
#endif

//functions declaration start here
Tree createTree ();
Tree add (Tree root, Tree val);
Tree find (Tree root, Tree val);
Tree delete (Tree root, Tree val);
void inOrder (Tree root, void (*f) (Tree));     //passing a function pointer
void preOrder (Tree root, void (*f) (Tree));
void postOrder (Tree root, void (*f) (Tree));
void compare (value val1, value val2);

//you can pass a function to traverse to direct traversing it returns a path
PATH traverse (Tree root, enum TRAV_RET (*f) (Tree, ...), ...);
#endif