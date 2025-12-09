#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    char val;
    struct no *esq, *dir;
} no;

no* novo(char v) {
    no *t = (no*)malloc(sizeof(no));
    t->val = v;
    t->esq = NULL;
    t->dir = NULL;
    return t;
}

no* inserir(no *r, char v) {
    if (r == NULL) return novo(v);
    if (v < r->val) r->esq = inserir(r->esq, v);
    else if (v > r->val) r->dir = inserir(r->dir, v);
    return r;
}

int buscar(no *r, char v) {
    if (r == NULL) return 0;
    if (v == r->val) return 1;
    if (v < r->val) return buscar(r->esq, v);
    return buscar(r->dir, v);
}

int first;

void prefixa(no *r) {
    if (r == NULL) return;
    if (first == 0) printf(" ");
    printf("%c", r->val);
    first = 0;
    prefixa(r->esq);
    prefixa(r->dir);
}

void infixa(no *r) {
    if (r == NULL) return;
    infixa(r->esq);
    if (first == 0) printf(" ");
    printf("%c", r->val);
    first = 0;
    infixa(r->dir);
}

void posfixa(no *r) {
    if (r == NULL) return;
    posfixa(r->esq);
    posfixa(r->dir);
    if (first == 0) printf(" ");
    printf("%c", r->val);
    first = 0;
}

void limpar(no *r) {
    if (r == NULL) return;
    limpar(r->esq);
    limpar(r->dir);
    free(r);
}

int main() {
    no *raiz = NULL;
    char op[20], c;

    while (scanf("%s", op) != EOF) {

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
            first = 1;
            prefixa(raiz);
            printf("\n");
        }

        else if (op[0] == 'I' && op[1] == 'N') {
            first = 1;
            infixa(raiz);
            printf("\n");
        }

        else if (op[0] == 'P' && op[1] == 'O') {
            first = 1;
            posfixa(raiz);
            printf("\n");
        }
    }

    limpar(raiz);
    return 0;
}
