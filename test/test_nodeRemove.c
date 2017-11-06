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

void test_findNearest(void)
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

void test_remove(void){
  Node *root;
  Node *root2=&node50;
  initNode(&node30,NULL,NULL,0);
  initNode(&node40,&node30,NULL,-1);
  initNode(&node50,&node40,NULL,-2);

  root=nodeRemove(&root2,40);
  TEST_ASSERT_EQUAL_PTR(root,&node30);
}
