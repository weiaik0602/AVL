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
  if(node->data==valToRemove){
    Remove=node;
    if(Remove->right!=NULL){
      Nearest=findNearest(Remove->right,LEFT);
      node=Nearest;
    //  nodeRemove(node->right, node->data);
    }
    else if(Remove->left!=NULL){
      Nearest=findNearest(Remove->left,RIGHT);
      node=Nearest;
    //  nodeRemove(node->left, node->data);
    }
    else
      node= NULL;
      Nearest->left=Remove->left;
      Nearest->right=Remove->right;
  }
  else if(node->left!=NULL){
    if(leftChild->data==valToRemove){
      Remove=node->left;
      if(Remove->right!=NULL){
        Nearest=findNearest(Remove->right,LEFT);
        node->left=Nearest;
      }
      else if(Remove->left!=NULL){
        Nearest=findNearest(Remove->left,RIGHT);
        node->left=Nearest;
      }
      else
        node->left=NULL;

      if(Remove->left!=Nearest){
        Nearest->left=Remove->left;
        Nearest->right=Remove->right;
      }
    }
  }
  else if(node->right!=NULL){
    if(node->right->data==valToRemove){
      Remove=node->right;
      if(Remove->right!=NULL)
        Nearest=findNearest(Remove->right,LEFT);
      else if(Remove->left!=NULL)
        Nearest=findNearest(Remove->left,RIGHT);
      else
        node->right=NULL;

      if(Remove->left!=Nearest){
        Nearest->left=Remove->left;
        Nearest->right=Remove->right;
      }
    }
  }
  else if(valToRemove < (*rootPtr)->data){
    nodeRemove(&(*rootPtr)->left,valToRemove);
  }
  else if(valToRemove > (*rootPtr)->data){
    nodeRemove(&(*rootPtr)->right,valToRemove);
  }
return node;
}
