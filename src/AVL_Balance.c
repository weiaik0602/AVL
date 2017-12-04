#include "AVL_Balance.h"


#include "Rotate.h"

int avlBalanceLeftTree(Node **rootPtr){
  Node *node = *rootPtr;
  Node *child = node->right;
  Node *grandChild = node->right->left;

  if(child->balanceFactor > 0 ){
    node->balanceFactor = 0;
    child->balanceFactor = 0;
    *rootPtr = rotateLeft(*rootPtr);
    }
  else if(child->balanceFactor == 0){
    node->balanceFactor = 1;
    child->balanceFactor = -1;
    *rootPtr = rotateLeft(*rootPtr);
    }
  else if(child->balanceFactor == -1){
    if(grandChild->balanceFactor == -1){
      node->balanceFactor = 0;
      child->balanceFactor = 1;
      grandChild->balanceFactor = 0;
      *rootPtr = rotateRightLeft(*rootPtr);
      }
    else if(grandChild->balanceFactor == 0){
      node->balanceFactor = 0;
      child->balanceFactor = 0;
      grandChild->balanceFactor = 0;
      *rootPtr = rotateRightLeft(*rootPtr);
      }
    else if(grandChild->balanceFactor == 1){
      node->balanceFactor = -1;
      child->balanceFactor = 0;
      grandChild->balanceFactor = 0;
      *rootPtr = rotateRightLeft(*rootPtr);
      }
  }
  return 0;
}

int avlBalanceRightTree(Node **rootPtr){
  Node *node = *rootPtr;
  Node *child = node->left;
  Node *grandChild = node->left->right;

  if(child->balanceFactor < 0 ){
    node->balanceFactor = 0;
    child->balanceFactor = 0;
    *rootPtr = rotateRight(*rootPtr);
    }
  else if(child->balanceFactor == 0){
    node->balanceFactor = -1;
    child->balanceFactor = 1;
    *rootPtr = rotateRight(*rootPtr);
    }
  else if(child->balanceFactor == 1){
    if(grandChild->balanceFactor == 1){
      node->balanceFactor = 0;
      child->balanceFactor = -1;
      grandChild->balanceFactor = 0;
      *rootPtr = rotateLeftRight(*rootPtr);
      }
    else if(grandChild->balanceFactor == 0){
      node->balanceFactor = 0;
      child->balanceFactor = 0;
      grandChild->balanceFactor = 0;
      *rootPtr = rotateLeftRight(*rootPtr);
      }
    else if(grandChild->balanceFactor == -1){
      node->balanceFactor = 1;
      child->balanceFactor = 0;
      grandChild->balanceFactor = 0;
      *rootPtr = rotateLeftRight(*rootPtr);
      }
  }
  return 0;
}



void avlbalance(Node **rootPtr){
  Node *node = *rootPtr;
  if(node->balanceFactor==2){
    Node *child = node->right;
    Node *grandChild = node->right->left;
    if(child->balanceFactor > 0 ){
    node->balanceFactor = 0;
    child->balanceFactor = 0;
    *rootPtr = rotateLeft(*rootPtr);
    }
    else if(child->balanceFactor == 0){
    node->balanceFactor = 1;
    child->balanceFactor = -1;
    *rootPtr = rotateLeft(*rootPtr);
    }
    else if(child->balanceFactor == -1){
    if(grandChild->balanceFactor == -1){
      node->balanceFactor = 0;
      child->balanceFactor = 1;
      grandChild->balanceFactor = 0;
      *rootPtr = rotateRightLeft(*rootPtr);
      }
      else if(grandChild->balanceFactor == 0){
      node->balanceFactor = 0;
      child->balanceFactor = 0;
      grandChild->balanceFactor = 0;
      *rootPtr = rotateRightLeft(*rootPtr);
      }
      else if(grandChild->balanceFactor == 1){
      node->balanceFactor = -1;
      child->balanceFactor = 0;
      grandChild->balanceFactor = 0;
      *rootPtr = rotateRightLeft(*rootPtr);
      }
    }
  }
  if(node->balanceFactor==-2){
    Node *child = node->left;
    Node *grandChild = node->left->right;

    if(child->balanceFactor < 0 ){
      node->balanceFactor = 0;
      child->balanceFactor = 0;
      *rootPtr = rotateRight(*rootPtr);
      }
    else if(child->balanceFactor == 0){
      node->balanceFactor = -1;
      child->balanceFactor = 1;
      *rootPtr = rotateRight(*rootPtr);
      }
    else if(child->balanceFactor == 1){
      if(grandChild->balanceFactor == 1){
        node->balanceFactor = 0;
        child->balanceFactor = -1;
        grandChild->balanceFactor = 0;
        *rootPtr = rotateLeftRight(*rootPtr);
        }
      else if(grandChild->balanceFactor == 0){
        node->balanceFactor = 0;
        child->balanceFactor = 0;
        grandChild->balanceFactor = 0;
        *rootPtr = rotateLeftRight(*rootPtr);
        }
      else if(grandChild->balanceFactor == -1){
        node->balanceFactor = 1;
        child->balanceFactor = 0;
        grandChild->balanceFactor = 0;
        *rootPtr = rotateLeftRight(*rootPtr);
        }
    }
  }

}
