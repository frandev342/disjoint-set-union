#include "dsu-simple-union.h"
#include <stdlib.h>

Node *makeSet(DSU *dsu, int value) {
  Set *set = malloc(sizeof(*set));
  if (!set)
    return NULL;

  Node *x = malloc(sizeof(*x));
  if (!x)
    return NULL;

  x->value = value;
  x->next = NULL;
  x->set = set;

  set->head = x;
  set->tail = x;

  set->nextSet = dsu->sets;
  dsu->sets = set;

  return x;
}

Node *findSet(Node *x) {
  if (!x)
    return NULL;
  // Devolver head->value, es nuestro representante
  return x->set->head;
}

int unite(DSU *dsu, Node *x, Node *y) {
  if (x == NULL || y == NULL)
    return 0;
  Set *A = x->set;
  Set *B = y->set;

  // Preguntar si perteneccen al mismo conjunto, entoncesn no hacer nada
  if (A == B)
    return 0;

  // conectar lista B a la cola de la lista A
  A->tail->next = B->head;
  A->tail = B->tail; // actualizar cola de A

  // actualizar al set que apunta cada nodo
  Node *current = B->head;
  while (current) {
    current->set = A;
    current = current->next;
  };
  // Liberamos el conjunto B
  Set *currentSet = dsu->sets;
  if (currentSet == B) {
    dsu->sets = currentSet->nextSet;
  } else {
    while (currentSet->nextSet != B)
      currentSet = currentSet->nextSet;
    currentSet->nextSet = B->nextSet;
  }
  free(B);
  return 1;
}

void initDSU(DSU *dsu) { dsu->sets = NULL; }
void destroyDSU(DSU *dsu) {
  Set *currentSet = dsu->sets;
  while (currentSet) {
    Node *currentNode = currentSet->head;
    while (currentSet) {
      Node *nextNode = currentNode->next;
      free(currentNode);
      currentNode = nextNode;
    }
    Set *nextSet = currentSet->nextSet;
    free(currentSet);
    currentSet = nextSet;
  }
}
