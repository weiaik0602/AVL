#include "nodeRemove.h"

Node *findNearest(Node *rootPtr,int choose){
  Node *child;
  if(choose==LEFT){
    child=rootPtr->left;
    if(child!=NULL){
      if(child->left!=NULL)
        findNearest(rootPtr->left,choose);
      else{
        //rootPtr->left=NULL;
        return child;
        }
      }
    else
      return rootPtr;
  }
  if(choose==RIGHT){
    child=rootPtr->right;
    if(child!=NULL){
      if(child->right!=NULL)
        findNearest(rootPtr->right,choose);
      else{
        //rootPtr->right=NULL;
        return child;
        }
      }
    else
      return rootPtr;
  }
}

Node *removeRoot(Node *Remove){
  if(Remove->right!=NULL){
    Nearest=findNearest(Remove->right,LEFT);
    node=Nearest;
  }
  else if(Remove->left!=NULL){
    Nearest=findNearest(Remove->left,RIGHT);
    node=Nearest;
  }
  else
    node= NULL;
    Nearest->left=Remove->left;
    Nearest->right=Remove->right;
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
    }
    else if(Remove->left!=NULL){
      Nearest=findNearest(Remove->left,RIGHT);
      node=Nearest;
    }
    else
      node= NULL;
      Nearest->left=Remove->left;
      Nearest->right=Remove->right;
  }
  else if(node->left!=NULL){
    if(leftChild->data==valToRemove){
      Remove=node->left;
      printf("%d\n",Remove->right->data );
      if(Remove->right!=NULL){
        Nearest=findNearest(Remove->right,LEFT);
        nodeRemove(&(Remove->right),Nearest->data);
        node->left=Nearest;
        if(Remove->right!=Nearest){
          Nearest->left=Remove->left;
          Nearest->right=Remove->right;
        }
      }
      else if(Remove->left!=NULL){
        Nearest=findNearest(Remove->left,RIGHT);
        nodeRemove(&(Remove->left),Nearest->data);
        node->left=Nearest;
        if(Remove->left!=Nearest){
          Nearest->left=Remove->left;
          Nearest->right=Remove->right;
        }
      }
      //else
      //  node->left=NULL;

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

      if(Remove->right!=Nearest&&Remove->left!=Nearest){
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
