#include "unity.h"
#include "addNode.h"
#include "stdlib.h"
#include "Node.h"
#include "nodeVerifier.h"
#include "nodeHelper.h"
#include "Rotate.h"
#include "AVL_Balance.h"
/**
---------rotateLeft----------------------
*        30 +2                     40
*       /  \                     /   \
*      25   40 +1   ------->    30    50
*           / \                /     /  \
*          45   50            25    45   60
*                \
*                 60
**/

void setUp(void)
{
  giveInitdata();
}

void tearDown(void){
};

  void test_insert_given_40_30_insert_20_expect_balance(void){

  initNode(&node30,NULL,NULL,0);
  initNode(&node40,&node30,NULL,-1);

  Node *root = &node40;
  addNode(&root,&node20);
  TEST_ASSERT_EQUAL_PTR(&node30,root);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node40);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node20);
  TEST_ASSERT_EQUAL_NODE(&node20,&node40,0,&node30);

}



/**
---------test_givenewNode-----------------
*
*
*      10     -> + 2     10
*     / \               / \
*    5  20             5  20
*                     /
*                    2
void test_inset_newNode(void)
{   Node *root;
    root = GiveNewNode(100);
    TEST_ASSERT_EQUAL(0,root->bf);
    TEST_ASSERT_EQUAL_PTR(NULL,root->left);
    TEST_ASSERT_EQUAL_PTR(NULL,root->right);
}
**/
/**
----------------test_addNode_right----------
*        10            10
*         \           /   \
*          30  ->    5    30
*
**/
void test_addNode_right(void){
   Node *root = &node10;
    initNode(&node10,NULL,&node30,1);

    addNode(&root,&node5);
    TEST_ASSERT_EQUAL_PTR(&node10,root);
    TEST_ASSERT_EQUAL_PTR(&node5,node10.left);
    TEST_ASSERT_EQUAL_PTR(&node30,node10.right);

}

/**
----------------test_addNode_left----------
*        10              10
*       /  \           /   \
*      5       ->    5     30
*
**/
void test_addNode_left(void)
{   Node *root = &node10;
    initNode(&node10,&node5,NULL,-1);

    addNode(&root,&node30);
    TEST_ASSERT_EQUAL_PTR(&node10,root);
    TEST_ASSERT_EQUAL_PTR(&node5,node10.left);
    TEST_ASSERT_EQUAL_PTR(&node30,node10.right);

}
/**
----------------test_addNode_leftChild_left----------
*        10              10
*       /  \           /   \
*      5    30   ->   5     30
*                    /
*                   1
**/
void test_addNode_1_t0_5_leftchild(void)
{   Node *root = &node10;
    initNode(&node10,&node5,&node30,0);
    initNode(&node5,NULL,NULL,0);

    addNode(&root,&node1);
    TEST_ASSERT_EQUAL_PTR(&node10,root);
    TEST_ASSERT_EQUAL_PTR(&node1,node5.left);
    TEST_ASSERT_EQUAL_PTR(&node30,node10.right);
    TEST_ASSERT_EQUAL_PTR(&node5,node10.left);

}

void test_addNode_40_t0_30_rightchild(void)
{   Node *root = &node10;
    initNode(&node10,&node5,&node30,0);
    initNode(&node5,NULL,NULL,0);
    initNode(&node30,NULL,NULL,0);

    addNode(&root,&node40);
    TEST_ASSERT_EQUAL_PTR(&node10,root);
    TEST_ASSERT_EQUAL_PTR(NULL,node5.left);
    TEST_ASSERT_EQUAL_PTR(NULL,node5.right);
    TEST_ASSERT_EQUAL_PTR(&node40,node30.right);
    TEST_ASSERT_EQUAL_PTR(&node30,node10.right);
    TEST_ASSERT_EQUAL_PTR(&node5,node10.left);

}