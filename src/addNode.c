#include "addNode.h"




 Node *addNode(Node **rootPtr, Node *nodeToAdd,Compare cmp){
    Node *root=*rootPtr;

     if (*rootPtr == NULL){
         *rootPtr = nodeToAdd;
       }
     else{
       int compare =cmp(nodeToAdd->data,root);
       if (compare==-1)
       {
         (*rootPtr)->left=addNode(&(*rootPtr)->left,nodeToAdd,cmp);
         if( (*rootPtr)->left->lock==0)
         (*rootPtr)->balanceFactor -= 1;
         else
         (*rootPtr)->lock = 1;
         (*rootPtr)->left->lock=0;
       }
       else if (compare==1)
       {
         (*rootPtr)->right=addNode(&(*rootPtr)->right,nodeToAdd,cmp);
         if( (*rootPtr)->right->lock==0)
         (*rootPtr)->balanceFactor += 1;
         else
         (*rootPtr)->lock = 1;
         (*rootPtr)->right->lock==0;
       }

       else if(compare==0){
           (*rootPtr)->lock=1;
           Throw((uintptr_t)(createException("The node is existing now !!!",0)));
           return *rootPtr;
       }
     }

     if((*rootPtr)->balanceFactor==2||(*rootPtr)->balanceFactor==-2){
       avlbalance(&(*rootPtr));
       (*rootPtr)->lock=1;
     }
         return *rootPtr;
  }
