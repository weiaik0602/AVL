#include "nodeRemove.h"

Node *findNearest(Node *rootPtr,int choose){

  if(choose==LEFT){
    if(rootPtr->left!=NULL)
      findNearest(rootPtr->left,choose);
    else
      return rootPtr;
  }
  else if(choose==RIGHT){
    if(rootPtr->right!=NULL)
      findNearest(rootPtr->right,choose);
    else
      return rootPtr;
  }
}

Node *nodeRemove(Node **rootPtr, int valToRemove){
  Node *Remove;
  Node *node = *rootPtr;
  Node *rightChild=node->right;
  Node *leftChild=node->left;
  Node *Nearest;
  //Node *child = node->right;
  if(node->data==valToRemove){
    return NULL;
  }
  else if(node->left!=NULL){
    if(leftChild->data==valToRemove){
      //return NULL;
      Remove=node->left;
      Nearest=findNearest(Remove->right,LEFT);
      Nearest->left=Remove->left;
      Nearest->right=Remove->right;
      node->left=Nearest;
    }
  }
  else if(node->right!=NULL){
    if(node->right->data==valToRemove){
      Remove=node->right;
      Nearest=findNearest(Remove->right,LEFT);
      Nearest->left=Remove->left;
      Nearest->right=Remove->right;
      node->right=Nearest;
    }
  }
  else if(valToRemove < (*rootPtr)->data){
    nodeRemove(&(*rootPtr)->left,valToRemove);
  }
  else if(valToRemove > (*rootPtr)->data){
    nodeRemove(&(*rootPtr)->right,valToRemove);
  }

return *rootPtr;
}
