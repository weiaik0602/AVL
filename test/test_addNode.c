#include "unity.h"
#include "addNode.h"
#include "stdlib.h"
#include "Node.h"
#include "nodeVerifier.h"
#include "nodeHelper.h"
#include "Rotate.h"
#include "AVL_Balance.h"
#include "AVLInteger.h"
#include "CException.h"
#include "exception.h"
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
  root=avlAddInteger(&root,&node20);
  TEST_ASSERT_EQUAL_PTR(&node30,root);
  TEST_ASSERT_EQUAL_NODE(&node20,&node40,0,&node30);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node40);

}


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
    initNode(&node30,NULL,NULL,0);

    root=avlAddInteger(&root,&node5);
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
    initNode(&node30,NULL,NULL,0);

    root=avlAddInteger(&root,&node30);
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

    root=avlAddInteger(&root,&node1);
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

    root=avlAddInteger(&root,&node40);
    TEST_ASSERT_EQUAL_PTR(&node10,root);
    TEST_ASSERT_EQUAL_PTR(NULL,node5.left);
    TEST_ASSERT_EQUAL_PTR(NULL,node5.right);
    TEST_ASSERT_EQUAL_PTR(&node40,node30.right);
    TEST_ASSERT_EQUAL_PTR(&node30,node10.right);
    TEST_ASSERT_EQUAL_PTR(&node5,node10.left);

}

void test_addNode_duplicate(void)
{
    CEXCEPTION_T   ex;
    Node *root = &node10;
    initNode(&node10,&node5,&node30,-1);
    initNode(&node5,&node1,NULL,-1);
    initNode(&node30,NULL,NULL,0);
    Try{
    root=avlAddInteger(&root,&node1);
    }
    Catch(ex)
    {
      dumpException((Exception *)ex);
    }
    TEST_ASSERT_EQUAL_PTR(&node10,root);
    TEST_ASSERT_EQUAL_NODE(&node5,&node30,-1,&node10);
    TEST_ASSERT_EQUAL_NODE(&node1,NULL,-1,&node5);
}
void test_Functional_addNode(void){
  Node *root = NULL;
  initNode(&node5,NULL,NULL,0);
  initNode(&node25,NULL,NULL,0);
  initNode(&node40,NULL,NULL,0);
  initNode(&node50,NULL,NULL,0);
  initNode(&node55,NULL,NULL,0);

  root=avlAddInteger(&root,&node5);
  root=avlAddInteger(&root,&node25);
  root=avlAddInteger(&root,&node40);
  root=avlAddInteger(&root,&node50);
  root=avlAddInteger(&root,&node55);


  TEST_ASSERT_EQUAL_PTR(&node25,root);
  TEST_ASSERT_EQUAL(node25.balanceFactor,1);
  TEST_ASSERT_EQUAL_PTR(&node5,node25.left);
  TEST_ASSERT_EQUAL_PTR(&node50,node25.right);
  TEST_ASSERT_EQUAL_PTR(&node40,node50.left);
  TEST_ASSERT_EQUAL_PTR(&node55,node50.right);
  TEST_ASSERT_EQUAL(node50.balanceFactor,0);
  TEST_ASSERT_EQUAL(node40.balanceFactor,0);
}
