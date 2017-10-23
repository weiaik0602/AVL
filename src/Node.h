#ifndef _NODE_H
#define _NODE_H

#include <stdint.h>

typedef struct Node Node;
struct Node {
  Node *Left;
  Node *Right;
  int balancefactor;
  int Data;
};
#endif // _NODE_H
