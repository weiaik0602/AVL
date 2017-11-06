#include "AVL_Balance.h"


#include "Rotate.h"

int avlBalanceLeftTree(Node **rootPtr){
  Node *node = *rootPtr;
  Node *child = node->right;
  Node *grandChild = node->right->left;

  if(child->bf > 0 ){
    node->bf = 0;
    child->bf = 0;
    *rootPtr = rotateLeft(*rootPtr);
    }
  else if(child->bf == 0){
    node->bf = 1;
    child->bf = -1;
    *rootPtr = rotateLeft(*rootPtr);
    }
  else if(child->bf == -1){
    if(grandChild->bf == -1){
      node->bf = 0;
      child->bf = 1;
      grandChild->bf = 0;
      *rootPtr = rotateRightLeft(*rootPtr);
      }
    else if(grandChild->bf == 0){
      node->bf = 0;
      child->bf = 0;
      grandChild->bf = 0;
      *rootPtr = rotateRightLeft(*rootPtr);
      }
    else if(grandChild->bf == 1){
      node->bf = -1;
      child->bf = 0;
      grandChild->bf = 0;
      *rootPtr = rotateRightLeft(*rootPtr);
      }
  }
  return 0;
}

int avlBalanceRightTree(Node **rootPtr){
  Node *node = *rootPtr;
  Node *child = node->left;
  Node *grandChild = node->left->right;

  if(child->bf < 0 ){
    node->bf = 0;
    child->bf = 0;
    *rootPtr = rotateRight(*rootPtr);
    }
  else if(child->bf == 0){
    node->bf = -1;
    child->bf = 1;
    *rootPtr = rotateRight(*rootPtr);
    }
  else if(child->bf == 1){
    if(grandChild->bf == 1){
      node->bf = 0;
      child->bf = -1;
      grandChild->bf = 0;
      *rootPtr = rotateLeftRight(*rootPtr);
      }
    else if(grandChild->bf == 0){
      node->bf = 0;
      child->bf = 0;
      grandChild->bf = 0;
      *rootPtr = rotateLeftRight(*rootPtr);
      }
    else if(grandChild->bf == -1){
      node->bf = 1;
      child->bf = 0;
      grandChild->bf = 0;
      *rootPtr = rotateLeftRight(*rootPtr);
      }
  }
  return 0;
}



void avlbalance(Node **rootPtr){
  Node *node = *rootPtr;
  if(node->bf==2){
    Node *child = node->right;
    Node *grandChild = node->right->left;
    if(child->bf > 0 ){
    node->bf = 0;
    child->bf = 0;
    *rootPtr = rotateLeft(*rootPtr);
    }
    else if(child->bf == 0){
    node->bf = 1;
    child->bf = -1;
    *rootPtr = rotateLeft(*rootPtr);
    }
    else if(child->bf == -1){
    if(grandChild->bf == -1){
      node->bf = 0;
      child->bf = 1;
      grandChild->bf = 0;
      *rootPtr = rotateRightLeft(*rootPtr);
      }
      else if(grandChild->bf == 0){
      node->bf = 0;
      child->bf = 0;
      grandChild->bf = 0;
      *rootPtr = rotateRightLeft(*rootPtr);
      }
      else if(grandChild->bf == 1){
      node->bf = -1;
      child->bf = 0;
      grandChild->bf = 0;
      *rootPtr = rotateRightLeft(*rootPtr);
      }
    }
  }
  if(node->bf==-2){
    Node *child = node->left;
    Node *grandChild = node->left->right;

    if(child->bf < 0 ){
      node->bf = 0;
      child->bf = 0;
      *rootPtr = rotateRight(*rootPtr);
      }
    else if(child->bf == 0){
      node->bf = -1;
      child->bf = 1;
      *rootPtr = rotateRight(*rootPtr);
      }
    else if(child->bf == 1){
      if(grandChild->bf == 1){
        node->bf = 0;
        child->bf = -1;
        grandChild->bf = 0;
        *rootPtr = rotateLeftRight(*rootPtr);
        }
      else if(grandChild->bf == 0){
        node->bf = 0;
        child->bf = 0;
        grandChild->bf = 0;
        *rootPtr = rotateLeftRight(*rootPtr);
        }
      else if(grandChild->bf == -1){
        node->bf = 1;
        child->bf = 0;
        grandChild->bf = 0;
        *rootPtr = rotateLeftRight(*rootPtr);
        }
    }
  }

}
