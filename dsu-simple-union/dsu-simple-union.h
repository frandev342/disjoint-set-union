#ifndef DSU_SIMPLE_UNION_H
#define DSU_SIMPLE_UNION_H

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
int findSet(Node *x);
// Unir el conjunto de x con el conjunto y, manteniendo el representate de x
void unite(Node *x, Node *y);

#endif // !
