#include "dsu-disjoint-set-forests.h"
#include <stdlib.h>

// MAKE-SET(value): crea un árbol de un solo nodo
Node *makeSet(int value) {
  Node *x = malloc(sizeof(*x));
  if (!x)
    return NULL;

  x->value = value;
  x->parent = x; // Es su propia raíz
  x->rank = 0;

  return x;
}

// FIND-SET(x) con compresión de caminos (path compression)
Node *findSet(Node *x) {
  if (!x)
    return NULL;

  if (x != x->parent) {
    x->parent = findSet(x->parent);
  }
  return x->parent;
}

// LINK(x, y): recibe dos RAÍCES distintas y une por rank
void link(Node *x, Node *y) {
  if (!x || !y || x == y)
    return;

  if (x->rank > y->rank) {
    y->parent = x;
  } else {
    x->parent = y;
    if (x->rank == y->rank) {
      y->rank += 1;
    }
  }
}

// UNION(x, y)
int unite(Node *x, Node *y) {
  if (!x || !y)
    return 0;

  Node *rootX = findSet(x);
  Node *rootY = findSet(y);

  if (rootX == rootY)
    return 0; // Ya están en el mismo conjunto

  link(rootX, rootY);
  return 1;
}
