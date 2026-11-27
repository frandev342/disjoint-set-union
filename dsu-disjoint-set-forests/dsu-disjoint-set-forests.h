#ifndef DISJOINTSETFORESTS_H
#define DISJOINTSETFORESTS_H
#include <stdlib.h>

typedef struct Node{
  int data;
  Node* parent;
  int rank;
} Node;
Node *makeSet(int value);
Node *findSet(Node *x);
void link(Node *x, Node *y);
int unite(Node *x, Node *y);

#endif
