#ifndef _ADDNODE_H
#define _ADDNODE_H

#include <Node.h>
#include <stdio.h>
#include <Rotate.h>
#include "AVL_Balance.h"





Node *addNode(Node **rootPtr, Node *nodeToAdd,Compare cmp);

#endif // _ADDNODE_H
