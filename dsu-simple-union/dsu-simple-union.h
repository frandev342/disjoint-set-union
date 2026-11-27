#ifndef DSU_SIMPLE_UNION_H
#define DSU_SIMPLE_UNION_H

#include <stdlib.h>
typedef struct Set {
  struct Node *head;
  struct Node *tail;
} Set;

typedef struct Node {
  int value;
  struct Node *next;
  Set *set;
} Node;

// Devuelve el representate del conjunto del nodo x
Node *findSet(Node *x);

// Crear un conjunto para value
Node *makeSet(int value);

// Unir el conjunto de x con el conjunto y, manteniendo el representate de x
void unite(Node *x, Node *y);

#endif // !
