#include "unity.h"
#include "Rotate.h"
#include <stdio.h>

Node node1, node5,node10,node15,node20,node25,node30,node35,node40,node45,node50;

void initNode(Node *node,Node *Left, Node *Right, int bf){
  node->left=Left;
  node->right=Right;
  node->balancefactor=bf;
}
void setUp(void)
{
  node1.data=1;
  node5.data=5;
  node10.data=10;
  node15.data=15;
  node20.data=20;
  node25.data=25;
  node30.data=30;
  node35.data=35;
  node40.data=40;
  node45.data=45;
  node50.data=50;
}

void tearDown(void)
{
}

/*
            30                  10
           /                   /  \
          10     ---------->  5   30
         / \                      /
         5  20                    20
*/
void test_RotateRight(void)
{
  Node *root;
  initNode(&node5,NULL,NULL,0);
  initNode(&node20,NULL,NULL,0);
  initNode(&node10,&node5,&node20,0);
  initNode(&node30,&node10,NULL,2);

  root=rotateRight(&node30);
  TEST_ASSERT_EQUAL_PTR(&node10,root);
  TEST_ASSERT_EQUAL_PTR(NULL,node20.left);
  TEST_ASSERT_EQUAL_PTR(NULL,node20.right);
  TEST_ASSERT_EQUAL_PTR(NULL,node5.left);
  TEST_ASSERT_EQUAL_PTR(NULL,node5.right);
  TEST_ASSERT_EQUAL_PTR(&node20,node30.left);
  TEST_ASSERT_EQUAL_PTR(NULL,node30.right);
  TEST_ASSERT_EQUAL_PTR(&node5,node10.left);
  TEST_ASSERT_EQUAL_PTR(&node30,node10.right);
}



/*
            30                         40
              \                       /  \
               40     ---------->    30   50
              / \                      \
             35  50                    35
*/
void test_RotateLeft(void)
{
  Node *root;
  initNode(&node35,NULL,NULL,0);
  initNode(&node50,NULL,NULL,0);
  initNode(&node40,&node35,&node50,0);
  initNode(&node30,NULL,&node40,2);

  root=rotateLeft(&node30);
  TEST_ASSERT_EQUAL_PTR(&node40,root);
  TEST_ASSERT_EQUAL_PTR(NULL,node35.left);
  TEST_ASSERT_EQUAL_PTR(NULL,node35.right);
  TEST_ASSERT_EQUAL_PTR(NULL,node50.left);
  TEST_ASSERT_EQUAL_PTR(NULL,node50.right);
  TEST_ASSERT_EQUAL_PTR(&node35,node30.right);
  TEST_ASSERT_EQUAL_PTR(NULL,node30.left);
  TEST_ASSERT_EQUAL_PTR(&node30,node40.left);
  TEST_ASSERT_EQUAL_PTR(&node50,node40.right);
}
