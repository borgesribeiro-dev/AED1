#include <stdio.h>

#define MAXV 20

int v, e;
int adj[MAXV][MAXV];
int visitado[MAXV];

int dfs(int u, int nivel) {
    int teve_aresta = 0;
    visitado[u] = 1;

    for (int w = 0; w < v; w++) {
        if (adj[u][w]) {
            teve_aresta = 1;
            for (int k = 0; k < nivel; k++) putchar(' ');
            if (!visitado[w]) {
                printf("%d-%d pathR(G,%d)\n", u, w, w);
                dfs(w, nivel + 2);
            } else {
                printf("%d-%d\n", u, w);
            }
        }
    }

    return teve_aresta;
}

int main(void) {
    int t;

    if (scanf("%d", &t) != 1) return 0;

    for (int caso = 1; caso <= t; caso++) {
        scanf("%d %d", &v, &e);

        for (int i = 0; i < v; i++) {
            visitado[i] = 0;
            for (int j = 0; j < v; j++)
                adj[i][j] = 0;
        }

        for (int i = 0; i < e; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            if (a >= 0 && a < v && b >= 0 && b < v)
                adj[a][b] = 1;
        }

        printf("Caso %d:\n", caso);

        for (int s = 0; s < v; s++) {
            if (!visitado[s]) {
                int ok = dfs(s, 2);
                if (ok) printf("\n");
            }
        }
    }

    return 0;
}
