#include "unity.h"
#include "Rotate.h"
#include "AVL_Balance.h"
#include <stdio.h>
#include "nodeHelper.h"

void setUp(void)
{
giveInitdata();
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


void test_rotate_leftright(void)
{   Node *root;
    initNode(&node25,NULL,NULL,0);
    initNode(&node40,NULL,NULL,0);
    initNode(&node50,NULL,NULL,0);
    initNode(&node30,&node25,&node40,0);
    initNode(&node10,NULL,&node30,2);
    initNode(&node45,&node10,&node50,-2);

    root =  rotateLeftRight(&node45);
    TEST_ASSERT_EQUAL_PTR(&node30,root);
    TEST_ASSERT_EQUAL_PTR(NULL,node25.left);
    TEST_ASSERT_EQUAL_PTR(NULL,node25.right);
    TEST_ASSERT_EQUAL_PTR(NULL,node50.left);
    TEST_ASSERT_EQUAL_PTR(NULL,node50.right);
    TEST_ASSERT_EQUAL_PTR(NULL,node40.left);
    TEST_ASSERT_EQUAL_PTR(NULL,node40.right);
    TEST_ASSERT_EQUAL_PTR(&node40,node45.left);
    TEST_ASSERT_EQUAL_PTR(&node50,node45.right);
    TEST_ASSERT_EQUAL_PTR(&node10,node30.left);
    TEST_ASSERT_EQUAL_PTR(&node45,node30.right);
    TEST_ASSERT_EQUAL_PTR(&node25,node10.right);
    TEST_ASSERT_EQUAL_PTR(NULL,node10.left);

}
void test_rotate_rightleft(void)
{   Node *root;
    initNode(&node1,NULL,NULL,0);
    initNode(&node20,NULL,NULL,0);
    initNode(&node35,NULL,NULL,0);
    initNode(&node25,&node20,&node35,0);
    initNode(&node40,&node25,NULL,-2);
    initNode(&node5,&node1,&node40,2);

    root =  rotateRightLeft(&node5);
    TEST_ASSERT_EQUAL_PTR(&node25,root);
    TEST_ASSERT_EQUAL_PTR(NULL,node1.left);
    TEST_ASSERT_EQUAL_PTR(NULL,node1.right);
    TEST_ASSERT_EQUAL_PTR(NULL,node20.left);
    TEST_ASSERT_EQUAL_PTR(NULL,node20.right);
    TEST_ASSERT_EQUAL_PTR(NULL,node35.left);
    TEST_ASSERT_EQUAL_PTR(NULL,node35.right);
    TEST_ASSERT_EQUAL_PTR(&node1,node5.left);
    TEST_ASSERT_EQUAL_PTR(&node20,node5.right);
    TEST_ASSERT_EQUAL_PTR(&node40,node25.right);
    TEST_ASSERT_EQUAL_PTR(&node5,node25.left);
    TEST_ASSERT_EQUAL_PTR(&node35,node40.left);
    TEST_ASSERT_EQUAL_PTR(NULL,node40.right);
}

/*
            30(2)                       40(-1)
              \                       /    \
               40(0)     ----------> 30(1) 50
              / \                      \
             35  50                    35
*/
void test_RotateLeft_BF_20x(void)
{
  initNode(&node35,NULL,NULL,0);
  initNode(&node50,NULL,NULL,0);
  initNode(&node40,&node35,&node50,0);
  initNode(&node30,NULL,&node40,2);
  TEST_ASSERT_EQUAL(node30.balanceFactor,2);
  Node *root = &node30;
  avlbalance(&root);
  TEST_ASSERT_EQUAL(node40.balanceFactor,-1);
  TEST_ASSERT_EQUAL(node30.balanceFactor,1);
}
/*
            30(2)                       40(0)
              \                       /    \
               40(1)     ----------> 30(0) 50
                  \
                  50
*/
void test_RotateLeft_BF_21x(void)
{
  Node *root=&node30;
  initNode(&node50,NULL,NULL,0);
  initNode(&node40,NULL,&node50,1);
  initNode(&node30,NULL,&node40,2);
  avlbalance(&root);
  TEST_ASSERT_EQUAL(node40.balanceFactor,0);
  TEST_ASSERT_EQUAL(node30.balanceFactor,0);
}

/*
            30(-2)               10(1)
           /                   /  \
        (0)10     ---------->  5   30(-1)
         / \                      /
         5  20                    20
*/
void test_RotateRight_BF_neg20(void)
{
  Node *root=&node30;
  initNode(&node5,NULL,NULL,0);
  initNode(&node20,NULL,NULL,0);
  initNode(&node10,&node5,&node20,0);
  initNode(&node30,&node10,NULL,-2);

  avlbalance(&root);
  TEST_ASSERT_EQUAL(node10.balanceFactor,1);
  TEST_ASSERT_EQUAL(node5.balanceFactor,0);
  TEST_ASSERT_EQUAL(node30.balanceFactor,-1);
  TEST_ASSERT_EQUAL(node20.balanceFactor,0);
}

/*
            30(-2)                 10(0)
           /                      /  \
        (-1)10     ---------->  5   30(0)
         /
         5
*/
void test_RotateRight_BF_neg2neg1(void)
{
  Node *root=&node30;
  initNode(&node5,NULL,NULL,0);
  initNode(&node10,&node5,NULL,-1);
  initNode(&node30,&node10,NULL,-2);

  avlbalance(&root);
  TEST_ASSERT_EQUAL(node10.balanceFactor,0);
  TEST_ASSERT_EQUAL(node5.balanceFactor,0);
  TEST_ASSERT_EQUAL(node30.balanceFactor,0);
}


void test_rotate_leftright_BF_neg211(void)
{   Node *root=&node50;
    initNode(&node10,NULL,NULL,0);
    initNode(&node40,NULL,NULL,0);
    initNode(&node30,NULL,&node40,1);
    initNode(&node20,&node10,&node30,1);
    initNode(&node60,NULL,NULL,0);
    initNode(&node50,&node20,&node60,-2);

    avlbalance(&root);
    TEST_ASSERT_EQUAL(node10.balanceFactor,0);
    TEST_ASSERT_EQUAL(node40.balanceFactor,0);
    TEST_ASSERT_EQUAL(node60.balanceFactor,0);
    TEST_ASSERT_EQUAL(node20.balanceFactor,-1);
    TEST_ASSERT_EQUAL(node50.balanceFactor,0);
    TEST_ASSERT_EQUAL(node30.balanceFactor,0);
}
void test_rotate_leftright_BF_neg210(void)
{   Node *root=&node50;
    initNode(&node10,NULL,NULL,0);
    initNode(&node30,NULL,NULL,0);
    initNode(&node45,NULL,NULL,0);
    initNode(&node40,&node30,&node45,0);
    initNode(&node20,&node10,&node40,1);
    initNode(&node60,NULL,NULL,0);
    initNode(&node50,&node20,&node60,-2);

    avlbalance(&root);
    TEST_ASSERT_EQUAL(node10.balanceFactor,0);
    TEST_ASSERT_EQUAL(node40.balanceFactor,0);
    TEST_ASSERT_EQUAL(node60.balanceFactor,0);
    TEST_ASSERT_EQUAL(node20.balanceFactor,0);
    TEST_ASSERT_EQUAL(node50.balanceFactor,0);
    TEST_ASSERT_EQUAL(node30.balanceFactor,0);
}
void test_rotate_leftright_BF_neg21neg1(void)
{   Node *root=&node50;
    initNode(&node10,NULL,NULL,0);
    initNode(&node30,NULL,NULL,0);
    initNode(&node40,&node30,NULL,-1);
    initNode(&node20,&node10,&node40,1);
    initNode(&node60,NULL,NULL,0);
    initNode(&node50,&node20,&node60,-2);

    avlbalance(&root);
    TEST_ASSERT_EQUAL(node10.balanceFactor,0);
    TEST_ASSERT_EQUAL(node40.balanceFactor,0);
    TEST_ASSERT_EQUAL(node60.balanceFactor,0);
    TEST_ASSERT_EQUAL(node20.balanceFactor,0);
    TEST_ASSERT_EQUAL(node50.balanceFactor,1);
    TEST_ASSERT_EQUAL(node30.balanceFactor,0);
}

void test_rotate_rightleft_BF_2neg1neg1(void)
{   Node *root=&node20;
    initNode(&node10,NULL,NULL,0);
    initNode(&node30,NULL,NULL,0);
    initNode(&node40,&node30,NULL,-1);
    initNode(&node20,&node10,&node50,2);
    initNode(&node60,NULL,NULL,0);
    initNode(&node50,&node40,&node60,-1);

    avlbalance(&root);
    TEST_ASSERT_EQUAL(node10.balanceFactor,0);
    TEST_ASSERT_EQUAL(node40.balanceFactor,0);
    TEST_ASSERT_EQUAL(node60.balanceFactor,0);
    TEST_ASSERT_EQUAL(node20.balanceFactor,0);
    TEST_ASSERT_EQUAL(node50.balanceFactor,1);
    TEST_ASSERT_EQUAL(node30.balanceFactor,0);
}

void test_rotate_rightleft_BF_2neg10(void)
{   Node *root=&node20;
    initNode(&node10,NULL,NULL,0);
    initNode(&node30,NULL,NULL,0);
    initNode(&node40,&node30,&node45,0);
    initNode(&node20,&node10,&node50,2);
    initNode(&node60,NULL,NULL,0);
    initNode(&node50,&node40,&node60,-1);

    avlbalance(&root);
    TEST_ASSERT_EQUAL(node10.balanceFactor,0);
    TEST_ASSERT_EQUAL(node40.balanceFactor,0);
    TEST_ASSERT_EQUAL(node60.balanceFactor,0);
    TEST_ASSERT_EQUAL(node20.balanceFactor,0);
    TEST_ASSERT_EQUAL(node50.balanceFactor,0);
    TEST_ASSERT_EQUAL(node30.balanceFactor,0);
}

void test_rotate_rightleft_BF_21neg1(void)
{   Node *root=&node20;
    initNode(&node10,NULL,NULL,0);
    initNode(&node30,NULL,NULL,0);
    initNode(&node40,&node30,&node60,1);
    initNode(&node20,&node10,&node40,2);
    initNode(&node50,NULL,NULL,0);
    initNode(&node60,&node50,NULL,-1);

    avlbalance(&root);
    TEST_ASSERT_EQUAL(node10.balanceFactor,0);
    TEST_ASSERT_EQUAL(node40.balanceFactor,0);
    TEST_ASSERT_EQUAL(node60.balanceFactor,-1);
    TEST_ASSERT_EQUAL(node20.balanceFactor,0);
    TEST_ASSERT_EQUAL(node50.balanceFactor,0);
    TEST_ASSERT_EQUAL(node30.balanceFactor,0);
}
