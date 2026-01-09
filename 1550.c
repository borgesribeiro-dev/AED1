#include <stdio.h>
#include <stdlib.h>

typedef struct fila {
    int v;
    int passo;
    struct fila *prox;
} fila;

void push(fila **ini, fila **fim, int v, int passo) {
    fila *novo = malloc(sizeof(fila));
    novo->v = v;
    novo->passo = passo;
    novo->prox = NULL;
    if (*fim) (*fim)->prox = novo;
    else *ini = novo;
    *fim = novo;
}

void pop(fila **ini, fila **fim) {
    fila *tmp = *ini;
    *ini = (*ini)->prox;
    if (*ini == NULL) *fim = NULL;
    free(tmp);
}

int inverte(int x) {
    int r = 0;
    while (x > 0) {
        r = r*10 + (x % 10);
        x /= 10;
    }
    return r;
}

int bfs(int n, int m) {
    int limite = 2000000;

    int *vis = calloc(limite + 1, sizeof(int));

    fila *ini = NULL, *fim = NULL;
    push(&ini, &fim, n, 0);
    vis[n] = 1;

    while (ini) {
        int v = ini->v;
        int passo = ini->passo;

        if (v == m) {
            free(vis);
            return passo;
        }

        
        int a = v + 1;
        if (a <= limite && !vis[a]) {
            vis[a] = 1;
            push(&ini, &fim, a, passo + 1);
        }

        
        int b = inverte(v);
        if (b <= limite && !vis[b]) {
            vis[b] = 1;
            push(&ini, &fim, b, passo + 1);
        }

        pop(&ini, &fim);
    }

    free(vis);
    return -1;
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n, m;
        scanf("%d %d", &n, &m);

        printf("%d\n", bfs(n, m));
    }

    return 0;
}
