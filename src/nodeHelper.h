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
