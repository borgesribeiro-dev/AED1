/*1152 - Dark Roads*/

#include <stdio.h>
#include <stdlib.h>

#define MAXE 200000
#define MAXV 200000

typedef struct {
    int u, v;
    int w;
} Aresta;

Aresta vet[MAXE];
int pai[MAXV];
int peso[MAXV];

int find_set(int x) {
    if (pai[x] == x) return x;
    pai[x] = find_set(pai[x]);
    return pai[x];
}

void union_set(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a == b) return;
    if (peso[a] < peso[b]) {
        pai[a] = b;
    } else if (peso[b] < peso[a]) {
        pai[b] = a;
    } else {
        pai[b] = a;
        peso[a]++;
    }
}

int cmp_aresta(const void *p1, const void *p2) {
    Aresta *a = (Aresta*)p1;
    Aresta *b = (Aresta*)p2;
    if (a->w < b->w) return -1;
    if (a->w > b->w) return 1;
    return 0;
}

int main() {
    int m, n;

    while (1) {
        if (scanf("%d %d", &m, &n) != 2) return 0;
        if (m == 0 && n == 0) break;

        long long total = 0;

        for (int i = 0; i < n; i++) {
            int x, y, z;
            scanf("%d %d %d", &x, &y, &z);
            vet[i].u = x;
            vet[i].v = y;
            vet[i].w = z;
            total += z;
        }

        
        for (int i = 0; i < m; i++) {
            pai[i] = i;
            peso[i] = 0;
        }

        
        qsort(vet, n, sizeof(Aresta), cmp_aresta);

        long long mst = 0;

        
        for (int i = 0; i < n; i++) {
            int a = vet[i].u;
            int b = vet[i].v;
            int w = vet[i].w;

            if (find_set(a) != find_set(b)) {
                union_set(a, b);
                mst += w;
            }
        }

        printf("%lld\n", total - mst);
    }

    return 0;
}
