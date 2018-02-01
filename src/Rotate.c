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
}
