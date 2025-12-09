// 1610 - Dudu Service Maker (lista de adjacência)

#include <stdio.h>
#include <stdlib.h>

#define MAXN 10005
#define MAXM 200005

int ini[MAXN];
int prox[MAXM];
int dest[MAXM];
int cor[MAXN];
int n, m, epos;
int tem_ciclo;

void adiciona(int u, int v) {
    dest[epos] = v;
    prox[epos] = ini[u];
    ini[u] = epos;
    epos++;
}

void dfs(int u) {
    cor[u] = 1;

    for (int e = ini[u]; e != -1; e = prox[e]) {
        int v = dest[e];

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

        epos = 0;
        for (int i = 0; i < n; i++) {
            ini[i] = -1;
            cor[i] = 0;
        }

        for (int i = 0; i < m; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            a--;
            b--;
            adiciona(a, b);
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
