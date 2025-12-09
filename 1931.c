// 1931 - Mania de Par

#include <stdio.h>
#include <stdlib.h>

#define MAXN 100005
#define MAXM 200005
#define INF  1000000000

typedef struct {
    int v;
    int w;
    int next;
} Aresta;

typedef struct {
    int nodo;
    int dist;
} NoHeap;

Aresta grafo[2 * MAXM];  // grafo estendido (2 estados)
int head[2 * MAXN];
int distv[2 * MAXN];
int usado[2 * MAXN];

NoHeap heap[2 * MAXN * 2];
int hsz;

void heap_swap(int i, int j) {
    NoHeap tmp = heap[i];
    heap[i] = heap[j];
    heap[j] = tmp;
}

void heap_push(int nodo, int d) {
    int i = ++hsz;
    heap[i].nodo = nodo;
    heap[i].dist = d;
    while (i > 1 && heap[i].dist < heap[i/2].dist) {
        heap_swap(i, i/2);
        i /= 2;
    }
}

int heap_vazio() {
    return hsz == 0;
}

NoHeap heap_pop() {
    NoHeap topo = heap[1];
    heap[1] = heap[hsz--];
    int i = 1;
    while (1) {
        int esq = 2*i, dir = 2*i+1, menor = i;
        if (esq <= hsz && heap[esq].dist < heap[menor].dist) menor = esq;
        if (dir <= hsz && heap[dir].dist < heap[menor].dist) menor = dir;
        if (menor == i) break;
        heap_swap(i, menor);
        i = menor;
    }
    return topo;
}

int cont_aresta;

void add_aresta(int u, int v, int w) {
    grafo[cont_aresta].v = v;
    grafo[cont_aresta].w = w;
    grafo[cont_aresta].next = head[u];
    head[u] = cont_aresta++;
}

int main() {
    int n, m;

    if (scanf("%d %d", &n, &m) != 2) return 0;

    for (int i = 0; i < 2*n + 5; i++) {
        head[i] = -1;
        distv[i] = INF;
        usado[i] = 0;
    }
    cont_aresta = 0;
    hsz = 0;

    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);

        // estados:
        // a_par = a*2, a_impar = a*2+1
        // b_par = b*2, b_impar = b*2+1

        int a_par   = a * 2;
        int a_impar = a * 2 + 1;
        int b_par   = b * 2;
        int b_impar = b * 2 + 1;

        // estrada é bidirecional, mas cada uso troca par/ímpar
        add_aresta(a_par,   b_impar, c);
        add_aresta(a_impar, b_par,   c);
        add_aresta(b_par,   a_impar, c);
        add_aresta(b_impar, a_par,   c);
    }

    int origem = 1 * 2;       // 1 com 0 arestas (par)
    int destino = n * 2;      // N com número par de arestas

    distv[origem] = 0;
    heap_push(origem, 0);

    while (!heap_vazio()) {
        NoHeap at = heap_pop();
        int u = at.nodo;

        if (usado[u]) continue;
        usado[u] = 1;
        if (u == destino) break;

        for (int e = head[u]; e != -1; e = grafo[e].next) {
            int v = grafo[e].v;
            int w = grafo[e].w;
            if (!usado[v] && distv[v] > distv[u] + w) {
                distv[v] = distv[u] + w;
                heap_push(v, distv[v]);
            }
        }
    }

    if (distv[destino] == INF)
        printf("-1\n");
    else
        printf("%d\n", distv[destino]);

    return 0;
}
