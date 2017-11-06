#include "addNode.h"

/*
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
*/

Node *addNode(Node **rootPtr, Node *nodeToAdd){
    if (*rootPtr == NULL){
        *rootPtr = nodeToAdd;
      //  return *rootPtr;
      }
    else{
      if (nodeToAdd->data < (*rootPtr)->data)
      {
        (*rootPtr)->bf -= 1;
        (*rootPtr)->left = addNode(&(*rootPtr)->left,nodeToAdd);

      }
      else if (nodeToAdd->data > (*rootPtr)->data)
      {
          (*rootPtr)->bf += 1;
        (*rootPtr)->right = addNode(&(*rootPtr)->right,nodeToAdd);

      }
    }

    if((*rootPtr)->bf!=1||(*rootPtr)->bf!=0||(*rootPtr)->bf!=-1){
      avlbalance(&(*rootPtr));
    }
/*
    if((*rootPtr)->bf >= 2)
        avlBalanceRightTree(&(*rootPtr));
    else if((*rootPtr)->bf <= -2)
        avlBalanceLeftTree(&(*rootPtr));
    else{
        *rootPtr = *rootPtr;
      }*/
        return *rootPtr;
 }
