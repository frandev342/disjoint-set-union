#include <stdlib.h>
#include <stdio.h>

#define MAX 1001

typedef struct Node {
    int value;
    int rank;
    struct Node *parent;
} Node;

struct dsu {
    Node *arr[MAX];
};

Node *makeSet(int value) {
    Node *x = malloc(sizeof(*x));
    if (!x)
        return NULL;

    x->value = value;
    x->parent = x;
    x->rank = 0;

    return x;
}

Node *findSet(Node *x) {
    if (!x)
        return NULL;

    if (x != x->parent) {
        x->parent = findSet(x->parent);
    }
    return x->parent;
}

void link(Node *x, Node *y) {
    if (!x || !y || x == y)
        return;

    if (x->rank > y->rank) {
        y->parent = x;
    } else {
        x->parent = y;
        if (x->rank == y->rank) {
            y->rank += 1;
        }
    }
}

int unite(Node *x, Node *y) {
    if (!x || !y)
        return 0;

    Node *rootX = findSet(x);
    Node *rootY = findSet(y);

    if (rootX == rootY)
        return 0;
    link(rootX, rootY);
    return 1;
}

int main() {
    int n, d1, d2;
    if (scanf("%d", &n) != 1)
        return 0;

    struct dsu d;
    for (int i = 1; i <= n; i++) {
        d.arr[i] = makeSet(i);
    }

    int arr[MAX][4];
    int dia = 0;

    for (int i = 0; i < n - 1; i++) {
        scanf("%d %d", &d1, &d2);
        if (findSet(d.arr[d1]) == findSet(d.arr[d2])) {
            arr[dia][0] = d1;
            arr[dia][1] = d2;
            dia++;
        } else {
            unite(d.arr[d1], d.arr[d2]);
        }
    }

    int u = findSet(d.arr[1])->value;
    int cand = 2;

    for (int i = 0; i < dia; i++) {
        while (cand <= n && findSet(d.arr[cand])->value == u) {
            cand++;
        }
        arr[i][2] = u;
        arr[i][3] = cand;
        unite(d.arr[u], d.arr[cand]);
        u = findSet(d.arr[1])->value;
    }

    printf("%d\n", dia);
    for (int i = 0; i < dia; i++) {
        printf("%d %d %d %d\n", arr[i][0], arr[i][1], arr[i][2], arr[i][3]);
    }

    for (int i = 1; i <= n; i++) {
        free(d.arr[i]);
    }

    return 0;
}
