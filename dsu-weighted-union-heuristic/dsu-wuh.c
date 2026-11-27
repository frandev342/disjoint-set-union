#include "dsu-wuh.h"
#include <stdlib.h>

Node *makeSet(DSU *dsu, int value) {
  Node *x = malloc(sizeof(*x));
  if (!x)
    return NULL;
  x->value = value;
  x->next = NULL;
  x->set = NULL;

  Set *set = malloc(sizeof(*set));
  if (!set)
    return NULL;
  set->head = x;
  set->tail = x;
  set->length = 0;
  set->nextSet = 0;

  dsu->sets = set;
  return x;
}
