#ifndef _AVL_BALANCE_H
#define _AVL_BALANCE_H

#include "addNode.h"
#include "Rotate.h"
#include "Node.h"
int avlBalanceRightTree(Node **rootPtr);
int avlBalanceLeftTree(Node **rootPtr);
void avlbalance(Node **rootPtr);
#endif // _AVL_BALANCE_H
