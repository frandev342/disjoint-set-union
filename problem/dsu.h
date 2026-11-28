#ifndef DISJOINT_SET_UNION_H
#define DISJOINT_SET_UNION_H

typedef struct Node {
  int value;
  struct Node *parent;
  int rank;
} Node;

typedef struct DSU {
  Node **nodes;
  int size;
  int capacity;
} DSU;

int initDSU(DSU *dsu, int capacity);
void destroyDSU(DSU *dsu);

Node *makeSet(DSU *dsu, int value);
Node *findSet(Node *x);
void link(Node *x, Node *y);
int unite(DSU *dsu, Node *x, Node *y);

#endif
