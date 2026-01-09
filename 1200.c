#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    char val;
    struct no *esq;
    struct no *dir;
} no;

no* novo(char v) {
    no *r = (no*)malloc(sizeof(no));
    r->val = v;
    r->esq = NULL;
    r->dir = NULL;
    return r;
}

no* inserir(no *r, char v) {
    if (!r) return novo(v);
    if (v < r->val) r->esq = inserir(r->esq, v);
    else if (v > r->val) r->dir = inserir(r->dir, v);
    return r;
}

int buscar(no *r, char v) {
    if (!r) return 0;
    if (v == r->val) return 1;
    if (v < r->val) return buscar(r->esq, v);
    return buscar(r->dir, v);
}

void prefixa(no *r, int *first) {
    if (!r) return;
    if (!(*first)) printf(" ");
    printf("%c", r->val);
    *first = 0;
    prefixa(r->esq, first);
    prefixa(r->dir, first);
}

void infixa(no *r, int *first) {
    if (!r) return;
    infixa(r->esq, first);
    if (!(*first)) printf(" ");
    printf("%c", r->val);
    *first = 0;
    infixa(r->dir, first);
}

void posfixa(no *r, int *first) {
    if (!r) return;
    posfixa(r->esq, first);
    posfixa(r->dir, first);
    if (!(*first)) printf(" ");
    printf("%c", r->val);
    *first = 0;
}

void limpar(no *r) {
    if (!r) return;
    limpar(r->esq);
    limpar(r->dir);
    free(r);
}

int main() {
    no *raiz = NULL;
    char op[20], c;

    while (scanf("%s", op) == 1) {

        if (op[0] == 'I' && op[1] == '\0') {
            scanf(" %c", &c);
            raiz = inserir(raiz, c);
        }

        else if (op[0] == 'P' && op[1] == '\0') {
            scanf(" %c", &c);
            if (buscar(raiz, c)) printf("%c existe\n", c);
            else printf("%c nao existe\n", c);
        }

        else if (op[0] == 'P' && op[1] == 'R') {
            int first = 1;
            prefixa(raiz, &first);
            printf("\n");
        }

        else if (op[0] == 'I' && op[1] == 'N') {
            int first = 1;
            infixa(raiz, &first);
            printf("\n");
        }

        else if (op[0] == 'P' && op[1] == 'O') {
            int first = 1;
            posfixa(raiz, &first);
            printf("\n");
        }
    }

    limpar(raiz);
    return 0;
}

