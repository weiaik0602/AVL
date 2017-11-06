#ifndef _NODEREMOVE_H
#define _NODEREMOVE_H

#include <Node.h>
#include <stdio.h>
#include <Rotate.h>
#include "AVL_Balance.h"
#include "nodeHelper.h"


#define LEFT 0
#define RIGHT 1


Node *findNearest(Node *rootPtr,int choose);
Node *nodeRemove(Node **rootPtr, int valToRemove);
#endif // _NODEREMOVE_H
