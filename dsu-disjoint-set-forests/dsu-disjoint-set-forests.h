#ifndef DISJOINTSETFORESTS_H
#define DISJOINTSETFORESTS_H
#include <stdlib.h>

Node *makeSet(int value);
Node *findSet(Node *x);
void link(Node *x, Node *y);
int unite(Node *x, Node *y);

#endif
