#include "Rotate.h"

void printTraversalPostorder(Node *node){
  if(node->left!=NULL)
    printTraversalPostorder(node->left);
  if(node->right!=NULL)
    printTraversalPostorder(node->right);
  printf("%d",node->data);
}

Node* rotateRight(Node *node){
  Node *temp;
  temp=node->left;
  node->left=temp->right;
  temp->right=node;
  return temp;
}

Node* rotateLeft(Node *node){
  Node *temp;
  temp=node->right;
  node->right=temp->left;
  temp->left=node;
  return temp;
}
