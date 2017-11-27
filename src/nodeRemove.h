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

Node *findNearestO(Node *rootPtr,int choose);
Node *removeRoot(Node *Remove);
Node *nodeRemove(Node **rootPtr, int valToRemove);

Node *avlRemove(Node **rootPtr, int data);
Node *_avlRemove(Node **root, int nodeToRemove ,int *heightchange);
Node *findnearest(Node **rootPtr, int *heightchange);
#endif // _NODEREMOVE_H
