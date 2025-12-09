// 1466 - Percurso em Árvore por Nível

#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *esq;
    struct no *dir;
} No;

No* insere_abp(No *raiz, int x) {
    if (raiz == NULL) {
        No *novo = (No*)malloc(sizeof(No));
        novo->valor = x;
        novo->esq = NULL;
        novo->dir = NULL;
        return novo;
    }
    if (x < raiz->valor) {
        raiz->esq = insere_abp(raiz->esq, x);
    } else {
        raiz->dir = insere_abp(raiz->dir, x);
    }
    return raiz;
}

void libera_arvore(No *raiz) {
    if (raiz == NULL) return;
    libera_arvore(raiz->esq);
    libera_arvore(raiz->dir);
    free(raiz);
}

#define MAXN 2000

void percurso_nivel(No *raiz, int qtd) {
    No *fila[MAXN];
    int ini = 0, fim = 0;

    if (raiz != NULL) {
        fila[fim++] = raiz;
    }

    int imp = 0;

    while (ini != fim) {
        No *p = fila[ini++];

        if (imp) printf(" ");
        printf("%d", p->valor);
        imp = 1;

        if (p->esq != NULL) fila[fim++] = p->esq;
        if (p->dir != NULL) fila[fim++] = p->dir;
    }
    printf("\n");
}

int main() {
    int c, n;
    int caso = 1;

    if (scanf("%d", &c) != 1) return 0;

    while (c--) {
        if (scanf("%d", &n) != 1) return 0;

        No *raiz = NULL;

        for (int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            raiz = insere_abp(raiz, x);
        }

        printf("Case %d:\n", caso);
        percurso_nivel(raiz, n);
        printf("\n");

        libera_arvore(raiz);
        caso++;
    }

    return 0;
}
