#ifndef _NODEREMOVE_H
#define _NODEREMOVE_H

#include <Node.h>
#include <stdio.h>
#include <Rotate.h>
#include "AVL_Balance.h"
#include "nodeHelper.h"


#define LEFT 0
#define RIGHT 1
#define UNCHANGE 0
#define CHANGED 1

Node *findNearest(Node *rootPtr,int choose);
Node *removeRoot(Node *Remove,Compare cmp);
Node *nodeRemove(Node **rootPtr, void* valToRemove ,Compare cmp);


#endif // _NODEREMOVE_H
