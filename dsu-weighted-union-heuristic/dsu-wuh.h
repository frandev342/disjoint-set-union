#ifndef DSU_WUH_H
#define DSU_WUH_H

typedef struct Set {
  struct Node *head;
  struct Node *tail;
  int length;
} Set;

typedef struct Node {
  int value;
  struct Node *next;
  Set *set;
} Node;

Node *findSet(Node *x);
Node *makeSet(int value);
void unite(Node *x, Node *y);

#endif // !
