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

Node *findSet(Node *x) {
  if (!x)
    return NULL;
  // Devolver head->value, es nuestro representante
  return x->set->head;
}

void unite(Node *x, Node *y) {
  if (!x || !y)
    return;
  Set *A = x->set;
  Set *B = y->set;

  // Preguntar si perteneccen al mismo conjunto, entoncesn no hacer nada
  if (A == B)
    return;

  // conectar lista B a la cola de la lista A
  A->tail->next = B->head;
  A->tail = B->tail; // actualizar cola de A

  // actualizar al set que apunta cada nodo
  Node *current = B->head;
  while (current) {
    current->set = A;
    current = current->next;
  }
  // Liberamos el conjunto B
  free(B);
}
