#include "dsu-simple-union.h"
#include <stdlib.h>

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
