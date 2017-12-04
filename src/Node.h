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
// /typedef int (*CompareWithVoidPtr)(void *, Node *);

#endif // _NODE_H
