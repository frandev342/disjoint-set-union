#ifndef DSU_SIMPLE_UNION_H
#define DSU_SIMPLE_UNION_H

#include <stdlib.h>
typedef struct Set {
  struct Node *head;
  struct Node *tail;
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

// Devuelve el representate del conjunto del nodo x
int findSet(Node *x);

// Crear un conjunto para value
Node *makeSet(DSU *dsu, int value);

// Unir el conjunto de x con el conjunto y, manteniendo el representate de x
int unite(DSU *dsu, Node *x, Node *y);

#endif // !
