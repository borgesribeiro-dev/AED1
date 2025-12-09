#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int v;
    struct No *prox;
} No;

void addAresta(No **adj, int a, int b) {
    No *novo = malloc(sizeof(No));
    novo->v = b;
    novo->prox = adj[a];
    adj[a] = novo;
}

void dfs(int u, No **adj, int *vis, int *comp, int *p) {
    vis[u] = 1;
    comp[(*p)++] = u;

    for (No *aux = adj[u]; aux != NULL; aux = aux->prox) {
        if (!vis[aux->v]) {
            dfs(aux->v, adj, vis, comp, p);
        }
    }
}

int cmpInt(const void *a, const void *b) {
    int ia = *(const int*)a;
    int ib = *(const int*)b;
    return ia - ib;
}

int main() {
    int T;
    if (scanf("%d", &T) != 1) return 0;

    for (int caso = 1; caso <= T; caso++) {
        int n, m;
        scanf("%d %d", &n, &m);

        No **adj = calloc(n, sizeof(No*));
        int *vis = calloc(n, sizeof(int));

        for (int i = 0; i < m; i++) {
            char a, b;
            scanf(" %c %c", &a, &b);
            int x = a - 'a';
            int y = b - 'a';
            addAresta(adj, x, y);
            addAresta(adj, y, x);
        }

        printf("Case #%d:\n", caso);

        int componentes = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                int *comp = malloc(n * sizeof(int)); // no máximo n vértices na componente
                int p = 0;

                dfs(i, adj, vis, comp, &p);

                qsort(comp, p, sizeof(int), cmpInt);

                for (int k = 0; k < p; k++) {
                    printf("%c,", (char)(comp[k] + 'a'));
                }
                printf("\n");

                componentes++;
                free(comp);
            }
        }

        printf("%d connected components\n\n", componentes);

        // libera memória do grafo
        for (int i = 0; i < n; i++) {
            No *aux = adj[i];
            while (aux) {
                No *tmp = aux;
                aux = aux->prox;
                free(tmp);
            }
        }

        free(adj);
        free(vis);
    }

    return 0;
}
