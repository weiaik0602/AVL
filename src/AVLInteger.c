#include "AVLInteger.h"



int integerCompare(int data,Node *refNode){
  IntegerNode *root = (IntegerNode*)refNode;

  root->data=(uintptr_t)refNode->data;

  if(data > root->data)
    return 1;
  else if(data< root->data)
    return -1;
  else
    return 0;
}
