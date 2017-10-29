#include "add.h"

Node* addNode(Node *addition,Node *node){
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
