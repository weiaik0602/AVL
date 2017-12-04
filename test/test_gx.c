#include "unity.h"
#include "nodeRemove.h"
#include "stdlib.h"
#include "Node.h"
#include "nodeVerifier.h"
#include "nodeHelper.h"
#include "Rotate.h"
#include "AVL_Balance.h"
#include "AVLInteger.h"


void setUp(void)
{
  giveInitdata();
}

void tearDown(void)
{
}

/**
 *    NULL    --->    NULL
*/
void test_deleteLeaf_given_NULL(void){
    Node *root;
    root = NULL;

    Node *deletedNode = avlRemoveInteger(&root, 0);
    TEST_ASSERT_NULL(deletedNode);
    TEST_ASSERT_NULL(root);
}
/**
 *       delete node10
 *  10      ---->         NULL
 */
void test_deleteLeaf_given_node10_expect_NULL(void)
{
    initNode(&node10, NULL, NULL, 0);
    Node *root;
    root = &node10;

    avlRemoveInteger(&root, 10);
    TEST_ASSERT_NULL(root);
}

/**
 *    10    delete node 5    10
 *   /         ---->
 *  5
 */
void test_deleteLeaf_given_10_5_delete_5_expect_10(void){
    initNode(&node10, &node5, NULL, -1);
    initNode(&node5, NULL, NULL, -1);
    Node *root;
    root = &node10;

    avlRemoveInteger(&root, 5);
    TEST_ASSERT_EQUAL_NODE2(&node10, NULL, NULL, 0);
}

/**
 *    10    delete node 15    10
 *      \        ---->
 *      15
 */
void test_deleteLeaf_given_10_15_delete_15_expect_10(void)
{
    initNode(&node10, NULL, &node15, 1);
    Node *root;
    root = &node10;

    avlRemoveInteger(&root, 15);
    TEST_ASSERT_EQUAL_NODE2(&node10, NULL, NULL, 0);
}

/**
 *
 *    5                          5
 *  /  \                      /    \
 * 1   10    delete node 15   1    10
 *      \        ---->
 *      15
 */
void test_deleteLeaf_given_10_15_delete_15_expect_10_with_1Parent(void)
{
    initNode(&node5, &node1, &node10, 1);
    initNode(&node10, NULL, &node15, 1);
    initNode(&node1, NULL, NULL, 0);
    Node *root;
    root = &node5;

    avlRemoveInteger(&root, 15);
    TEST_ASSERT_EQUAL_NODE2(&node10, NULL, NULL, 0);
    TEST_ASSERT_EQUAL_NODE2(&node5, &node1, &node10, 0);
}

/**
 *
 *    5                          5                            10
 *  /  \                          \                         /    \
 * 1   10    delete node 1        10     rotate left       5     15
 *      \        ---->             \       ---->
 *      15                         15
 */
void test_deleteLeaf_given_5_1_10_15_delete_15_expect_rotateLeft(void)
{
    initNode(&node5, &node1, &node10, 1);
    initNode(&node10, NULL, &node15, 1);
    initNode(&node1, NULL, NULL, 0);
    Node *root;
    root = &node5;

    avlRemoveInteger(&root, 1);
    TEST_ASSERT_EQUAL_NODE2(&node10, &node5, &node15, 0);
    TEST_ASSERT_EQUAL_NODE2(&node5, NULL, NULL, 0);
    TEST_ASSERT_EQUAL_NODE2(&node15, NULL, NULL, 0);
}

/**
 *
 *         5                          5                          3
 *       /  \                        /                         /  \
 *      3   10    delete node 10    3     rotate right        1    5
 *     /              ---->        /        ---->
 *    1                           1
 */
void test_deleteLeaf_given_5_3_1_10_delete_10_expect_rotateRight(void)
{
    initNode(&node5, &node3, &node10, -1);
    initNode(&node3, &node1, NULL, -1);
    initNode(&node1, NULL, NULL, 0);
    initNode(&node10, NULL, NULL, 0);
    Node *root;
    root = &node5;

    avlRemoveInteger(&root, 10);
    TEST_ASSERT_EQUAL_NODE2(&node3, &node1, &node5, 0);
    TEST_ASSERT_EQUAL_NODE2(&node5, NULL, NULL, 0);
    TEST_ASSERT_EQUAL_NODE2(&node1, NULL, NULL, 0);
}

/**
 *
 *         5                          5                              3
 *       /  \                        /                             /  \
 *      1   10    delete node 10    1     rotate Leftright        1    5
 *      \               ---->        \         ---->
 *      3                            3
 */
void test_deleteLeaf_given_5_3_1_10_delete_10_expect_rotateLeftRight(void)
{
    initNode(&node5, &node1, &node10, -1);
    initNode(&node1, NULL, &node3, 1);
    initNode(&node10, NULL, NULL, 0);
    initNode(&node3, NULL, NULL, 0);
    Node *root;
    root = &node5;

    avlRemoveInteger(&root, 10);
    TEST_ASSERT_EQUAL_NODE2(&node3, &node1, &node5, 0);
    TEST_ASSERT_EQUAL_NODE2(&node5, NULL, NULL, 0);
    TEST_ASSERT_EQUAL_NODE2(&node1, NULL, NULL, 0);
}

/**
 *
 *         5                          5                              10
 *       /  \                          \                            /  \
 *      1   15    delete node 1        15   rotate rightLeft       5   15
 *         /           ---->           /      ---->
 *        10                          10
 */
void test_deleteLeaf_given_5_3_1_10_delete_10_expect_rotateRightLeft(void)
{
    initNode(&node5, &node1, &node15, 1);
    initNode(&node15, &node10, NULL, -1);
    initNode(&node10, NULL, NULL, 0);
    initNode(&node1, NULL, NULL, 0);
    Node *root;
    root = &node5;

    avlRemoveInteger(&root, 1);
    TEST_ASSERT_EQUAL_NODE2(&node10, &node5, &node15, 0);
    TEST_ASSERT_EQUAL_NODE2(&node5, NULL, NULL, 0);
    TEST_ASSERT_EQUAL_NODE2(&node15, NULL, NULL, 0);
}

/**
 *    5    delete 1      5
 *   / \     -->         \
 *  1  10                10
 */
void test_deleteLeaf_bf_parent_no_change(void){
    initNode(&node5, &node1, &node10, 0);
    initNode(&node1, NULL, NULL, 0);
    initNode(&node10, NULL, NULL, 0);

    Node *root;
    root = &node5;

    avlRemoveInteger(&root, 1);
    TEST_ASSERT_EQUAL_NODE2(&node5, NULL, &node10, 1);
    // TEST_ASSERT_EQUAL(NO_CHANGED, heightChanged);
}

/**
 *
 *         5                             5
 *       /  \                           /  \
 *      1   15    delete node 15       1   10
 *         /           ---->
 *        10
 */
void test_deleteNonLeaf_given_5_3_1_10_delete_15_expect_1_5_10(void)
{
    initNode(&node5, &node1, &node15, 1);
    initNode(&node15, &node10, NULL, -1);
    initNode(&node10, NULL, NULL, 0);
    initNode(&node1, NULL, NULL, 0);
    Node *root;
    root = &node5;

    Node *deletedNode = avlRemoveInteger(&root, 15);
    TEST_ASSERT_NOT_NULL(deletedNode);
    TEST_ASSERT_EQUAL_NODE2(&node5, &node1, &node10, 0);
    TEST_ASSERT_EQUAL_NODE2(&node1, NULL, NULL, 0);
    TEST_ASSERT_EQUAL_NODE2(&node10, NULL, NULL, 0);
}

/**
 *
 *         5                                 5
 *       /  \                              /  \
 *      1   15(0)     delete node 15       1  20
 *         /  \          ---->                /
 *        10  20                              10
 */
void test_deleteLeaf_given_deletedNode_left_right_Not_null_delete_15(void)
{
    initNode(&node5, &node1, &node15, 1);
    initNode(&node15, &node10, &node20, 0);
    initNode(&node10, NULL, NULL, 0);
    initNode(&node20, NULL, NULL, 0);
    initNode(&node1, NULL, NULL, 0);

    Node *root;
    root = &node5;

    Node *deletedNode = avlRemoveInteger(&root, 15);
    TEST_ASSERT_NOT_NULL(deletedNode);
    TEST_ASSERT_EQUAL_PTR(node20.left,&node10);
    TEST_ASSERT_EQUAL_PTR(node20.right,NULL);
    TEST_ASSERT_EQUAL(node20.balanceFactor,-1);
    TEST_ASSERT_EQUAL_PTR(node5.left,&node1);
    TEST_ASSERT_EQUAL_PTR(node5.right,&node20);
    TEST_ASSERT_EQUAL(node5.balanceFactor,1);
    TEST_ASSERT_EQUAL_NODE2(&node5, &node1, &node20, 1);
    TEST_ASSERT_EQUAL_NODE2(&node10, NULL, NULL, 0);
    TEST_ASSERT_EQUAL_NODE2(&node1, NULL, NULL, 0);
    TEST_ASSERT_EQUAL_NODE2(&node20, &node10, NULL, -1);
}

/**
 ````*````
 *         5                                 5
 *       /  \                              /  \
 *      4    15      delete node 15       4   10
 *     /    /  \          ---->          /   / \
 *    3   10  20                        3   7   20
 *       /
 *      7
 */
void test_deleteLeaf_given_deletedNode_left_right_Not_null_grandchild_notNULL_delete_15(void)
{
    initNode(&node5, &node4, &node15, 1);
    initNode(&node4, &node3, NULL, -1);
    initNode(&node15, &node10, &node20, -1);
    initNode(&node10, &node7, NULL, -1);

    initNode(&node3, NULL, NULL, 0);
    initNode(&node7, NULL, NULL, 0);
    initNode(&node20, NULL, NULL, 0);

    Node *root;
    root = &node5;

    avlRemoveInteger(&root, 15);
    TEST_ASSERT_EQUAL_NODE2(&node5, &node4, &node10, 0);
    TEST_ASSERT_EQUAL_NODE2(&node10, &node7, &node20, 0);
    TEST_ASSERT_EQUAL_NODE2(&node3, NULL, NULL, 0);
    TEST_ASSERT_EQUAL_NODE2(&node7, NULL, NULL, 0);
    TEST_ASSERT_EQUAL_NODE2(&node20, NULL, NULL, 0);
}

/*
 *
 *         node3(1)                                       2  (2)                            5(0)
 *        /    \                                        /  \                              /   \
 *   node2(-1) node5(1)        remove node3            1   5 (1)    (rotate left)       2(0)  10(1)
 *    /       /     \             ----->                  / \            --->          / \     \
 * node1   node4   node10                                4   10                       1   4    20
 *                    \                                       \
 *                    node20                                  20
 *
 *
 *
 */
void xtest_nodeRemove_3_expect_rotateAtParent(void)
{
    initNode(&node3, &node2, &node5, 1);
    initNode(&node2, &node1, NULL, -1);
    initNode(&node5, &node4, &node10, 1);
    initNode(&node10, NULL, &node20, 1);
    initNode(&node1, NULL, NULL, 0);
    initNode(&node20, NULL, NULL, 0);
    initNode(&node4, NULL, NULL, 0);

    initNode(&node15, NULL, NULL, 0);

    Node *root = &node3;
    avlRemoveInteger(&root, 3);

    TEST_ASSERT_EQUAL_NODE2(&node5, &node2, &node10, 0);
    TEST_ASSERT_EQUAL_NODE2(&node2, &node1, &node4, 0);
    TEST_ASSERT_EQUAL_NODE2(&node10, NULL, &node20, 1);

    TEST_ASSERT_EQUAL_NODE2(&node1, NULL, NULL, 0);
    TEST_ASSERT_EQUAL_NODE2(&node4, NULL, NULL, 0);
    TEST_ASSERT_EQUAL_NODE2(&node20, NULL, NULL, 0);
}

/**
 *     20 (-1)                     15 (0)
 *    /  \                       /  \
 *   5    35 (-1)  (delete 20)  5(0) 35(1)
 *  / \    \            --->   / \    \
 * 1  15   40                 1   10  40
 *    /
 *  10
 */
void test_nodeRemove_replace_and_pass_grandChild_to_child(void){
    initNode(&node20, &node5, &node35, -1);
    initNode(&node5, &node1, &node15, 1);
    initNode(&node35, NULL, &node40, 1);
    initNode(&node15, &node10, NULL, -1);

    initNode(&node40, NULL, NULL, 0);
    initNode(&node1, NULL, NULL, 0);
    initNode(&node10, NULL, NULL, 0);

    Node *root = &node20;
    avlRemoveInteger(&root, 20);
    TEST_ASSERT_EQUAL_PTR(root,&node15);
    TEST_ASSERT_EQUAL_NODE2(&node15, &node5, &node35, 0);
    TEST_ASSERT_EQUAL_NODE2(&node5, &node1, &node10, 0);
    TEST_ASSERT_EQUAL_NODE2(&node35, NULL, &node40, 1);
    TEST_ASSERT_EQUAL_NODE2(&node1, NULL, NULL, 0);
    TEST_ASSERT_EQUAL_NODE2(&node10, NULL, NULL, 0);
    TEST_ASSERT_EQUAL_NODE2(&node40, NULL, NULL, 0);
}

/**
 *           40                                 45
 *          /  \                               /  \
 *        30    60     remove node 40         30   60
 *         \   /  \       and rotateRL        \    /\
 *         35 50  70       ---->              35   50 70
 *            /
 *           45
 */
void test_nodeRemove_replace_and_rotate_rightLeft(void){
    initNode(&node40, &node30, &node60, 1);
    initNode(&node60, &node50, &node70, -1);
    initNode(&node30, NULL, &node35, 1);
    initNode(&node50, &node45, NULL, -1);
    initNode(&node35, NULL, NULL, 0);
    initNode(&node45, NULL, NULL, 0);
    initNode(&node70, NULL, NULL, 0);

    Node *root = &node40;
    root=avlRemoveInteger(&root, 40);
    TEST_ASSERT_EQUAL_PTR(root,&node45);
    TEST_ASSERT_EQUAL_NODE2(&node50, NULL, NULL, 0);
    TEST_ASSERT_EQUAL_NODE2(&node35, NULL, NULL, 0);
    TEST_ASSERT_EQUAL_PTR(&node50,node60.left);
    TEST_ASSERT_EQUAL_PTR(&node70,node60.right);
    TEST_ASSERT_EQUAL(0,node60.balanceFactor);
    TEST_ASSERT_EQUAL_NODE2(&node60, &node50, &node70, 0);
    TEST_ASSERT_EQUAL_NODE2(&node30, NULL, &node35, 1);
    TEST_ASSERT_EQUAL_NODE2(&node45, &node30, &node60, 0);
    TEST_ASSERT_EQUAL_NODE2(&node70, NULL, NULL, 0);
}

/**
 *       50                                               40
 *      /  \              delete 50                      / \
 *     30  60    child rotate right before return      20  60
 *    /  \  \            --->                         / \   \
 *   20  40  70                                     10   30  70
 *  /
 * 10
 */

void test_nodeRemove_replace_and_child_rotate_R(void)
{
    initNode(&node50, &node30, &node60, -1);
    initNode(&node30, &node20, &node40, -1);
    initNode(&node60, NULL, &node70, 1);
    initNode(&node20, &node10, NULL, -1);
    initNode(&node10, NULL, NULL, 0);
    initNode(&node40, NULL, NULL, 0);
    initNode(&node70, NULL, NULL, 0);

    Node *root = &node50;
    avlRemoveInteger(&root, 50);
    TEST_ASSERT_EQUAL_PTR(root,&node30);
    TEST_ASSERT_EQUAL_NODE2(&node40, NULL, NULL, 0);
    TEST_ASSERT_EQUAL_NODE2(&node20, &node10, NULL, -1);
    TEST_ASSERT_EQUAL_NODE2(&node60, &node40, &node70, 0);
    TEST_ASSERT_EQUAL_NODE2(&node10, NULL, NULL, 0);
    TEST_ASSERT_EQUAL_NODE2(&node30, &node20, &node60, 0);
    TEST_ASSERT_EQUAL_NODE2(&node70, NULL, NULL, 0);
}

/**
 *       50                                               40
 *      /  \              delete 50                      / \
 *     30  60    child rotate right before return      25  60
 *    /  \  \            --->                         / \   \
 *   20  40  70                                     20   30  70
 *    \
 *    25
 */

void test_nodeRemove_replace_and_child_rotate_RL(void)
{
    initNode(&node50, &node30, &node60, -1);
    initNode(&node30, &node20, &node40, -1);
    initNode(&node60, NULL, &node70, 1);
    initNode(&node20, NULL, &node25, 1);

    initNode(&node25, NULL, NULL, 0);
    initNode(&node40, NULL, NULL, 0);
    initNode(&node70, NULL, NULL, 0);

    Node *root = &node50;
    avlRemoveInteger(&root, 50);
    TEST_ASSERT_EQUAL_PTR(root,&node30);
    TEST_ASSERT_EQUAL_NODE2(&node40, NULL, NULL, 0);
    TEST_ASSERT_EQUAL_NODE2(&node20, NULL, &node25, 1);
    TEST_ASSERT_EQUAL_NODE2(&node60, &node40, &node70, 0);
    TEST_ASSERT_EQUAL_NODE2(&node10, NULL, NULL, 0);
    TEST_ASSERT_EQUAL_NODE2(&node30, &node20, &node60, 0);
    TEST_ASSERT_EQUAL_NODE2(&node70, NULL, NULL, 0);
}

/**
 *       50                                               40
 *      /  \              delete 50                      / \
 *     30  60    child rotate right before return      20  60
 *    /  \  \            --->                         / \   \
 *   20  40  70                                     15   30  70
 *  / \                                                 /
 * 15  25                                              25
 */

void test_nodeRemove_replace_and_child_rotate_R_rootPtr_bf_nochanged(void)
{
    initNode(&node50, &node30, &node60, -1);
    initNode(&node30, &node20, &node40, -1);
    initNode(&node60, NULL, &node70, 1);
    initNode(&node20, &node15, &node25, 0);

    initNode(&node15, NULL, NULL, 0);
    initNode(&node25, NULL, NULL, 0);
    initNode(&node40, NULL, NULL, 0);
    initNode(&node70, NULL, NULL, 0);

    Node *root = &node50;
    avlRemoveInteger(&root, 50);
    TEST_ASSERT_EQUAL_PTR(root,&node30);
    TEST_ASSERT_EQUAL_NODE2(&node40, NULL, NULL, 0);
    TEST_ASSERT_EQUAL_NODE2(&node20, &node15, &node25,0);
    TEST_ASSERT_EQUAL_NODE2(&node60, &node40, &node70, 0);
    TEST_ASSERT_EQUAL_NODE2(&node10, NULL, NULL, 0);
    TEST_ASSERT_EQUAL_NODE2(&node30, &node20, &node60, 0);
    TEST_ASSERT_EQUAL_NODE2(&node70, NULL, NULL, 0);
}

/**
 *       15                                               20
 *      /  \              delete 15                      / \
 *     10   25     child rotate left before return      10  30
 *    /    / \            --->                         /    /\
 *   5    20  30                                      5    25 35
 *             \
 *              35
 */

void test_nodeRemove_replace_and_child_rotate_L(void)
{
    initNode(&node5, NULL, NULL, 0);
    initNode(&node20, NULL, NULL, 0);
    initNode(&node35,NULL, NULL, 0);
    initNode(&node30, NULL, &node35, 1);
    initNode(&node10, &node5, NULL, -1);
    initNode(&node25, &node20, &node30, 1);
    initNode(&node15, &node10, &node25, 1);

    Node *root = &node15;
    avlRemoveInteger(&root, 15);
    TEST_ASSERT_EQUAL_PTR(root,&node20);
    TEST_ASSERT_EQUAL_NODE2(&node5, NULL, NULL, 0);
    TEST_ASSERT_EQUAL_NODE2(&node25, NULL, NULL, 0);
    TEST_ASSERT_EQUAL_NODE2(&node35, NULL, NULL, 0);
    TEST_ASSERT_EQUAL_NODE2(&node30, &node25, &node35, 0);
    TEST_ASSERT_EQUAL_PTR(&node10,node20.left);
    TEST_ASSERT_EQUAL_PTR(&node30,node20.right);
    TEST_ASSERT_EQUAL(0,node20.balanceFactor);
    TEST_ASSERT_EQUAL_NODE2(&node20, &node10, &node30, 0);
    TEST_ASSERT_EQUAL_NODE2(&node10, &node5, NULL, -1);


}
