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
  Node *node=Remove;
  Node *Nearest;
  if(Remove->right!=NULL){
    Nearest=findNearest(Remove->right,LEFT);
    node=Nearest;
  }
  else if(Remove->left!=NULL){
    Nearest=findNearest(Remove->left,RIGHT);
    node=Nearest;
  }
  else
    return NULL;
  Nearest->left=Remove->left;
  Nearest->right=Remove->right;
  return node;
}


Node *nodeRemove(Node **rootPtr, int valToRemove){
  Node *Remove;
  Node *node = *rootPtr;
  Node *rightChild=node->right;
  Node *leftChild=node->left;
  Node *Nearest;
  if(node->data==valToRemove){
    Remove=node;
    node=removeRoot(Remove);
    return node;
  }
  else if(node->left!=NULL && leftChild->data==valToRemove){
      Remove=node->left;
      if(Remove->right!=NULL){
        Nearest=findNearest(Remove->right,LEFT);
        nodeRemove(&(Remove->right),Nearest->data);
        node->left=Nearest;
        if(Remove->right!=Nearest){
          Nearest->left=Remove->left;
          Nearest->right=Remove->right;
        }
        else
          Nearest->left=Remove->left;
        return node;
      }
      else if(Remove->left!=NULL){
          Nearest=findNearest(Remove->left,RIGHT);
          nodeRemove(&(Remove->left),Nearest->data);
          node->left=Nearest;
          if(Remove->left!=Nearest){
            Nearest->left=Remove->left;
            Nearest->right=Remove->right;
          }
          else
            Nearest->right=Remove->right;
          return node;
        }
      else
        node->left=NULL;
      }
  else if(node->right!=NULL && rightChild->data==valToRemove){
      Remove=node->right;
      if(Remove->right!=NULL){
        Nearest=findNearest(Remove->right,LEFT);
        nodeRemove(&(Remove->right),Nearest->data);
        node->right=Nearest;
        if(Remove->right!=Nearest){
          Nearest->left=Remove->left;
          Nearest->right=Remove->right;
        }
        else
          Nearest->left=Remove->left;
        return node;
      }
      else if(Remove->left!=NULL){
          Nearest=findNearest(Remove->left,RIGHT);
          nodeRemove(&(Remove->left),Nearest->data);
          node->right=Nearest;
          if(Remove->left!=Nearest){
            Nearest->left=Remove->left;
            Nearest->right=Remove->right;
          }
          else
            Nearest->right=Remove->right;
          return node;
        }
      else
        node->right=NULL;
  }
  else if(valToRemove < node->data){
    nodeRemove(&(node->left),valToRemove);
  }
  else if(valToRemove > node->data){
    nodeRemove(&(node->right),valToRemove);
  }
  return node;
}
