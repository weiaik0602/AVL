#include "unity.h"
#include "AVLInteger.h"
#include "addNode.h"
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

void test_AVLInteger_NeedToImplement(void)
{
  initNode(&node30,NULL,NULL,0);
  initNode(&node40,&node30,NULL,-1);

  int x=integerCompare(30,&node40);
  int y=integerCompare(40,&node30);
  TEST_ASSERT_EQUAL(x,-1);
  TEST_ASSERT_EQUAL(y,1);
}
