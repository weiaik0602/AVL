#include "add.h"

Node* addNode(Node *addition,Node *node){
  if((node->left!=NULL)&&(addition->data)>(node->data)){
    addNode(addition,node->left);
    //node->left=addition;
  }
  if(node->left==NULL)
  node->left=addition;

  if((node->right!=NULL)&&(addition->data)<(node->data)){
    addNode(addition,node->right);
    // /node->right=addition;
  }
  if(node->right==NULL)
  node->right=addition;

}
