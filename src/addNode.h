#ifndef _ADDNODE_H
#define _ADDNODE_H

#include <Node.h>
#include <stdio.h>
#include <Rotate.h>
#include "AVL_Balance.h"
Node* addNode_SIM(Node *addition,Node *node);
Node *addNode(Node **rootPtr, Node *nodeToAdd);
#endif // _ADDNODE_H
