#ifndef DISJOINT_SET_FORESTS_H
#define DISJOINT_SET_FORESTS_H

typedef struct Node {
  int value;
  struct Node *parent;
  int rank;
} Node;
// Crea solo un nodo, rank = 0
Node *makeSet(int value);
// Debe dejar los ranks sin cambios
Node *findSet(Node *x);
// Une 2 sets, 2 casos, uno si ambos rangos son iguales o el otro si son
// distintos
void link(Node *x, Node *y);
// Llama a la función link
int unite(Node *x, Node *y);

#endif
