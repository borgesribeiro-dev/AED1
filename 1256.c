// 1256 - Tabelas Hash

#include <stdio.h>
#include <stdlib.h>

typedef struct cel {
    int valor;
    struct cel *prox;
} Cel;

Cel *tab[105];

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    for (int caso = 0; caso < n; caso++) {
        int M, C;
        scanf("%d %d", &M, &C);

        for (int i = 0; i < M; i++) tab[i] = NULL;

        for (int i = 0; i < C; i++) {
            int x;
            scanf("%d", &x);
            int h = x % M;

            Cel *novo = (Cel*)malloc(sizeof(Cel));
            novo->valor = x;
            novo->prox = NULL;

            if (tab[h] == NULL) {
                tab[h] = novo;
            } else {
                Cel *p = tab[h];
                while (p->prox != NULL) p = p->prox;
                p->prox = novo;
            }
        }

        for (int i = 0; i < M; i++) {
            printf("%d ->", i);
            Cel *p = tab[i];
            while (p != NULL) {
                printf(" %d ->", p->valor);
                p = p->prox;
            }
            printf(" \\\n");
        }

        if (caso != n - 1) printf("\n");
    }

    return 0;
}
