#ifndef _AVLSTRING_H
#define _AVLSTRING_H

#include "Node.h"
#include "stdlib.h"
#include "string.h"
#include "nodeRemove.h"
typedef struct StringNode StringNode;
struct StringNode{
  StringNode *left;
  StringNode *right;
  int balanceFactor;
  char* data;
  //int lock;
};


#define avlAddString(root, nodeToAdd)  addNode((Node **)root, (Node *)nodeToAdd,(Compare) stringCompare)
#define avlRemoveString(root,data)     nodeRemove((Node **)root,(char *)data ,(Compare) stringCompare)

int stringCompare(char* data,Node *refNode);
#endif // _AVLSTRING_H
