#include "nodeRemove.h"




/*
Node *findNearest(Node *rootPtr,int choose){
  Node *child;
  if(choose==LEFT){
    child=rootPtr->left;
    if(child!=NULL){
      if(child->left!=NULL){
        rootPtr->bf+=1;
        child=findNearest(rootPtr->left,choose);
      }
      else{
        if(child->right!=NULL){
          rootPtr->left=child->right;
        }
        else
          rootPtr->left=NULL;
        rootPtr->bf+=1;
        }
      }
    else
      return rootPtr;
  }
  else if(choose==RIGHT){
    child=rootPtr->right;
    if(child!=NULL){
      if(child->right!=NULL){
        rootPtr->bf+=1;
        child=findNearest(rootPtr->right,choose);
      }
      else{
        if(child->left!=NULL){
          rootPtr->right=child->left;
        }
        else
          rootPtr->right=NULL;
        rootPtr->bf-=1;
        }
      }
    else
      return rootPtr;
  }

  if(rootPtr!=NULL){
    if(rootPtr->bf==2  ||  rootPtr->bf==-2 ){
      avlbalance(&rootPtr);
    }
  }
  return child;
}

*/
Node *findNearestO(Node *node,int choose){
  if(choose==LEFT){
    if(node->left!=NULL){
      findNearestO(node->left,choose);
    }
    else
      return node;
  }
  else if(choose==RIGHT){
    if(node->right!=NULL){
      findNearestO(node->right,choose);}
    else
      return node;
  }
}

Node *removeRoot(Node *Remove){
  Node *Nearest;
  if(Remove->right!=NULL){
    if(Remove->right->bf==0 && Remove->right->right!=NULL)
      Remove->lock=Remove->right->lock;
    Nearest=findNearestO(Remove->right,LEFT);
    nodeRemove(&(Remove->right),Nearest->data);
    if(Remove->right==NULL){
        Nearest->bf=(Remove->bf)-1;
        Nearest->lock=(Remove->lock);
        Nearest->left=Remove->left;
      }
    else{
      if(Remove->lock==1)
        Nearest->bf=Remove->bf;
      else
        Nearest->bf=(Remove->bf)-1;

      Nearest->left=Remove->left;
      Nearest->right=Remove->right;
    }
  return Nearest;
  }
  else if(Remove->left!=NULL){
    if(Remove->left->bf==0 && Remove->left->right!=NULL)
      Remove->lock=Remove->left->lock;
    Nearest=findNearestO(Remove->left,RIGHT);
    nodeRemove(&(Remove->left),Nearest->data);
    if(Remove->left==NULL){
        Nearest->bf=(Remove->bf)+1;
        Nearest->lock=(Remove->lock);
        Nearest->right=Remove->right;
      }
    else{
      if(Remove->lock==1)
        Nearest->bf=Remove->bf;
      else
        Nearest->bf=(Remove->bf)+1;

      Nearest->left=Remove->left;
      Nearest->right=Remove->right;
    }

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
    if(node->left!=NULL){
      node->lock=node->left->lock;
      node->left->lock=0;
    }
    else
      node->lock=0;
    if(node->lock==0)
      node->bf+=1;
    else
      node->lock=0;
  }
  else if(valToRemove > node->data){
    node->right=nodeRemove(&(node->right),valToRemove);
    if(node->right!=NULL){
      node->lock=node->right->lock;
      node->right->lock=0;
    }
    else
      node->lock=0;
    if(node->lock==0)
      node->bf-=1;
    else
      node->lock=0;
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
//////////////////////////////////////////////////////////////////////
Node *avlRemove(Node **rootPtr, int data){
    int heightchange;
    Node *avlRemove = _avlRemove(rootPtr, data, &heightchange);
    if(avlRemove == NULL){
        printf("deleted value doesn't exist!");
    }
    return avlRemove;
}

Node *_avlRemove(Node **root, int nodeToRemove ,int *heightchange){

        Node *temp = *root;
        //heightchange to determine either root's heigh change or unchange
       //standard removing
       // 0 is no height change
       if (*root == NULL)
           return NULL; //heigh change

       if(nodeToRemove < (*root)->data ){
         temp=_avlRemove(&(*root)->left, nodeToRemove,heightchange);
         if(*heightchange == CHANGED)
            (*root)->bf +=1;
            if((*root)->bf != 0)
            *heightchange = UNCHANGE;
       }
       else if(nodeToRemove > (*root)->data ){
         temp=_avlRemove(&(*root)->right, nodeToRemove,heightchange);
         if(*heightchange==CHANGED)
            (*root)->bf -=1;
            if((*root)->bf != 0)
            *heightchange = UNCHANGE;
       }
       else if(nodeToRemove == (*root)->data ){
           // node with only one child or no child
         if( ( (*root)->left == NULL) || ( (*root)->right == NULL) )
         {
             Node *current = (*root)->left ?  (*root)->left : (*root)->right;

             // No child case
             if (current == NULL)
             {
                 current = *root;
                 *root = NULL;
                 *heightchange=CHANGED; //heigh change
             }
             else // One child case
             {
              *root = current; // Copy the contents of the non-empty child
              *heightchange=CHANGED; // height change
             }
        }
        else// node with two children case
        {
            //find the nearest in removenode->right->most left
            Node* temp1 = findnearest(&(*root)->right,heightchange);
            //checking whether have heightchange ?
            if(*heightchange==CHANGED)
            (*root)->bf -=1;
            else
            (*root)->bf=(*root)->bf;
            // Copy the nearest's data to this node
            if(temp1->right!=NULL){
              temp1->bf = ((*root)->bf);
              temp1->left = (*root)->left;
              (*root) = temp1;
            }
            else{
            temp1->bf = ((*root)->bf);
            temp1->left = (*root)->left;
            temp1->right= (*root)->right;
            (*root) = temp1;
            }
			       *heightchange=CHANGED;
             if(*root==NULL){
               return temp;
             }
			       if((*root)->bf >= 2)
                avlBalanceRightTree(&(*root));
             else if((*root)->bf <= -2)
                 avlBalanceLeftTree(&(*root));
             else{
                *root = *root;
               }
            return temp;
        }
    }
    if(*root==NULL){
          return temp;
        }
        if(*root!=NULL){
          if( (*root)->bf==2  ||  (*root)->bf==-2 ){
            avlbalance(&(*root));
          }
        }
    return temp;
}
Node *findnearest(Node **rootPtr, int *heightchange)
{
Node *current = (*rootPtr)->left;
    /* loop down to find the leftmost leaf */
 if(current!=NULL){
      if(current->left != NULL)
         findnearest(&(*rootPtr)->left,heightchange);
     else{
         if(current->right !=NULL){
          (*rootPtr)->left = current->right;
          (*rootPtr)->bf +=1;
           current->right = NULL;
           *heightchange = CHANGED;
         }
         else{
           (*rootPtr)->left = NULL;
           (*rootPtr)->bf +=1;
           if((*rootPtr)->bf >= 2)
              avlBalanceRightTree(&(*rootPtr));
           else if((*rootPtr)->bf <= -2)
              avlBalanceLeftTree(&(*rootPtr));
           else{
                (*rootPtr) = (*rootPtr);
               }
            if((*rootPtr)->bf!=0)
              *heightchange = UNCHANGE;
           else
             *heightchange = CHANGED;
         }
       return current;
        }
  }
  else
     *heightchange = CHANGED;
     return *rootPtr;
 }
