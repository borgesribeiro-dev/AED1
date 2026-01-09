#include <stdio.h>
#include <stdlib.h>

#define MAX 2000

typedef struct no {
    int val;
    struct no *esq;
    struct no *dir;
} no;

no* inserir(no *r, int x) {
    if (r == NULL) {
        no *novo = (no*)malloc(sizeof(no));
        novo->val = x;
        novo->esq = NULL;
        novo->dir = NULL;
        return novo;
    }

    if (x < r->val)
        r->esq = inserir(r->esq, x);
    else
        r->dir = inserir(r->dir, x);

    return r;
}

void limpar(no *r) {
    if (r == NULL) return;
    limpar(r->esq);
    limpar(r->dir);
    free(r);
}

void nivel(no *r) {
    no *fila[MAX];
    int ini = 0, fim = 0;
    int primeiro = 1;

    if (r != NULL)
        fila[fim++] = r;

    while (ini < fim) {
        no *p = fila[ini++];

        if (!primeiro) printf(" ");
        printf("%d", p->val);
        primeiro = 0;

        if (p->esq) fila[fim++] = p->esq;
        if (p->dir) fila[fim++] = p->dir;
    }

    printf("\n");
}

int main() {
    int c, n;
    int caso = 1;

    scanf("%d", &c);

    while (c--) {
        scanf("%d", &n);

        no *raiz = NULL;

        for (int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            raiz = inserir(raiz, x);
        }

        printf("Case %d:\n", caso++);
        nivel(raiz);
        printf("\n");

        limpar(raiz);
    }

    return 0;
}
