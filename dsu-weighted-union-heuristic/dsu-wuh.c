#include "dsu-wuh.h"
#include <stdlib.h>

Node *makeSet(int value) {
  Node *x = malloc(sizeof(*x));
  if (!x)
    return NULL;
  Set *set = malloc(sizeof(*set));
  if (!set)
    return NULL;

  x->value = value;
  x->next = NULL;
  x->set = set;

  set->head = x;
  set->tail = x;
  set->length = 1;

  return x;
}

Node *findSet(Node *x) {
  if (!x)
    return NULL;
  return x->set->head;
}

void unite(Node *x, Node *y) {
  if (!x || !y)
    return;
  Set *A = x->set;
  Set *B = y->set;

  // Preguntar si pertenecen al mismo conjunto x e y
  if (A == B)
    return;

  Set *biggerSet, *smallerSet;

  // El conjunto de menor elemntos se une a la cola al mayor
  if (B->length <= A->length) {
    A->tail->next = B->head;
    A->tail = B->tail;
    biggerSet = A;
    smallerSet = B;

  } else {
    B->tail->next = A->head;
    B->tail = A->tail;
    biggerSet = B;
    smallerSet = A;
  }
  biggerSet->length += smallerSet->length;

  // Actualizar el set que apunta cada nodo del set pequeño
  Node *current = smallerSet->head;
  while (current) {
    current->set = biggerSet;
    current = current->next;
  }

  // Liberamos al pequeño
  free(smallerSet);
  return;
}
