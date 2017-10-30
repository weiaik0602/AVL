#include "add.h"

Node* addNode_SIM(Node *addition,Node *node){
  if((addition->data)<(node->data)){
    if(node->left!=NULL)
    addNode(addition,node->left);
    else
    node->left=addition;
  }
  if((addition->data)>(node->data)){
    if(node->right!=NULL)
    addNode(addition,node->right);
    else
    node->right=addition;
  }
}


Node* addNode(Node **rootPtr,Node *nodeToAdd){
  Node root =*rootPtr;
  if(root==NULL)
    root=nodeToAdd;
  if((nodeToAdd->data)<(root->data)){
    if(root->left!=NULL)
    addNode(root->left,nodeToAdd);
    else
    root->left=*nodeToAdd;
  }
  if((nodeToAdd->data)>(*rootPtr->data)){
    if(*rootPtr->right!=NULL)
    addNode(*rootPtr->right,nodeToAdd);
    else
    *rootPtr->right=*nodeToAdd;
  }
}
