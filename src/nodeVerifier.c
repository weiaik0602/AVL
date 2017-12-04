#include "nodeVerifier.h"
#include "node.h"
#include "unity.h"
#include <stdarg.h>
#include <stdio.h>
#include <malloc.h>


char *createMessage(char *message, ...){
  va_list args;
  char *buffer;
  int length;

  va_start(args,message);

  length = vsnprintf(buffer, 0, message, args);
  buffer = malloc(length+1);
  vsnprintf(buffer, length+1, message, args);

  return buffer;
}

void testAssertEqualNode(Node *left, Node *right, int balanceFactor, Node *node,int lineNo){
  char *error;
  if(left != node->left){
      error = createMessage("Expected left node to be 0x%p, but was %p",  \
                            left,node->left);
      UNITY_TEST_FAIL(lineNo,error);
    }
  else if(balanceFactor != node->balanceFactor){
    error = createMessage("Expected balance factor to be 0x%p, but was %p",  \
                          balanceFactor,node->balanceFactor);
    UNITY_TEST_FAIL(lineNo,error);
  }


  else if(right != node->right){
      error = createMessage("Expected right node to be 0x%p, but was %p",  \
                            right,node->right);
    UNITY_TEST_FAIL(lineNo,error);
    }
}

void testAssertEqualNode2(Node *node,Node *left, Node *right, int balanceFactor, int lineNo){
  char *error;
  if(left != node->left){
      error = createMessage("Expected left node to be 0x%p, but was %p",  \
                            left,node->left);
      UNITY_TEST_FAIL(lineNo,error);
    }
  else if(balanceFactor != node->balanceFactor){
    error = createMessage("Expected balance factor to be 0x%p, but was %p",  \
                          balanceFactor,node->balanceFactor);
    UNITY_TEST_FAIL(lineNo,error);
  }


  else if(right != node->right){
      error = createMessage("Expected right node to be 0x%p, but was %p",  \
                            right,node->right);
    UNITY_TEST_FAIL(lineNo,error);
    }
}
