#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    
    char *mapa = malloc((size_t)n * m * sizeof(char));
    int *vis = calloc((size_t)n * m, sizeof(int));
    char *linha = malloc((size_t)m + 1);

    for (int i = 0; i < n; i++) {
        scanf("%s", linha);
        memcpy(mapa + (size_t)i * m, linha, m);
    }
    free(linha);

    int *fila = malloc((size_t)n * m * sizeof(int));
    int regioes = 0;

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int idx = i * m + j;

            
            if (vis[idx] || mapa[idx] == 'o') continue;

            
            int ini = 0, fim = 0;
            fila[fim++] = idx;
            vis[idx] = 1;

            while (ini < fim) {
                int cur = fila[ini++];
                int cx = cur / m;
                int cy = cur % m;

                for (int d = 0; d < 4; d++) {
                    int nx = cx + dx[d];
                    int ny = cy + dy[d];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    int nidx = nx * m + ny;
                    if (!vis[nidx] && mapa[nidx] == '.') {
                        vis[nidx] = 1;
                        fila[fim++] = nidx;
                    }
                }
            }

            regioes++;
        }
    }

    printf("%d\n", regioes);

    free(mapa);
    free(vis);
    free(fila);
    return 0;
}
