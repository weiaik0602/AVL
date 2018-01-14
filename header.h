#ifndef _ADDNODE_H
#define _ADDNODE_H

#include <Node.h>
#include <stdio.h>
#include <Rotate.h>
#include "CException.h"
#include "exception.h"
#include "AVL_Balance.h"





Node *addNode(Node **rootPtr, Node *nodeToAdd,Compare cmp);

#endif // _ADDNODE_H
#ifndef _AVL_BALANCE_H
#define _AVL_BALANCE_H

#include "addNode.h"
#include "Rotate.h"
#include "Node.h"
int avlBalanceRightTree(Node **rootPtr);
int avlBalanceLeftTree(Node **rootPtr);
void avlbalance(Node **rootPtr);
#endif // _AVL_BALANCE_H
#ifndef _AVLINTEGER_H
#define _AVLINTEGER_H

#include "Node.h"
#include "stdlib.h"
typedef struct IntegerNode IntegerNode;
struct IntegerNode{
  IntegerNode *left;
  IntegerNode *right;
  int balanceFactor;
  int data;
  //int lock;
};


#define avlAddInteger(root, nodeToAdd)  addNode((Node **)root, (Node *)nodeToAdd,(Compare) integerCompare)
#define avlRemoveInteger(root,data)     nodeRemove((Node **)root,(int *)data ,(Compare) integerCompare)

int integerCompare(int data,Node *refNode);
#endif // _AVLINTEGER_H
#ifndef _AVLSTRING_H
#define _AVLSTRING_H

#include "Node.h"
#include "stdlib.h"
#include "string.h"
#include "nodeRemove.h"
typedef struct StringNode StringNode;
struct StringNode{
  StringNode *left;
  StringNode *right;
  int balanceFactor;
  char* data;
  //int lock;
};


#define avlAddString(root, nodeToAdd)  addNode((Node **)root, (Node *)nodeToAdd,(Compare) stringCompare)
#define avlRemoveString(root,data)     nodeRemove((Node **)root,(char *)data ,(Compare) stringCompare)

int stringCompare(char* data,Node *refNode);
#endif // _AVLSTRING_H
#ifndef CExceptionConfig_H
#define CExceptionConfig_H

#include "exception.h"

#define CEXCEPTION_T    ExceptionPtr
#define CEXCEPTION_NONE ((ExceptionPtr)0x5A5A5A5A)

#endif
#ifndef _EXCEPTION_H
#define _EXCEPTION_H

typedef struct Exception Exception;
typedef Exception* ExceptionPtr;
struct Exception{
  char *msg;
  int errorCode;
};

Exception *createException(char *msg,int errorCode);
void freeException(Exception *e);
void dumpException(Exception *e);

#endif // _EXCEPTION_H
#ifndef _NODE_H
#define _NODE_H

#include <stdint.h>


typedef struct Node Node;
struct Node {
  Node *left;
  Node *right;
  int balanceFactor;
  void *data;
  int lock;
};



typedef int (*Compare)(void *data, Node *refNode);


#endif // _NODE_H
#ifndef _NODEHELPER_H
#define _NODEHELPER_H
#include "node.h"

Node node1 ,node2, node3, node4,node23,node5,node7, node10,node15, node20, node25, node30, node35, node40;
Node node45, node50, node55, node60, node65, node70, node75, node80;
Node node85, node90, node95, node100;
Node nodeAli, nodeAbu, nodeAkau, nodeAlirosa,nodeAba,nodeAmin,nodeXaxa;


void initNode (Node *node, Node *left, Node *right, int balanceFactor);
void giveInitdata(void);
void giveInitString(void);



#endif // _NODEHELPER_H
#ifndef _NODEREMOVE_H
#define _NODEREMOVE_H

#include <Node.h>
#include <stdio.h>
#include <Rotate.h>
#include "AVL_Balance.h"
#include "nodeHelper.h"
#include "CException.h"
#include "exception.h"

#define LEFT 0
#define RIGHT 1
#define UNCHANGE 0
#define CHANGED 1

Node *findNearest(Node *rootPtr,int choose);
Node *removeRoot(Node *Remove,Compare cmp);
Node *nodeRemove(Node **rootPtr, void* valToRemove ,Compare cmp);


#endif // _NODEREMOVE_H
#ifndef _NODEVERIFIER_H
#define _NODEVERIFIER_H
#include "Node.h"

#define TEST_ASSERT_EQUAL_NODE(left,right,balanceFactor,node) \
                          testAssertEqualNode(left,right,balanceFactor,node,__LINE__)

void testAssertEqualNode(Node *left, Node *right, int balanceFactor, Node *node,int lineNo);


#define TEST_ASSERT_EQUAL_NODE2(node,left,right,balanceFactor) \
                          testAssertEqualNode2(node,left,right,balanceFactor,__LINE__)
void testAssertEqualNode2(Node *node,Node *left, Node *right, int balanceFactor, int lineNo);

#endif // _NODEVERIFIER_H
#ifndef _ROTATE_H
#define _ROTATE_H
#include <Node.h>
#include <stdio.h>

void printTraversalPostorder(Node *node);
Node* rotateRight(Node *node);
Node* rotateLeft(Node *node);
Node *rotateLeftRight(Node *node);
Node *rotateRightLeft(Node *node);


#endif // _ROTATE_H
