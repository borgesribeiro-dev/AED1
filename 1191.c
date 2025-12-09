#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 60

typedef struct No {
    char valor;
    struct No *esq;
    struct No *dir;
} No;

No *novo_no(char v) {
    No *p = (No *)malloc(sizeof(No));
    if (!p) exit(1);
    p->valor = v;
    p->esq = p->dir = NULL;
    return p;
}

int acha_pos(const char *in, int ini, int fim, char ch) {
    for (int i = ini; i <= fim; i++) {
        if (in[i] == ch) return i;
    }
    return -1;
}

No *construir(const char *pre, const char *in,
              int pre_ini, int pre_fim,
              int in_ini, int in_fim) {
    if (pre_ini > pre_fim || in_ini > in_fim)
        return NULL;

    char raiz_val = pre[pre_ini];
    int pos_raiz = acha_pos(in, in_ini, in_fim, raiz_val);

    No *raiz = novo_no(raiz_val);

    int tam_esq = pos_raiz - in_ini;

    raiz->esq = construir(pre, in,
                          pre_ini + 1,
                          pre_ini + tam_esq,
                          in_ini,
                          pos_raiz - 1);

    raiz->dir = construir(pre, in,
                          pre_ini + tam_esq + 1,
                          pre_fim,
                          pos_raiz + 1,
                          in_fim);

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

int main(void) {
    char pre[MAXN], in[MAXN];

    while (scanf("%s %s", pre, in) == 2) {
        int n = (int)strlen(pre);

        No *raiz = construir(pre, in,
                             0, n - 1,
                             0, n - 1);

        posordem(raiz);
        putchar('\n');

        libera(raiz);
    }

    return 0;
}
