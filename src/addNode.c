#include "addNode.h"



Node *addNode(Node **rootPtr, Node *nodeToAdd){
    if (*rootPtr == NULL){
        *rootPtr = nodeToAdd;
      }
    else{
      if (nodeToAdd->data < (*rootPtr)->data)
      {
        (*rootPtr)->left=addNode(&(*rootPtr)->left,nodeToAdd);
        if( (*rootPtr)->left->lock==0)
        (*rootPtr)->bf -= 1;
        else
        (*rootPtr)->lock = 1;
        (*rootPtr)->left->lock=0;
      }
      else if (nodeToAdd->data > (*rootPtr)->data)
      {
        (*rootPtr)->right=addNode(&(*rootPtr)->right,nodeToAdd);
        if( (*rootPtr)->right->lock==0)
        (*rootPtr)->bf += 1;
        else
        (*rootPtr)->lock = 1;
        (*rootPtr)->right->lock==0;
      }

      else if(nodeToAdd->data == (*rootPtr)->data){
          (*rootPtr)->lock=1;
          printf("The value %d is existed, no changes!!!",nodeToAdd->data);
          return *rootPtr;
      }
    }

    if((*rootPtr)->bf==2||(*rootPtr)->bf==-2){
      avlbalance(&(*rootPtr));
    }
        return *rootPtr;
 }
