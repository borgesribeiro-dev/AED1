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
    No *n = (No*) malloc(sizeof(No));
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
    f->ini = f->ini->prox;
    if (f->ini == NULL)
        f->fim = NULL;
    free(t);
    return x;
}

void ord(int v[], int n) {
    int i, j, tmp;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (v[j] > v[i]) {
                tmp = v[i];
                v[i] = v[j];
                v[j] = tmp;
            }
        }
    }
}

int main() {
    int t;
    scanf("%d", &t);

    while (t > 0) {

        int n;
        scanf("%d", &n);

        Fila f;
        init(&f);

        int orig[1000], ordn[1000];
        int i = 0;

        while (i < n) {
            int x;
            scanf("%d", &x);
            add(&f, x);
            i++;
        }

        i = 0;
        while (!vazio(&f)) {
            orig[i] = rmv(&f);
            ordn[i] = orig[i];
            i++;
        }

        ord(ordn, n);

        int ok = 0;
        for (i = 0; i < n; i++) {
            if (orig[i] == ordn[i])
                ok++;
        }

        printf("%d\n", ok);

        t--;
    }

    return 0;
}
