#ifndef _AVLINTEGER_H
#define _AVLINTEGER_H

#include "Node.h"
#include "stdlib.h"
typedef struct IntegerNode IntegerNode;
struct IntegerNode{
  IntegerNode *left;
  IntegerNode *right;
  int balanceFactor;
  int data;
  //int lock;
};


#define avlAddInteger(root, nodeToAdd)  addNode((Node **)root, (Node *)nodeToAdd,(Compare) integerCompare)
#define avlRemoveInteger(root,data)     nodeRemove((Node **)root,(int *)data ,(Compare) integerCompare)

int integerCompare(int data,Node *refNode);
#endif // _AVLINTEGER_H
