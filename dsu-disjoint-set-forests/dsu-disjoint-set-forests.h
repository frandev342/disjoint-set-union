#ifndef DISJOINTSETFORESTS_H
#define DISJOINTSETFORESTS_H
#include <stdlib.h>

typedef struct Node{
  int data;
  Node* parent;
  int rank;
} Node;

Node *makeSet(int value); //Crea solo un nodo, rank = 0
Node *findSet(Node *x); //Debe dejar los ranks sin cambios
void link(Node *x, Node *y); //Une 2 sets, 2 casos, uno si ambos rangos son iguales o el otro si son distintos
int unite(Node *x, Node *y); //Llama a la función link

#endif
