#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int v;
    struct no *prox;
} No;

typedef struct {
    No *ini;
    No *fim;
} Fila;

void init(Fila *f) {
    f->ini = NULL;
    f->fim = NULL;
}

void add(Fila *f, int x) {
    No *n = malloc(sizeof(No));
    n->v = x;
    n->prox = NULL;
    if (f->fim == NULL) {
        f->ini = n;
        f->fim = n;
    } else {
        f->fim->prox = n;
        f->fim = n;
    }
}

int vazio(Fila *f) {
    return f->ini == NULL;
}

int rmv(Fila *f) {
    No *t = f->ini;
    int x = t->v;
    f->ini = t->prox;
    if (f->ini == NULL) f->fim = NULL;
    free(t);
    return x;
}

int main() {
    int n, m, x;
    scanf("%d", &n);

    Fila fila;
    init(&fila);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        add(&fila, x);
    }

    scanf("%d", &m);

    Fila rem;
    init(&rem);

    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        add(&rem, x);
    }

    int atual = rmv(&rem);
    int resp[10005], k = 0;

    while (!vazio(&fila)) {
        int u = rmv(&fila);
        if (u == atual) {
            if (!vazio(&rem)) atual = rmv(&rem);
        } else {
            resp[k++] = u;
        }
    }

    for (int i = 0; i < k; i++) {
        if (i) printf(" ");
        printf("%d", resp[i]);
    }
    printf("\n");

    return 0;
}
