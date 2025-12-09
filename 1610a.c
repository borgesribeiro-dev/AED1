// 1610 - Dudu Service Maker

#include <stdio.h>
#include <stdlib.h>

#define MAXN 1000

int adj[MAXN][MAXN];
int cor[MAXN];
int n, m;
int tem_ciclo;

void dfs(int u) {
    cor[u] = 1;

    for (int v = 0; v < n; v++) {
        if (!adj[u][v]) continue;

        if (cor[v] == 1) {
            tem_ciclo = 1;
            return;
        }
        if (cor[v] == 0) {
            dfs(v);
            if (tem_ciclo) return;
        }
    }

    cor[u] = 2;
}

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;

    while (t--) {
        scanf("%d %d", &n, &m);

        for (int i = 0; i < n; i++) {
            cor[i] = 0;
            for (int j = 0; j < n; j++) {
                adj[i][j] = 0;
            }
        }

        for (int i = 0; i < m; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            a--;
            b--;
            adj[a][b] = 1;
        }

        tem_ciclo = 0;

        for (int i = 0; i < n && !tem_ciclo; i++) {
            if (cor[i] == 0) {
                dfs(i);
            }
        }

        if (tem_ciclo) printf("SIM\n");
        else printf("NAO\n");
    }

    return 0;
}
