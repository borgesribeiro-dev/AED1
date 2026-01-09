#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 60

typedef struct no {
    char valor;
    struct no *esq;
    struct no *dir;
} No;

No *novo_no(char v) {
    No *n = (No *)malloc(sizeof(No));
    if (!n) exit(1);
    n->valor = v;
    n->esq = NULL;
    n->dir = NULL;
    return n;
}

int busca(const char *in, int ini, int fim, char c) {
    for (int i = ini; i <= fim; i++) {
        if (in[i] == c)
            return i;
    }
    return -1;
}

No *constroi(const char *pre, const char *in, int pi, int pf, int ii, int ifim) {
    if (pi > pf || ii > ifim)
        return NULL;

    char r = pre[pi];
    int pos = busca(in, ii, ifim, r);

    No *raiz = novo_no(r);
    int tam_esq = pos - ii;

    raiz->esq = constroi(pre, in, pi + 1, pi + tam_esq, ii, pos - 1);
    raiz->dir = constroi(pre, in, pi + tam_esq + 1, pf, pos + 1, ifim);

    return raiz;
}

void posordem(No *raiz) {
    if (!raiz) return;
    posordem(raiz->esq);
    posordem(raiz->dir);
    putchar(raiz->valor);
}

void libera(No *raiz) {
    if (!raiz) return;
    libera(raiz->esq);
    libera(raiz->dir);
    free(raiz);
}

int main() {
    char pre[MAXN], in[MAXN];

    while (scanf("%s %s", pre, in) == 2) {
        int n = strlen(pre);

        No *raiz = constroi(pre, in, 0, n - 1, 0, n - 1);

        posordem(raiz);
        putchar('\n');

        libera(raiz);
    }

    return 0;
}

