#include "addNode.h"



Node *addNode(Node **rootPtr, Node *nodeToAdd){
    if (*rootPtr == NULL){
        *rootPtr = nodeToAdd;
      }
    else{
      if (nodeToAdd->data < (*rootPtr)->data)
      {
        (*rootPtr)->bf -= 1;
     addNode(&(*rootPtr)->left,nodeToAdd);
      }
      else if (nodeToAdd->data > (*rootPtr)->data)
      {
          (*rootPtr)->bf += 1;
      addNode(&(*rootPtr)->right,nodeToAdd);
      }
    }

    if((*rootPtr)->bf!=1||(*rootPtr)->bf!=0||(*rootPtr)->bf!=-1){
      avlbalance(&(*rootPtr));
    }
        return *rootPtr;
 }
