#include "nodeRemove.h"


Node *findNearest(Node *node,int choose){
  if(choose==LEFT){
    if(node->left!=NULL){
      findNearest(node->left,choose);
    }
    else
      return node;
  }
  else if(choose==RIGHT){
    if(node->right!=NULL){
      findNearest(node->right,choose);}
    else
      return node;
  }
}

Node *removeRoot(Node *Remove,Compare cmp){
  Node *Nearest;
  if(Remove->right!=NULL){
    //get the lock value from the right child if they are locked
    if(Remove->right->balanceFactor==0 && Remove->right->right!=NULL)
      Remove->lock=Remove->right->lock;
      //find nearest node
    Nearest=findNearest(Remove->right,LEFT);
    //remove the nearest node from the tree
    nodeRemove(&(Remove->right),(void *)Nearest->data,cmp);

    if(Remove->right==NULL){
        Nearest->balanceFactor=(Remove->balanceFactor)-1;
        Nearest->lock=(Remove->lock);
        Nearest->left=Remove->left;
      }
    else{
      if(Remove->lock==1)
        Nearest->balanceFactor=Remove->balanceFactor;
      else
        Nearest->balanceFactor=(Remove->balanceFactor)-1;
      Nearest->left=Remove->left;
      Nearest->right=Remove->right;
    }
  return Nearest;
  }
  else if(Remove->left!=NULL){
    if(Remove->left->balanceFactor==0 && Remove->left->right!=NULL)
      Remove->lock=Remove->left->lock;
    Nearest=findNearest(Remove->left,RIGHT);
    nodeRemove(&(Remove->left),(void *)Nearest->data,cmp);
    if(Remove->left==NULL){
        Nearest->balanceFactor=(Remove->balanceFactor)+1;
        Nearest->lock=(Remove->lock);
        Nearest->right=Remove->right;
      }
    else{
      if(Remove->lock==1)
        Nearest->balanceFactor=Remove->balanceFactor;
      else
        Nearest->balanceFactor=(Remove->balanceFactor)+1;

      Nearest->left=Remove->left;
      Nearest->right=Remove->right;
    }

  return Nearest;
  }
  else
    return NULL;
}



Node *nodeRemove(Node **rootPtr, void* valToRemove ,Compare cmp){
  Node *node = *rootPtr;
  if(node!=NULL){
    //lock the left/right node if their balanceFactor is 0 and not empty
    if(node->left!=NULL&&node->left->left!=NULL&&node->left->balanceFactor==0)
      node->left->lock=1;
    if(node->right!=NULL&&node->right->right!=NULL&&node->right->balanceFactor==0)
      node->right->lock=1;

      //if value smaller then go left
  int compare =cmp(valToRemove,node);
  if(compare==-1){
    if(node->left==NULL){
      Throw((uintptr_t)(createException("This data is not found in this tree!!!",1)));
      node->lock=2;
      return node;
    }
    node->left=nodeRemove(&(node->left),valToRemove,cmp);
    if(node->left!=NULL){
      if(node->left->lock==2){
        node->lock=2;
        return node;
      }
      node->lock=node->left->lock;
      node->left->lock=0;
    }
    else
      node->lock=0;
    if(node->lock==0)
      node->balanceFactor+=1;
    else
      node->lock=0;
  }
  // else bigger go right
  else if(compare==1){
    if(node->right==NULL){
      Throw((uintptr_t)(createException("This data is not found in this tree!!!",1)));
      node->lock=2;
      return node;
    }
    node->right=nodeRemove(&(node->right),valToRemove,cmp);

    if(node->right!=NULL){
      if(node->right->lock==2){
        node->lock=2;
        return node;
      }
      node->lock=node->right->lock;
      node->right->lock=0;
    }
    else
      node->lock=0;
    if(node->lock==0)
      node->balanceFactor-=1;
    else
      node->lock=0;
  }
  //else equal then can delete
  else if(compare==0){
    node=removeRoot(node,cmp);
  }
  //no bigger,no smaller,not equal= NULL
  else
    return NULL;
  }
  //to balance the tree if there is not balanced
  if(node!=NULL){
    if( node->balanceFactor==2  ||  node->balanceFactor==-2 ){
      avlbalance(&node);
    }
  }

    *rootPtr=node;
    return node;
}
