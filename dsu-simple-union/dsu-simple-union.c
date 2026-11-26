#include "dsu-simple-union.h"
#include <stdlib.h>

Node *makeSet(int value) {
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

  return x;
}

int findSet(Node *x) {
  // Devolver head->value, es nuestro representante
  return x->set->head->value;
}

void unite(Node *x, Node *y) {
  Set *A = x->set;
  Set *B = y->set;
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
  free(B);
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
