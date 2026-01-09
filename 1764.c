// 1764 - Itinerário do Papai Noel

#include <stdio.h>
#include <stdlib.h>

#define MAXE 50000
#define MAXV 40000

typedef struct {
    int u, v;
    int w;
} Aresta;

Aresta vet[MAXE];
int pai[MAXV];
int altura[MAXV];

int encontra(int x) {
    if (pai[x] == x) return x;
    pai[x] = encontra(pai[x]);
    return pai[x];
}

void junta(int a, int b) {
    a = encontra(a);
    b = encontra(b);
    if (a == b) return;

    if (altura[a] < altura[b]) {
        pai[a] = b;
    } else if (altura[b] < altura[a]) {
        pai[b] = a;
    } else {
        pai[b] = a;
        altura[a]++;
    }
}

int compara_aresta(const void *p1, const void *p2) {
    const Aresta *a = (const Aresta*)p1;
    const Aresta *b = (const Aresta*)p2;
    if (a->w < b->w) return -1;
    if (a->w > b->w) return 1;
    return 0;
}

int main() {
    int m, n;

    while (1) {
        if (scanf("%d %d", &m, &n) != 2) return 0;
        if (m == 0 && n == 0) break;

        for (int i = 0; i < n; i++) {
            int x, y, z;
            scanf("%d %d %d", &x, &y, &z);
            vet[i].u = x;   
            vet[i].v = y;
            vet[i].w = z;
        }

        
        for (int i = 0; i < m; i++) {
            pai[i] = i;
            altura[i] = 0;
        }

        
        qsort(vet, n, sizeof(Aresta), compara_aresta);

        long long custo_mst = 0;
        int usados = 0;

        
        for (int i = 0; i < n && usados < m - 1; i++) {
            int a = vet[i].u;
            int b = vet[i].v;
            int w = vet[i].w;

            if (encontra(a) != encontra(b)) {
                junta(a, b);
                custo_mst += w;
                usados++;
            }
        }

        printf("%lld\n", custo_mst);
    }

    return 0;
}
