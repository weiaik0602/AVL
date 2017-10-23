#include "unity.h"
#include "Rotate.h"


Node node1, node5,node10,node15,node20,node25,node30,node35,node40,node45,node50;

void initNode(Node *node,Node *Left, Node *Right, int bf){
  node->Left=Left;
  node->Right=Right;
  node->balancefactor=bf;
}
void setUp(void)
{
  node1.Data=1;
  node5.Data=5;
  node10.Data=10;
  node15.Data=15;
  node20.Data=20;
  node25.Data=25;
  node30.Data=30;
  node35.Data=35;
  node40.Data=40;
  node45.Data=45;
  node50.Data=50;
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
void test_RotateLeft(void)
{
  initNode(&node5,NULL,NULL,0);
  initNode(&node20,NULL,NULL,0);
  initNode(&node10,&node5,&node20,0);
  initNode(&node30,&node10,NULL,2)
}
