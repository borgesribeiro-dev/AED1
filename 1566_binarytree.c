// 1566 - Altura (usando árvore binária de busca)

#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *esq;
    struct no *dir;
} No;

No* insere(No *raiz, int x) {
    if (raiz == NULL) {
        No *novo = (No*)malloc(sizeof(No));
        novo->valor = x;
        novo->esq = NULL;
        novo->dir = NULL;
        return novo;
    }
    if (x < raiz->valor) {
        raiz->esq = insere(raiz->esq, x);
    } else {
        raiz->dir = insere(raiz->dir, x);
    }
    return raiz;
}

void imprime_ordem(No *raiz, int *primeiro) {
    if (raiz == NULL) return;

    imprime_ordem(raiz->esq, primeiro);

    if (*primeiro) {
        printf("%d", raiz->valor);
        *primeiro = 0;
    } else {
        printf(" %d", raiz->valor);
    }

    imprime_ordem(raiz->dir, primeiro);
}

void libera(No *raiz) {
    if (raiz == NULL) return;
    libera(raiz->esq);
    libera(raiz->dir);
    free(raiz);
}

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;

    while (t--) {
        int n;
        scanf("%d", &n);

        No *raiz = NULL;

        for (int i = 0; i < n; i++) {
            int h;
            scanf("%d", &h);
            raiz = insere(raiz, h);
        }

        int primeiro = 1;
        imprime_ordem(raiz, &primeiro);
        printf("\n");

        libera(raiz);
    }

    return 0;
}
