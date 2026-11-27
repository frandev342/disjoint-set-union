#ifndef DSU_WUH_H
#define DSU_WUH_H

typedef struct Set {
  struct Node *head;
  struct Node *tail;
  int length;
  struct Set *nextSet;
} Set;

typedef struct Node {
  int value;
  struct Node *next;
  Set *set;
} Node;

typedef struct DSU {
  Set *sets;
} DSU;

void initDSU(DSU *dsu);
void destroyDSU(DSU *dsu);

Node *findSet(Node *x);
Node *makeSet(DSU *dsu, int value);
int unite(DSU *dsu, Node *x, Node *y);

#endif // !
