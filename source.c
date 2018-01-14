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
     }
         return *rootPtr;
  }
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
#include "AVLInteger.h"



int integerCompare(int data,Node *refNode){
  IntegerNode *root = (IntegerNode*)refNode;

  root->data=(uintptr_t)refNode->data;

  if(data > root->data)
    return 1;
  else if(data< root->data)
    return -1;
  else
    return 0;
}
#include "AVLString.h"



int stringCompare(char* data,Node *refNode){
  StringNode *root = (StringNode*)refNode;

  root->data=refNode->data;
  return strcmp(data,root->data);

}
#include "exception.h"
#include <stdlib.h>
#include <stdio.h>

Exception *createException(char *msg, int errorCode){
  Exception *e=malloc(sizeof(Exception));
  e->msg=msg;
  e->errorCode=errorCode;
  return e;
}

void freeException(Exception *e){
  free(e);
}



void dumpException(Exception *e){
  printf("%s (err=%d)\n",e->msg,e->errorCode);
}
#include "nodeHelper.h"

extern Node node1 ,node2, node3, node4,node23,node5,node7, node10,node15, node20, node25, node30, node35, node40;
extern Node node45, node50, node55, node60, node65, node70, node75, node80;
extern Node node85, node90, node95, node100;
extern Node nodeAli, nodeAbu, nodeAkau, nodeAlirosa,nodeXaxa;
void initNode (Node *node, Node *left, Node *right, int balanceFactor){
  node->left = left;
  node->right = right;
  node->balanceFactor = balanceFactor;
  node->lock=0;
}

void giveInitdata(void){
  node1.data = (int *)1 ;
  node2.data = (int *)2;
  node3.data = (int *)3;
  node4.data = (int *)4;
  node5.data = (int *)5;
  node7.data = (int *)7;
  node10.data = (int *)10 ;
  node15.data = (int *)15 ;
  node20.data = (int *)20 ;
  node23.data = (int *)23;
  node25.data = (int *)25 ;
  node30.data = (int *)30 ;
  node35.data = (int *)35 ;
  node40.data = (int *)40 ;
  node45.data = (int *)45 ;
  node50.data = (int *)50 ;
  node55.data = (int *)55 ;
  node60.data = (int *)60 ;
  node65.data = (int *)65 ;
  node70.data = (int *)70 ;
  node75.data = (int *)75 ;
  node80.data = (int *)80 ;
  node85.data = (int *)85 ;
  node90.data = (int *)90 ;
  node95.data = (int *)95 ;
  node100.data = (int *)100 ;
}

void giveInitString(void){
  nodeAli.data="Ali";
  nodeAbu.data="Abu";
  nodeAkau.data="Akau";
  nodeAlirosa.data="Alirosa";
  nodeAba.data="Aba";
  nodeAmin.data="Amin";
  nodeXaxa.data="Xaxa";
}
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
#include "nodeVerifier.h"
#include "node.h"
#include "unity.h"
#include <stdarg.h>
#include <stdio.h>
#include <malloc.h>


char *createMessage(char *message, ...){
  va_list args;
  char *buffer;
  int length;

  va_start(args,message);

  length = vsnprintf(buffer, 0, message, args);
  buffer = malloc(length+1);
  vsnprintf(buffer, length+1, message, args);

  return buffer;
}

void testAssertEqualNode(Node *left, Node *right, int balanceFactor, Node *node,int lineNo){
  char *error;
  if(left != node->left){
      error = createMessage("Expected left node to be 0x%p, but was %p",  \
                            left,node->left);
      UNITY_TEST_FAIL(lineNo,error);
    }
  else if(balanceFactor != node->balanceFactor){
    error = createMessage("Expected balance factor to be 0x%p, but was %p",  \
                          balanceFactor,node->balanceFactor);
    UNITY_TEST_FAIL(lineNo,error);
  }


  else if(right != node->right){
      error = createMessage("Expected right node to be 0x%p, but was %p",  \
                            right,node->right);
    UNITY_TEST_FAIL(lineNo,error);
    }
}

void testAssertEqualNode2(Node *node,Node *left, Node *right, int balanceFactor, int lineNo){
  char *error;
  if(left != node->left){
      error = createMessage("Expected left node to be 0x%p, but was %p",  \
                            left,node->left);
      UNITY_TEST_FAIL(lineNo,error);
    }
  else if(balanceFactor != node->balanceFactor){
    error = createMessage("Expected balance factor to be 0x%p, but was %p",  \
                          balanceFactor,node->balanceFactor);
    UNITY_TEST_FAIL(lineNo,error);
  }


  else if(right != node->right){
      error = createMessage("Expected right node to be 0x%p, but was %p",  \
                            right,node->right);
    UNITY_TEST_FAIL(lineNo,error);
    }
}
#include "Rotate.h"


/*      ____________________________________________________________________________________________
 *     |_Current_Node_|__Child_Node_| G.Child_Node |________Action________|_Root_|_Child_|_G.Child_|
 *     |_______+2_____|_(R)__+1_____|______X_______|________Rotate_Left___|___0__|___0___|____X____|
 *     |_______+2_____|_(R)___0_____|______X_______|________Rotate_Left___|__1__|___-1___|____X____|
 *     |_______+2_____|_(R)__-1_____|_____-1_______|___Rotate_RightLeft___|___0__|___1___|____0____|
 *     |_______+2_____|_(R)__-1_____|______0_______|___Rotate_RightLeft___|___0__|___0___|____0____|
 *     |_______+2_____|_(R)__-1_____|_____+1_______|___Rotate_RightLeft___|__-1__|___0___|____0____|
 *     |_______-2_____|_(L)__-1_____|______X_______|________Rotate_right__|___0__|___0___|____X____|
 *     |_______-2_____|_(L)___0_____|______X_______|________Rotate_right__|__-1__|__1____|____X____|
 *     |_______-2_____|_(L)__+1_____|_____+1_______|___Rotate_LeftRight___|___0__|__-1___|____0____|
 *     |_______-2_____|_(L)__+1_____|______0_______|___Rotate_LeftRight___|___0__|___0___|____0____|
 *     |_______-2_____|_(L)__+1_____|_____-1_______|___Rotate_LeftRight___|___1__|___0___|____0____|
 *
 *
 */
void printTraversalPostorder(Node *node){
  if(node->left!=NULL)
    printTraversalPostorder(node->left);
  if(node->right!=NULL)
    printTraversalPostorder(node->right);
  printf("%d",node->data);
}

Node* rotateRight(Node *node){
  Node *temp;
  temp=node->left;
  node->left=temp->right;
  temp->right=node;
  return temp;
}

Node* rotateLeft(Node *node){
  Node *temp;
  temp=node->right;
  node->right=temp->left;
  temp->left=node;
  return temp;
}

Node *rotateLeftRight(Node *node){
  Node *root, *child, *grandchild;
  node->left = rotateLeft(node->left);
  root = rotateRight(node);
  return root;
}

Node *rotateRightLeft(Node *node){
  Node *root;
  node->right = rotateRight(node->right);
  root = rotateLeft(node);
  return root;
}/*
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
*/
