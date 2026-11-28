#include "dsu.h"
#include <stdlib.h>

int initDSU(DSU *dsu, int capacity) {
  if (!dsu || capacity <= 0)
    return 0;

  // reservar memoria capacity*tamaño del nodo
  dsu->nodes = malloc(capacity * sizeof(Node *));
  if (!dsu->nodes)
    return 0;
  dsu->size = 0;
  dsu->capacity = capacity;
  return 1;
}
void destroyDSU(DSU *dsu) {
  if (!dsu)
    return;
  // Liberar nodos
  for (int i = 0; i < dsu->capacity; ++i) {
    free(dsu->nodes[i]);
  }
  // Liberar dsu
  free(dsu->nodes);
  // dejar en blanco al dsu
  dsu->capacity = 0;
  dsu->size = 0;
  dsu->nodes = NULL;
}

// MAKE-SET(value): crea un árbol de un solo nodo
Node *makeSet(DSU *dsu, int value) {
  // Verificar dsu y capacidad
  if (!dsu || dsu->capacity <= dsu->size)
    return NULL;
  Node *x = malloc(sizeof(*x));
  if (!x)
    return NULL;

  x->value = value;
  x->parent = x; // Es su propia raíz
  x->rank = 0;

  // Agregarlo al final y aumentar tamaño
  dsu->nodes[dsu->size] = x;
  dsu->size++;

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
int unite(DSU *dsu, Node *x, Node *y) {
  if (!x || !y)
    return 0;

  Node *rootX = findSet(x);
  Node *rootY = findSet(y);

  if (rootX == rootY)
    return 0; // Ya están en el mismo conjunto

  link(rootX, rootY);
  return 1;
}
