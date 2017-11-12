#include "unity.h"
#include "nodeRemove.h"
#include "stdlib.h"
#include "Node.h"
#include "nodeVerifier.h"
#include "nodeHelper.h"
#include "Rotate.h"
#include "AVL_Balance.h"


void setUp(void)
{
  giveInitdata();
}

void tearDown(void)
{
}

void xtest_findNearest(void)
{
  Node *root;
  Node *root2;
  initNode(&node30,NULL,NULL,0);
  initNode(&node40,&node30,NULL,-1);
  initNode(&node50,&node40,NULL,0);
  root=findNearest(&node50,LEFT);
  TEST_ASSERT_EQUAL_PTR(root,&node30);

  initNode(&node30,NULL,&node40,0);
  initNode(&node40,NULL,&node50,-1);
  initNode(&node50,NULL,NULL,0);
  root=findNearest(&node30,RIGHT);
  TEST_ASSERT_EQUAL_PTR(root,&node50);
}

void xtest_remove(void){
  Node *root;
  Node *root2=&node50;
  initNode(&node30,NULL,NULL,0);
  initNode(&node40,&node30,NULL,-1);
  initNode(&node50,&node40,NULL,-2);

  root=nodeRemove(&root2,40);
  TEST_ASSERT_EQUAL_PTR(root,&node50);
  TEST_ASSERT_EQUAL_NODE(&node30,NULL,-2,&node50);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,-0,&node30);

}
void xtest_remove1(void){
  Node *root;
  Node *root2=&node50;
  initNode(&node30,NULL,NULL,0);
  initNode(&node40,&node30,NULL,-1);
  initNode(&node50,&node40,NULL,-2);

  root=nodeRemove(&root2,30);
  TEST_ASSERT_EQUAL_PTR(root,&node50);
  TEST_ASSERT_EQUAL_NODE(&node40,NULL,-2,&node50);

}
/*
              50
            /   \
          40    60
          / \   /\
        25  45 55  70
        /
      10
*/
void test_remove_70(void){
  Node *root;
  Node *root2=&node50;
  initNode(&node10,NULL,NULL,0);
  initNode(&node25,&node10,NULL,0);
  initNode(&node45,NULL,NULL,0);
  initNode(&node40,&node25,&node45,0);
  initNode(&node55,NULL,NULL,0);
  initNode(&node70,NULL,NULL,0);
  initNode(&node60,&node55,&node70,0);
  initNode(&node50,&node40,&node60,0);
  TEST_ASSERT_EQUAL_PTR(&node70,node60.right);
  root=nodeRemove(&root2,70);
  TEST_ASSERT_EQUAL_PTR(root,&node50);
  TEST_ASSERT_EQUAL_NODE(&node40,&node60,0,&node50);
  //TEST_ASSERT_EQUAL_NODE(&node55,NULL,0,&node60);
}
void test_remove_55(void){
  Node *root;
  Node *root2=&node50;
  initNode(&node10,NULL,NULL,0);
  initNode(&node25,&node10,NULL,0);
  initNode(&node45,NULL,NULL,0);
  initNode(&node40,&node25,&node45,0);
  initNode(&node55,NULL,NULL,0);
  initNode(&node70,NULL,NULL,0);
  initNode(&node60,&node55,&node70,0);
  initNode(&node50,&node40,&node60,0);

  root=nodeRemove(&root2,55);
  TEST_ASSERT_EQUAL_PTR(root,&node50);
  TEST_ASSERT_EQUAL_NODE(&node40,&node60,0,&node50);
  TEST_ASSERT_EQUAL_NODE(NULL,&node70,0,&node60);

}
void test_remove_10(void){
  Node *root;
  Node *root2=&node50;
  initNode(&node10,NULL,NULL,0);
  initNode(&node25,&node10,NULL,0);
  initNode(&node45,NULL,NULL,0);
  initNode(&node40,&node25,&node45,0);
  initNode(&node55,NULL,NULL,0);
  initNode(&node70,NULL,NULL,0);
  initNode(&node60,&node55,&node70,0);
  initNode(&node50,&node40,&node60,0);

  root=nodeRemove(&root2,10);
  TEST_ASSERT_EQUAL_PTR(root,&node50);
  TEST_ASSERT_EQUAL_NODE(&node40,&node60,0,&node50);
  TEST_ASSERT_EQUAL_NODE(&node25,&node45,0,&node40);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node25);
  TEST_ASSERT_EQUAL_NODE(&node55,&node70,0,&node60);
}
void test_remove_45(void){
  Node *root;
  Node *root2=&node50;
  initNode(&node10,NULL,NULL,0);
  initNode(&node25,&node10,NULL,0);
  initNode(&node45,NULL,NULL,0);
  initNode(&node40,&node25,&node45,0);
  initNode(&node55,NULL,NULL,0);
  initNode(&node70,NULL,NULL,0);
  initNode(&node60,&node55,&node70,0);
  initNode(&node50,&node40,&node60,0);

  root=nodeRemove(&root2,45);
  TEST_ASSERT_EQUAL_PTR(root,&node50);
  TEST_ASSERT_EQUAL_NODE(&node40,&node60,0,&node50);
  TEST_ASSERT_EQUAL_NODE(&node25,NULL,0,&node40);
  TEST_ASSERT_EQUAL_NODE(&node55,&node70,0,&node60);
}
void test_remove_25(void){
  Node *root;
  Node *root2=&node50;
  initNode(&node10,NULL,NULL,0);
  initNode(&node25,&node10,NULL,0);
  initNode(&node45,NULL,NULL,0);
  initNode(&node40,&node25,&node45,0);
  initNode(&node55,NULL,NULL,0);
  initNode(&node70,NULL,NULL,0);
  initNode(&node60,&node55,&node70,0);
  initNode(&node50,&node40,&node60,0);


  root=nodeRemove(&root2,25);
  TEST_ASSERT_EQUAL_PTR(root,&node50);
  TEST_ASSERT_EQUAL_NODE(&node40,&node60,0,&node50);
  TEST_ASSERT_EQUAL_NODE(&node10,&node45,0,&node40);
  TEST_ASSERT_EQUAL_NODE(&node55,&node70,0,&node60);
}
void test_remove_60(void){
  Node *root;
  Node *root2=&node50;
  initNode(&node10,NULL,NULL,0);
  initNode(&node25,&node10,NULL,0);
  initNode(&node45,NULL,NULL,0);
  initNode(&node40,&node25,&node45,0);
  initNode(&node55,NULL,NULL,0);
  initNode(&node70,NULL,NULL,0);
  initNode(&node60,&node55,&node70,0);
  initNode(&node50,&node40,&node60,0);


  root=nodeRemove(&root2,60);
  TEST_ASSERT_EQUAL_PTR(root,&node50);
  TEST_ASSERT_EQUAL_NODE(&node40,&node70,0,&node50);
  TEST_ASSERT_EQUAL_NODE(&node55,NULL,0,&node70);
  TEST_ASSERT_EQUAL_NODE(&node55,&node70,0,&node60);
}
void test_remove_40(void){
  Node *root;
  Node *root2=&node50;
  initNode(&node10,NULL,NULL,0);
  initNode(&node25,&node10,NULL,0);
  initNode(&node45,NULL,NULL,0);
  initNode(&node40,&node25,&node45,0);
  initNode(&node55,NULL,NULL,0);
  initNode(&node70,NULL,NULL,0);
  initNode(&node60,&node55,&node70,0);
  initNode(&node50,&node40,&node60,0);


  root=nodeRemove(&root2,40);
  TEST_ASSERT_EQUAL_PTR(root,&node50);
  TEST_ASSERT_EQUAL_NODE(&node45,&node60,0,&node50);
  TEST_ASSERT_EQUAL_PTR(&node25,node45.left);
  TEST_ASSERT_EQUAL_PTR(NULL,node45.right);
  TEST_ASSERT_EQUAL_NODE(&node25,NULL,0,&node45);
  TEST_ASSERT_EQUAL_NODE(&node55,&node70,0,&node60);
}
void test_remove_root(void){
  Node *root;
  initNode(&node55,NULL,NULL,0);
  root=removeRoot(&node55);
}

void test_remove_50(void){
  Node *root;
  Node *root2=&node50;
  initNode(&node10,NULL,NULL,0);
  initNode(&node25,&node10,NULL,0);
  initNode(&node45,NULL,NULL,0);
  initNode(&node40,&node25,&node45,0);
  initNode(&node55,NULL,NULL,0);
  initNode(&node70,NULL,NULL,0);
  initNode(&node60,&node55,&node70,0);
  initNode(&node50,&node40,&node60,0);

  root=nodeRemove(&root2,50);
  TEST_ASSERT_EQUAL_PTR(root,&node55);
  TEST_ASSERT_EQUAL_NODE(&node40,&node60,0,&node55);
  TEST_ASSERT_EQUAL_NODE(&node25,&node45,0,&node40);
  TEST_ASSERT_EQUAL_NODE(&node55,&node70,0,&node60);
}
