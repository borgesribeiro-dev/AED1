// 1148 - Países em Guerra

#include <stdio.h>

#define MAXN 505
#define INF 1000000000

int n, m;
int adj[MAXN][MAXN];
int distv[MAXN];
int usado[MAXN];

int dijkstra(int s, int t) {
    for (int i = 1; i <= n; i++) {
        distv[i] = INF;
        usado[i] = 0;
    }

    distv[s] = 0;

    for (int k = 0; k < n; k++) {
        int u = -1;
        int melhor = INF;

        for (int i = 1; i <= n; i++) {
            if (!usado[i] && distv[i] < melhor) {
                melhor = distv[i];
                u = i;
            }
        }

        if (u == -1 || u == t) break;

        usado[u] = 1;

        for (int v = 1; v <= n; v++) {
            if (adj[u][v] < INF) {
                int novo = distv[u] + adj[u][v];
                if (novo < distv[v]) distv[v] = novo;
            }
        }
    }

    return distv[t];
}

int main() {
    while (1) {
        if (scanf("%d %d", &n, &m) != 2) return 0;
        if (n == 0 && m == 0) break;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                adj[i][j] = INF;
            }
        }

        for (int i = 0; i < m; i++) {
            int x, y, h;
            scanf("%d %d %d", &x, &y, &h);

            if (adj[y][x] < INF) {
                adj[x][y] = 0;
                adj[y][x] = 0;
            } else if (h < adj[x][y]) {
                adj[x][y] = h;
            }
        }

        int q;
        scanf("%d", &q);

        for (int i = 0; i < q; i++) {
            int s, t;
            scanf("%d %d", &s, &t);

            int ans = dijkstra(s, t);

            if (ans == INF)
                printf("Nao e possivel entregar a carta\n");
            else
                printf("%d\n", ans);
        }

        printf("\n");
    }

    return 0;
}
