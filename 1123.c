// 1123 - Desvio de Rota

#include <stdio.h>
#include <stdlib.h>

#define INF 1000000000
#define MAXN 1010

int n, m, c, k;
int mat[MAXN][MAXN];  // matriz de adjacência
int distv[MAXN];      // custo mínimo até cada cidade
int fila[MAXN];       // fila simples
int ini, fim;

void inicializa_grafo() {
    for (int i = 0; i < n; i++) {
        distv[i] = INF;
        for (int j = 0; j < n; j++) {
            mat[i][j] = INF;
        }
    }
}

int dijkstra_simples(int origem, int destino) {
    ini = 0;
    fim = 0;

    distv[origem] = 0;
    fila[fim++] = origem;

    while (ini != fim) {
        int u = fila[ini++];

        for (int v = 0; v < n; v++) {
            if (mat[u][v] != INF && distv[v] > distv[u] + mat[u][v]) {
                distv[v] = distv[u] + mat[u][v];
                fila[fim++] = v;
            }
        }
    }

    return distv[destino];
}

int main() {
    while (1) {
        if (scanf("%d %d %d %d", &n, &m, &c, &k) != 4)
            return 0;
        if (n == 0 && m == 0 && c == 0 && k == 0)
            break;

        inicializa_grafo();

        for (int i = 0; i < m; i++) {
            int a, b, p;
            scanf("%d %d %d", &a, &b, &p);

            int a_rota = (a < c);
            int b_rota = (b < c);

            if (!a_rota && !b_rota) {
                // duas cidades fora da rota: bidirecional
                if (p < mat[a][b]) {
                    mat[a][b] = p;
                    mat[b][a] = p;
                }
            } else if (!a_rota && b_rota) {
                // entra na rota pela cidade b
                if (p < mat[a][b]) {
                    mat[a][b] = p;
                }
            } else if (a_rota && !b_rota) {
                // entra na rota pela cidade a
                if (p < mat[b][a]) {
                    mat[b][a] = p;
                }
            } else {
                // ambos na rota: só entre consecutivas
                if (abs(a - b) == 1 && p < mat[a][b]) {
                    mat[a][b] = p;
                    mat[b][a] = p;
                }
            }
        }

        int resposta = dijkstra_simples(k, c - 1);
        printf("%d\n", resposta);
    }

    return 0;
}
