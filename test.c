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
#include "unity.h"
#include "AVLInteger.h"
#include "addNode.h"
#include "stdlib.h"
#include "Node.h"
#include "nodeVerifier.h"
#include "nodeHelper.h"
#include "Rotate.h"
#include "AVL_Balance.h"
#include "CException.h"
#include "exception.h"
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
#include "unity.h"
#include "nodeRemove.h"
#include "stdlib.h"
#include "Node.h"
#include "nodeVerifier.h"
#include "nodeHelper.h"
#include "Rotate.h"
#include "AVL_Balance.h"
#include "AVLInteger.h"
#include "CException.h"
#include "exception.h"

void setUp(void)
{
  giveInitdata();
}

void tearDown(void)
{
}


/**
---------------------------------------------------------------------

-----------------remove 40----------------------
*                   remove 40
*        40 (0) ------------------>  NULL
*
**/
void test_nodeRemove_given_40_remove_expect_NULL(void){
    initNode(&node40,NULL,NULL,0);

    Node *root = &node40;
    root=avlRemoveInteger(&root,40);
    TEST_ASSERT_EQUAL_PTR(NULL,root);
}
/**
---------------------------------remove 30------------------------------
*       40(-1)                        40 (0)
*       /          remove 40
*     30 (0)  --------------->
*
*/
void test_nodeRemove_given_40_with_child_30_delete_40_expect_30_only(void){

    initNode(&node30,NULL,NULL,0);
    initNode(&node40,&node30,NULL,-1);

    Node *root = &node40;
    avlRemoveInteger(&root,40);
    TEST_ASSERT_EQUAL_PTR(&node30,root);
    TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node30);
}
void test_nodeRemove_given_40_with_child_30_delete_30_expect_40_only(void){

    initNode(&node30,NULL,NULL,0);
    initNode(&node40,&node30,NULL,-1);

    Node *root = &node40;
    avlRemoveInteger(&root,30);
    TEST_ASSERT_EQUAL_PTR(&node40,root);
    TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node40);
}

/**
---------------------------------remove 50------------------------------
*       40(0)                              40 (-1)
*       / \          remove 50            /
*   30 (0) 50(0)   --------------->     30(0)
*
**/
void test_nodeRemove_given_40_with_child_30_50__delete_50_expect_40_30(void){

    initNode(&node50,NULL,NULL,0);
    initNode(&node30,NULL,NULL,0);
    initNode(&node40,&node30,&node50,0);

    Node *root = &node40;
    avlRemoveInteger(&root,50);
    TEST_ASSERT_EQUAL_PTR(&node40,root);
    TEST_ASSERT_EQUAL_NODE(&node30,NULL,-1,&node40);
}

/**
---------------------------------remove 50------------------------------
*       40(-1)                            40 (-2)                                  30 (0)
*       / \          remove 50          /                 rotate right           /  \
*   30 (-1) 50(0)   --------------->   30(-1)            ------------>         20(0) 40 (0)
*   /                                 /
*  20(0)                             20(0)
*
**/
void test_nodeRemove_after_remove_rotate_right(void){

    initNode(&node50,NULL,NULL,0);
    initNode(&node20,NULL,NULL,0);
    initNode(&node30,&node20,NULL,-1);
    initNode(&node40,&node30,&node50,-1);

    Node *root = &node40;
    root=avlRemoveInteger(&root,50);
    TEST_ASSERT_EQUAL_PTR(&node30,root);
    TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node40);
    TEST_ASSERT_EQUAL_NODE(&node20,&node40,0,&node30);
}
/**
---------------------------------remove 50------------------------------
*       40(-1)                            40 (-2)                                  30 (1)
*       / \          remove 50          /                 rotate right           /  \
*   30 (0) 50(0)   --------------->   30(0)            ------------>          20     40 (-1)
*   / \                               / \                                            /
*  20  35                           20  35                                          35
*
**/
void test_nodeRemove_after_remove_rotate_right_condition2(void){

    initNode(&node50,NULL,NULL,0);
    initNode(&node35,NULL,NULL,0);
    initNode(&node20,NULL,NULL,0);
    initNode(&node30,&node20,&node35,0);
    initNode(&node40,&node30,&node50,-1);

    Node *root = &node40;
    root=avlRemoveInteger(&root,50);
    TEST_ASSERT_EQUAL_PTR(&node30,root);
    TEST_ASSERT_EQUAL_NODE(&node35,NULL,-1,&node40);
    TEST_ASSERT_EQUAL_NODE(&node20,&node40,1,&node30);
}
/**
---------------------------------remove 100       &           rotateLeftRight--------------------------------
*           90(-1)                            90 (-2)                                        60 (0)
*          / \          remove 100            /  \               rotateleftright           /  \
*       50 (1) 95(1)   --------------->   50(1)   95[0]         ---------------->   (-1) 50  90 (0)
*      / \     \                            / \                                          /    / \
*  45   60 (1)   100(0)                    45  60 (1)                                   45   70   95
*  (0)   \                                 (0)   \
*        70(0)                                   70(0)
*
**/
void test_remove_given_a_avltree_need_rotateLeftRight_after_remove_condition1_expect_balance(void){

     initNode(&node45,NULL,NULL,0);
     initNode(&node70,NULL,NULL,0);
     initNode(&node100,NULL,NULL,0);
     initNode(&node90,&node50,&node95,-1);
     initNode(&node95,NULL,&node100,1);
     initNode(&node50,&node45,&node60,1);
     initNode(&node60,NULL,&node70,1);

     Node *root = &node90;
     root=avlRemoveInteger(&root,100);
     TEST_ASSERT_EQUAL_PTR(&node60,root);
     TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node45);
     TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node70);
     TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node95);
     TEST_ASSERT_EQUAL_NODE(&node50,&node90,0,&node60);
     TEST_ASSERT_EQUAL_NODE(&node45,NULL,-1,&node50);
     TEST_ASSERT_EQUAL_NODE(&node70,&node95,0,&node90);
}
/**
---------------------------------remove 100       &           rotateLeftRight--------------------------------
*           90(-1)                            90 (-2)                                        60 (0)
*          / \          remove 100            /  \               rotateleftright           /  \
*       50 (1) 95(1)   --------------->   50(1)   95[0]         ---------------->      (0)50   90 (1)
*      / \     \                            / \                                          / \     \
*  45   60 (-1) 100(0)                    45  60 (-1)                                   45  55    95
*        /                                     /
*       55                                    55
*
**/
void test_remove_given_a_avltree_need_rotateLeftRight_after_remove_condition2_expect_balance(void){

     initNode(&node45,NULL,NULL,0);
     initNode(&node55,NULL,NULL,0);
     initNode(&node100,NULL,NULL,0);
     initNode(&node95,NULL,&node100,1);
     initNode(&node90,&node50,&node95,-1);
     initNode(&node50,&node45,&node60,1);
     initNode(&node60,&node55,NULL,-1);

     Node *root = &node90;
     root=avlRemoveInteger(&root,100);
     TEST_ASSERT_EQUAL_PTR(&node60,root);
     TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node45);
     TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node55);
     TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node95);
     TEST_ASSERT_EQUAL_NODE(&node50,&node90,0,&node60);
     TEST_ASSERT_EQUAL_NODE(&node45,&node55,0,&node50);
     TEST_ASSERT_EQUAL_NODE(NULL,&node95,1,&node90);

}
/**
---------------------------------remove 100       &           rotateLeftRight--------------------------------
*           90(-1)                            90 (-2)                                        60 (0)
*          / \          remove 100            /  \               rotateleftright           /  \
*       50 (1) 95(1)   --------------->   50(1)   95[0]         ---------------->      (0)50   90 (0)
*      / \     \                            / \                                          / \   / \
*  45   60 (0) 100(0)                    45  60 (-1)                                   45  55 70 95
*        / \                                 /  \
*       55  70                              55  70
*
**/
void test_remove_given_a_avltree_need_rotateLeftRight_after_remove_condition3_expect_balance(void){

     initNode(&node45,NULL,NULL,0);
     initNode(&node55,NULL,NULL,0);
     initNode(&node100,NULL,NULL,0);
     initNode(&node70,NULL,NULL,0);
     initNode(&node95,NULL,&node100,1);
     initNode(&node90,&node50,&node95,-1);
     initNode(&node50,&node45,&node60,1);
     initNode(&node60,&node55,&node70,0);

     Node *root = &node90;
     root=avlRemoveInteger(&root,100);
     TEST_ASSERT_EQUAL_PTR(&node60,root);
     TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node45);
     TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node55);
     TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node95);
     TEST_ASSERT_EQUAL_NODE(&node50,&node90,0,&node60);
     TEST_ASSERT_EQUAL_NODE(&node45,&node55,0,&node50);
     TEST_ASSERT_EQUAL_NODE(&node70,&node95,0,&node90);

}
/**
---------------------------------remove 30 and rotateLeft---------------------------------
*        40 (1)                            40 (+2)                             50(0)
*       /   \           remove 30            \                 rotate left    /   \
*     30     50 (+1)   ---------->            50(1)        -------------->  40    100
*            \                                 \                              (0) (0)
*            100                               100(0)
*
**/
void test_remove_rotateleft1(void){

    initNode(&node30,NULL,NULL,0);
    initNode(&node100,NULL,NULL,0);
    initNode(&node50,NULL,&node100,1);
    initNode(&node40,&node30,&node50,1);

    Node *root = &node40;
    root=avlRemoveInteger(&root,30);
    TEST_ASSERT_EQUAL_PTR(&node50,root);
    TEST_ASSERT_EQUAL_NODE(&node40,&node100,0,&node50);
    TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node40);
    TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node100);

}

/**
---------------------------------remove 30 and rotateLeft---------------------------------
*        40 (1)                            40 (+2)                             50(-1)
*       /   \           remove 30            \                 rotate left    /   \
*   (0)30    50(0)   ---------->             50(0)        -------------->  40(1)    100(0)
*            /\                              /   \                          \
*          45  100                         45   100                         45
*
**/
void test_remove_rotateleft2(void){

    initNode(&node30,NULL,NULL,0);
    initNode(&node100,NULL,NULL,0);
    initNode(&node45,NULL,NULL,0);
    initNode(&node50,&node45,&node100,0);
    initNode(&node40,&node30,&node50,1);

    Node *root = &node40;
    root=avlRemoveInteger(&root,30);
    TEST_ASSERT_EQUAL_PTR(&node50,root);
    TEST_ASSERT_EQUAL_NODE(&node40,&node100,-1,&node50);
    TEST_ASSERT_EQUAL_NODE(NULL,&node45,1,&node40);
    TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node100);


}
/**
---------------------------------remove 15 and rotateLeft---------------------------------
*        30 (1)                            30 (2)                                  40(0)
*       /   \           remove 15         /  \                 rotateRightleft    /   \
* (-1)20     50 (-1)   ------------>    20    50(-1)        ----------------    30(0)  50(1)
*    /       /\                              /   \                             / \      \
*  15   (-1)40 100                      (-1)40   100(0)                      20 35      100
*         /                                /
*       35                               35
*
*
**/

void test_remove_given_Avl_tree_remove_15_then_rotaterightleft_condition1_(void){
     initNode(&node15,NULL,NULL,0);
     initNode(&node35,NULL,NULL,0);
     initNode(&node100,NULL,NULL,0);
     initNode(&node40,&node35,NULL,-1);
     initNode(&node50,&node40,&node100,-1);
     initNode(&node30,&node20,&node50,1);
     initNode(&node20,&node15,NULL,-1);

     Node *root = &node30;
     root=avlRemoveInteger(&root,15);
     TEST_ASSERT_EQUAL_PTR(&node40,root);
     TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node20);
     TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node35);
     TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node100);
     TEST_ASSERT_EQUAL_NODE(&node30,&node50,0,&node40);
     TEST_ASSERT_EQUAL_NODE(NULL,&node100,1,&node50);
     TEST_ASSERT_EQUAL_NODE(&node20,&node35,0,&node30);
}
/**
---------------------------------remove 15 and rotateLeft---------------------------------
*        30 (1)                            30 (2)                                   40(0)
*       /   \           remove 15         /  \                 rotateRightleft    /   \
*  (-1)20    50(-1)   ------------>  (0)20    50(-1)        ----------------   30     50
*    /       /\                              /   \                             / \    / \
*  15    (0)40  100                       (0)40   100                          20 35  45 100
*         / \                             / \
*       35  45                           35 45
*
*
**/
void test_remove_given_Avl_tree_remove_15_then_rotaterightleft_condition2_(void){

     initNode(&node15,NULL,NULL,0);
     initNode(&node45,NULL,NULL,0);
     initNode(&node35,NULL,NULL,0);
     initNode(&node100,NULL,NULL,0);
     initNode(&node40,&node35,&node45,0);
     initNode(&node50,&node40,&node100,-1);
     initNode(&node30,&node20,&node50,1);
     initNode(&node20,&node15,NULL,-1);

     Node *root = &node30;
     root=avlRemoveInteger(&root,15);
     TEST_ASSERT_EQUAL_PTR(&node40,root);
     TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node20);
     TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node35);
     TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node100);
     TEST_ASSERT_EQUAL_NODE(&node30,&node50,0,&node40);
     TEST_ASSERT_EQUAL_NODE(&node45,&node100,0,&node50);
     TEST_ASSERT_EQUAL_NODE(&node20,&node35,0,&node30);
}
/**
---------------------------------remove 15 and rotateLeft---------------------------------
*        30 (1)                            30 (2)                                   40
*       /   \           remove 15         /  \                 rotateRightleft    /   \
*  (-1)20    50(-1)   ------------>    20    50(-1)        ----------------   30     50
*    /       /\                              /   \                             /     /  \
*  15    (1)40  100                       (1)40   100                          20   45   100
*           \                                 \
*           45                                45
*
*
**/
void test_remove_given_Avl_tree_remove_15_then_rotaterightleft_condition3_(void){

     initNode(&node15,NULL,NULL,0);
     initNode(&node45,NULL,NULL,0);
     initNode(&node100,NULL,NULL,0);
     initNode(&node40,NULL,&node45,1);
     initNode(&node50,&node40,&node100,-1);
     initNode(&node30,&node20,&node50,1);
     initNode(&node20,&node15,NULL,-1);

     Node *root = &node30;
     root=avlRemoveInteger(&root,15);
     TEST_ASSERT_EQUAL_PTR(&node40,root);
     TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node20);
     TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node35);
     TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node100);
     TEST_ASSERT_EQUAL_NODE(&node30,&node50,0,&node40);
     TEST_ASSERT_EQUAL_NODE(&node45,&node100,0,&node50);
     TEST_ASSERT_EQUAL_NODE(&node20,NULL,-1,&node30);
}
/**
-----------------------------------------------------------------------------------------
*        30 (1)                            40 (0)
*       /   \           remove 30         /    \
*  (-1)20     50 (-1)   ------------> (-1)20    50(0)
*    /       /\                         /     /   \
*  15   (1)40  100                     15    45   100
*           \
*           45
*
*
**/
void test_remove_30(void){

     initNode(&node15,NULL,NULL,0);
     initNode(&node45,NULL,NULL,0);
     initNode(&node100,NULL,NULL,0);
     initNode(&node40,NULL,&node45,1);
     initNode(&node50,&node40,&node100,-1);
     initNode(&node30,&node20,&node50,1);
     initNode(&node20,&node15,NULL,-1);

     Node *root = &node30;
     root=avlRemoveInteger(&root,30);
     TEST_ASSERT_EQUAL_PTR(&node40,root);
     TEST_ASSERT_EQUAL_NODE(&node15,NULL,-1,&node20);
     TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node45);
     TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node100);
     TEST_ASSERT_EQUAL_NODE(&node20,&node50,0,&node40);
     TEST_ASSERT_EQUAL_PTR(&node45,node50.left);
     TEST_ASSERT_EQUAL_PTR(&node100,node50.right);
     TEST_ASSERT_EQUAL(0,node50.balanceFactor);
     TEST_ASSERT_EQUAL_NODE(&node45,&node100,0,&node50);
}

/**
---------------------------------remove 15 and rotateLeft---------------------------------
*        30 (1)                            50 (0)
*       /   \           remove 30         /  \
*     20     50 (1)   ------------>    20    100(0)
*             \
*            100
*
*
*
*
**/
void test_remove_given_Avl_tree_remove_30_50_movedUP(void){

     initNode(&node100,NULL,NULL,0);
     initNode(&node50,NULL,&node100,1);
     initNode(&node30,&node20,&node50,1);
     initNode(&node20,NULL,NULL,0);

     Node *root = &node30;
     root=avlRemoveInteger(&root,30);
     TEST_ASSERT_EQUAL_PTR(&node50,root);
     TEST_ASSERT_EQUAL_NODE(&node20,&node100,0,&node50);
}
/**
---------------------------------remove 15 and rotateLeft---------------------------------
*        30 (1)                            40 (1)
*       /   \           remove 30         /  \
*     20     50 (0)   ------------>    20    50(1)
*            / \                              \
*           40 100                            100
*
*
*
*
**/
void test_remove_given_Avl_tree_remove_30_40_movedUP(void){

     initNode(&node100,NULL,NULL,0);
     initNode(&node50,&node40,&node100,0);
     initNode(&node30,&node20,&node50,1);
     initNode(&node40,NULL,NULL,0);
     initNode(&node20,NULL,NULL,0);

     Node *root = &node30;
     root=avlRemoveInteger(&root,30);
     TEST_ASSERT_EQUAL_PTR(&node40,root);
     TEST_ASSERT_EQUAL_NODE(&node20,&node50,1,&node40);
     TEST_ASSERT_EQUAL_PTR(NULL,node50.left);
     TEST_ASSERT_EQUAL_PTR(&node100,node50.right);
     TEST_ASSERT_EQUAL(1,node50.balanceFactor);
     TEST_ASSERT_EQUAL_NODE(NULL,&node100,1,&node50);
}
/**
---------------------------------remove 15 and rotateLeft---------------------------------
*        30 (1)                          30(0)
*          \           remove 50
*         50 (0)   ------------>
*
**/
void test_remove_given_Avl_tree_remove_50_30_left(void){

     initNode(&node50,NULL,NULL,0);
     initNode(&node30,NULL,&node50,1);

     Node *root = &node30;
     root=avlRemoveInteger(&root,50);
     TEST_ASSERT_EQUAL_PTR(&node30,root);
     TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node30);
}


/**
---------------------------------------remove 60----------------------------------------
*                  60                           60 (0)
*                /    \       remove 40        /   \
*               40      90    ---------->     30    90(1)
*              /  \    /   \                 / \   /  \
*            20   50  75   100             20  50  75  100
*           / \    \   \                   /   / \   \
*         10   30   55  80               10   35  55  80
*               \
*               35
**/
void test_remove_given_Avl_tree_remove_60_test2(void){

  initNode(&node60,&node40,&node90,-1);
  initNode(&node40,&node20,&node50,-1);
  initNode(&node90,&node75,&node100,-1);
  initNode(&node20,&node10,&node30,1);
  initNode(&node50,NULL,&node55,1);
  initNode(&node75,NULL,&node80,1);
  initNode(&node100,NULL,NULL,0);
  initNode(&node30,NULL,&node35,1);
  initNode(&node10,NULL,NULL,0);
  initNode(&node55,NULL,NULL,0);
  initNode(&node80,NULL,NULL,0);
  initNode(&node100,NULL,NULL,0);

   Node *root = &node60;
  root=avlRemoveInteger(&root,40);
  TEST_ASSERT_EQUAL_PTR(&node60,root);

TEST_ASSERT_EQUAL_NODE(&node30,&node90,0,&node60);
TEST_ASSERT_EQUAL_NODE(&node20,&node50,0,&node30);
TEST_ASSERT_EQUAL_NODE(&node75,&node100,-1,&node90);
TEST_ASSERT_EQUAL_NODE(&node35,&node55,0,&node50);
TEST_ASSERT_EQUAL_NODE(&node10,NULL,-1,&node20);
TEST_ASSERT_EQUAL_NODE(NULL,&node80,1,&node75);
TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node10);
TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node35);
TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node55);
TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node80);
TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node100);
}


/**
-------------------------------------------------------------------------------
*                  25                           25 (-1)
*                /    \       remove 20        /   \
*               15      30    ---------->    5    30(1)
*              /  \      \                  / \     \
*            5    20    35                  1  15   35
*           / \                               /
*         1    10                             10
*
*
**/
void test_remove_given_Avl_tree_remove_20_test2(void){

  initNode(&node1,NULL,NULL,0);
  initNode(&node5,&node1,&node10,0);
  initNode(&node10,NULL,NULL,0);
  initNode(&node15,&node5,&node20,-1);
  initNode(&node20,NULL,NULL,0);
  initNode(&node25,&node15,&node30,-1);
  initNode(&node30,NULL,&node35,1);
  initNode(&node35,NULL,NULL,0);

  Node *root = &node25;
  root=avlRemoveInteger(&root,20);
  TEST_ASSERT_EQUAL_PTR(&node25,root);
  TEST_ASSERT_EQUAL_NODE(&node5,&node30,-1,&node25);
  TEST_ASSERT_EQUAL_NODE(&node1,&node15,1,&node5);
  TEST_ASSERT_EQUAL_NODE(&node10,NULL,-1,&node15);
  TEST_ASSERT_EQUAL_NODE(NULL,&node35,1,&node30);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node20);
}

//////////////////////////////////////////////////////////////////////////
/**
*          20(1)                           25(0)
*          /   \           remove 20       /   \
*       10(-1) 30(1)        ----->     10(-1)  40(0)
*       /      /  \                     /       /  \
*     5(0)   25(0) 40(1)             5(0)    30(0) 50(0)
*                    \
*                    50(0)
**/

void test_remove_node_20_replace_by_node_25_v2(void){
  Node *root = &node20;
  initNode(&node10,&node5,NULL,-1);
  initNode(&node30,&node25,&node40,1);
  initNode(&node20,&node10,&node30,1);
  initNode(&node40,NULL,&node50,1);
  initNode(&node25,NULL,NULL,0);
  initNode(&node5,NULL,NULL,0);
  initNode(&node50,NULL,NULL,0);

  root=avlRemoveInteger(&root,20);
  TEST_ASSERT_EQUAL_PTR(&node25,root);
  TEST_ASSERT_EQUAL_PTR(&node10,node25.left);
  TEST_ASSERT_EQUAL_PTR(&node40,node25.right);
  TEST_ASSERT_EQUAL_PTR(&node30,node40.left);
  TEST_ASSERT_EQUAL_PTR(&node50,node40.right);
  TEST_ASSERT_EQUAL_PTR(NULL,node30.right);
  TEST_ASSERT_EQUAL_PTR(NULL,node30.left);
  TEST_ASSERT_EQUAL_PTR(NULL,node10.right);
  TEST_ASSERT_EQUAL_PTR(&node5,node10.left);
  TEST_ASSERT_EQUAL_PTR(NULL,node50.right);
  TEST_ASSERT_EQUAL_PTR(NULL,node50.left);
  TEST_ASSERT_EQUAL_PTR(NULL,node5.right);
  TEST_ASSERT_EQUAL_PTR(NULL,node5.left);
  TEST_ASSERT_EQUAL(0,node40.balanceFactor);
  TEST_ASSERT_EQUAL(0,node30.balanceFactor);
  TEST_ASSERT_EQUAL(0,node25.balanceFactor);
  TEST_ASSERT_EQUAL(-1,node10.balanceFactor);
  TEST_ASSERT_EQUAL(0,node50.balanceFactor);
  TEST_ASSERT_EQUAL(0,node5.balanceFactor);
}
/**
*          20(1)                           20(1)
*          /   \           remove 30       /   \
*        10(0) 30(0)        ----->     10(0)    40(-1)
*             /   \                            /
*         15(0)  40(0)                      15(0)
*
**/
void test_remove_node_30_replace_by_node_40_v2(void){
  Node *root = &node20;
  initNode(&node10,NULL,NULL,0);
  initNode(&node30,&node15,&node40,0);
  initNode(&node20,&node10,&node30,1);
  initNode(&node40,NULL,NULL,0);
  initNode(&node15,NULL,NULL,0);

  root=avlRemoveInteger(&root,30);
  TEST_ASSERT_EQUAL_PTR(&node20,root);
  TEST_ASSERT_EQUAL_PTR(&node10,node20.left);
  TEST_ASSERT_EQUAL_PTR(&node40,node20.right);
  TEST_ASSERT_EQUAL_PTR(NULL,node40.right);
  TEST_ASSERT_EQUAL_PTR(&node15,node40.left);
  TEST_ASSERT_EQUAL_PTR(NULL,node10.right);
  TEST_ASSERT_EQUAL_PTR(NULL,node10.left);
  TEST_ASSERT_EQUAL_PTR(NULL,node15.right);
  TEST_ASSERT_EQUAL_PTR(NULL,node15.left);
  TEST_ASSERT_EQUAL(-1,node40.balanceFactor);
  TEST_ASSERT_EQUAL(1,node20.balanceFactor);
  TEST_ASSERT_EQUAL(0,node10.balanceFactor);
  TEST_ASSERT_EQUAL(0,node15.balanceFactor);
}

void test_noderemove_remove_with_right_value_is_NULL5(void)
{
    Node *root = &node40;

    initNode(&node40,&node20,&node50,-1);
    initNode(&node20,&node10,&node30,1);
    initNode(&node50,NULL,&node55,1);
    initNode(&node30,NULL,&node35,1);
    initNode(&node10,NULL,NULL,0);
    initNode(&node35,NULL,NULL,0);
    initNode(&node55,NULL,NULL,0);
    root=avlRemoveInteger(&root,40);
    TEST_ASSERT_EQUAL_NODE(&node20,&node50,0,&node30);
    TEST_ASSERT_EQUAL_NODE(&node10,NULL,-1,&node20);
    TEST_ASSERT_EQUAL_NODE(&node35,&node55,0,&node50);
    TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node10);
    TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node35);
    TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node55);
}

void test_noderemove_remove_nonexisting_val(void){
  CEXCEPTION_T   ex;
  Node *root = &node20;
  initNode(&node10,NULL,NULL,0);
  initNode(&node30,&node15,&node40,0);
  initNode(&node20,&node10,&node30,1);
  initNode(&node40,NULL,NULL,0);
  initNode(&node15,NULL,NULL,0);
  Try
    root=avlRemoveInteger(&root,70);
  Catch(ex)
      dumpException((Exception *)ex);
  TEST_ASSERT_EQUAL_PTR(&node20,root);
  TEST_ASSERT_EQUAL_PTR(&node10,node20.left);
  TEST_ASSERT_EQUAL_PTR(&node30,node20.right);
  TEST_ASSERT_EQUAL_PTR(&node15,node30.left);
  TEST_ASSERT_EQUAL_PTR(&node40,node30.right);
  TEST_ASSERT_EQUAL_PTR(NULL,node40.right);
  TEST_ASSERT_EQUAL_PTR(NULL,node40.left);
  TEST_ASSERT_EQUAL_PTR(NULL,node10.right);
  TEST_ASSERT_EQUAL_PTR(NULL,node10.left);
  TEST_ASSERT_EQUAL_PTR(NULL,node15.right);
  TEST_ASSERT_EQUAL_PTR(NULL,node15.left);
  TEST_ASSERT_EQUAL(0,node40.balanceFactor);
  TEST_ASSERT_EQUAL(1,node20.balanceFactor);
  TEST_ASSERT_EQUAL(0,node10.balanceFactor);
  TEST_ASSERT_EQUAL(0,node15.balanceFactor);
}
#include "unity.h"
#include "Rotate.h"
#include "AVL_Balance.h"
#include <stdio.h>
#include "nodeHelper.h"
#include "CException.h"
#include "exception.h"

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
