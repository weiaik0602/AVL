#include "nodeRemove.h"


int hc;


Node *findNearest(Node *rootPtr,int choose){
  Node *child;
  if(choose==LEFT){
    child=rootPtr->left;
    if(child!=NULL){
      if(child->left!=NULL){
        rootPtr->bf+=1;
        findNearest(rootPtr->left,choose);
      }
      else{
        if(child->right!=NULL){
          rootPtr->left=child->right;
        }
        else
          rootPtr->left=NULL;
        rootPtr->bf+=1;
        return child;
        }
      }
    else
      return rootPtr;
  }
  if(choose==RIGHT){
    child=rootPtr->right;
    if(child!=NULL){
      if(child->right!=NULL){
        rootPtr->bf+=1;
        findNearest(rootPtr->right,choose);
      }
      else{
        if(child->left!=NULL){
          rootPtr->right=child->left;
        }
        else
          rootPtr->right=NULL;
        rootPtr->bf-=1;
        return child;
        }
      }
    else
      return rootPtr;
  }
}

Node *removeRoot(Node *Remove){
  Node *Nearest;
  if(Remove->right!=NULL){
    if(Remove->right->bf==0 && Remove->right->right!=NULL)
      Remove->lock=Remove->right->lock;
    Nearest=findNearest(Remove->right,LEFT);
    if(Nearest==Remove->right){
        Nearest->bf=(Remove->bf)-1;
        Nearest->lock=(Remove->lock);
      }
    else{
      if(Remove->lock==1)
        Nearest->bf=Remove->bf;
      else
        Nearest->bf=(Remove->bf)-1;
    }
    if(Remove->right!=Nearest){
      Nearest->left=Remove->left;
      Nearest->right=Remove->right;
    }
    else
      Nearest->left=Remove->left;
  return Nearest;
  }
  else if(Remove->left!=NULL){
    if(Remove->left->bf==0 && Remove->left->right!=NULL)
      Remove->lock=Remove->left->lock;
    Nearest=findNearest(Remove->left,RIGHT);
    if(Nearest==Remove->left){
        Nearest->bf=(Remove->bf)+1;
        Nearest->lock=(Remove->lock);
    }
    else{
      if(Remove->lock==1)
        Nearest->bf=Remove->bf;
      else
        Nearest->bf=(Remove->bf)+1;
    }

    if(Remove->left!=Nearest){
      Nearest->left=Remove->left;
      Nearest->right=Remove->right;
    }
    else
      Nearest->right=Remove->right;
  return Nearest;
  }
  else
    return NULL;


}



Node *nodeRemove(Node **rootPtr, int valToRemove  ){
  Node *node = *rootPtr;
  if(node!=NULL){
    if(node->left!=NULL&&node->left->left!=NULL&&node->left->bf==0)
    node->left->lock=1;
    if(node->right!=NULL&&node->right->right!=NULL&&node->right->bf==0)
      node->right->lock=1;


  if(valToRemove < node->data){
    node->left=nodeRemove(&(node->left),valToRemove);
    if(node->left!=NULL)
      node->lock=node->left->lock;
    if(node->lock==0)
      node->bf+=1;
  }
  else if(valToRemove > node->data){
    node->right=nodeRemove(&(node->right),valToRemove);
    if(node->right!=NULL)
      node->lock=node->right->lock;
    if(node->lock==0)
      node->bf-=1;
  }
  else if(valToRemove == node->data){
    node=removeRoot(node);
  }
  else
    return NULL;
  }

  if(node!=NULL){
    if( node->bf==2  ||  node->bf==-2 ){
      avlbalance(&node);
    }
  }
    *rootPtr=node;
    return node;
}
