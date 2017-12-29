#include "unity.h"
#include "AVLString.h"
#include "addNode.h"
#include "stdlib.h"
#include "Node.h"
#include "nodeVerifier.h"
#include "nodeHelper.h"
#include "Rotate.h"
#include "AVL_Balance.h"
#include "nodeRemove.h"
#include "CException.h"
#include "exception.h"
void setUp(void)
{
  giveInitString();
}

void tearDown(void)
{
}

void test_AVLStringCompare(void)
{

  int x=stringCompare("Ali",&nodeAbu);
  int y=stringCompare("Ali",&nodeAmin);
  int z=stringCompare("Xaxa",&nodeXaxa);
  TEST_ASSERT_EQUAL(x,1);
  TEST_ASSERT_EQUAL(y,-1);
  TEST_ASSERT_EQUAL(z,0);
}

void test_AVL_StringAdd(void){
  initNode(&nodeAli,NULL,NULL,0);
  initNode(&nodeAmin,NULL,NULL,0);
  Node *root = &nodeAli;

  avlAddString(&root,&nodeAmin);
  TEST_ASSERT_EQUAL_PTR(root,&nodeAli);
  TEST_ASSERT_EQUAL_NODE(NULL,&nodeAmin,1,&nodeAli);
  avlAddString(&root,&nodeAbu);
  TEST_ASSERT_EQUAL_PTR(root,&nodeAli);
  TEST_ASSERT_EQUAL_NODE(&nodeAbu,&nodeAmin,0,&nodeAli);
}

void test_AVL_StringRemove(void){
  initNode(&nodeAli,&nodeAbu,&nodeAmin,0);
  initNode(&nodeAmin,NULL,NULL,0);
  initNode(&nodeAbu,NULL,NULL,0);
  Node *root = &nodeAli;

  avlRemoveString(&root,"Amin");
  TEST_ASSERT_EQUAL_PTR(root,&nodeAli);
  TEST_ASSERT_EQUAL_PTR(&nodeAbu,nodeAli.left);
  TEST_ASSERT_EQUAL_PTR(NULL,nodeAli.right);
  TEST_ASSERT_EQUAL_NODE(&nodeAbu,NULL,-1,&nodeAli);
  avlRemoveString(&root,"Abu");
  TEST_ASSERT_EQUAL_PTR(root,&nodeAli);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&nodeAli);
}
