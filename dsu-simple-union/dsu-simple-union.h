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

int findSet(Node *x);

#endif // !
