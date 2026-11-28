#include <stdio.h>
#include <stdlib.h>
#include "dsu.h"

#define MAX 1001

int main() {
    int n, d1, d2;
    if (scanf("%d", &n) != 1)
        return 0;

    DSU dsu;
    if (!initDSU(&dsu, n))
        return 0;

    for (int i = 1; i <= n; i++) {
        makeSet(&dsu, i);
    }

    int arr[MAX][4];
    int dia = 0;

    for (int i = 0; i < n - 1; i++) {
        scanf("%d %d", &d1, &d2);
        Node *n1 = dsu.nodes[d1 - 1];
        Node *n2 = dsu.nodes[d2 - 1];

        if (findSet(n1) == findSet(n2)) {
            arr[dia][0] = d1;
            arr[dia][1] = d2;
            dia++;
        } else {
            unite(&dsu, n1, n2);
        }
    }

    Node *base = findSet(dsu.nodes[0]);
    int cand = 2;

    for (int i = 0; i < dia; i++) {
        while (cand <= n && findSet(dsu.nodes[cand - 1]) == base) {
            cand++;
        }
        Node *nCand = dsu.nodes[cand - 1];
        arr[i][2] = base->value;
        arr[i][3] = cand;
        unite(&dsu, base, nCand);
        base = findSet(dsu.nodes[0]);
    }

    printf("%d\n", dia);
    for (int i = 0; i < dia; i++) {
        printf("%d %d %d %d\n", arr[i][0], arr[i][1], arr[i][2], arr[i][3]);
    }

    destroyDSU(&dsu);
    return 0;
}
