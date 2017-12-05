#include "AVLString.h"



int stringCompare(char* data,Node *refNode){
  StringNode *root = (StringNode*)refNode;

  root->data=refNode->data;
  return strcmp(data,root->data);

}
