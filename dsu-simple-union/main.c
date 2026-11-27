#include "dsu-simple-union.h"
#include "stdio.h"

int main() {
  DSU dsu;
  initDSU(&dsu);
  Node *n1 = makeSet(&dsu, 1);
  Node *n2 = makeSet(&dsu, 2);
  Node *n3 = makeSet(&dsu, 3);
  Node *n4 = makeSet(&dsu, 4);
  unite(&dsu, n1, n2);
  unite(&dsu, n2, n3);

  printf("Representante: %d", findSet(n3)->value); // 1

  return 0;
}
