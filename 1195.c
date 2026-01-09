#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int val;
    struct no *esq;
    struct no *dir;
} no;

no *novo(int v) {
    no *n = (no *)malloc(sizeof(no));
    n->val = v;
    n->esq = NULL;
    n->dir = NULL;
    return n;
}

no *inserir(no *r, int v) {
    if (r == NULL)
        return novo(v);

    if (v < r->val)
        r->esq = inserir(r->esq, v);
    else
        r->dir = inserir(r->dir, v);

    return r;
}

void preorder(no *r) {
    if (r == NULL) return;
    printf(" %d", r->val);
    preorder(r->esq);
    preorder(r->dir);
}

void inorder(no *r) {
    if (r == NULL) return;
    inorder(r->esq);
    printf(" %d", r->val);
    inorder(r->dir);
}

void postorder(no *r) {
    if (r == NULL) return;
    postorder(r->esq);
    postorder(r->dir);
    printf(" %d", r->val);
}

void limpar(no *r) {
    if (r == NULL) return;
    limpar(r->esq);
    limpar(r->dir);
    free(r);
}

int main() {
    int t, n, v;
    int cont = 1;

    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);
        no *raiz = NULL;

        for (int i = 0; i < n; i++) {
            scanf("%d", &v);
            raiz = inserir(raiz, v);
        }

        printf("Case %d:\n", cont);
        printf("Pre.:"); preorder(raiz); printf("\n");
        printf("In..:"); inorder(raiz); printf("\n");
        printf("Post:"); postorder(raiz); printf("\n\n");

        limpar(raiz);
        cont++;
    }

    return 0;
}
