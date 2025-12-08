#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int v;
    struct no *prox;
} No;

typedef struct {
    No *topo;
} Pilha;

void init(Pilha *p) {
    p->topo = NULL;
}

void push(Pilha *p, int x) {
    No *n = (No*) malloc(sizeof(No));
    n->v = x;
    n->prox = p->topo;
    p->topo = n;
}

int vazio(Pilha *p) {
    return p->topo == NULL;
}

int topo(Pilha *p) {
    return p->topo->v;
}

void pop(Pilha *p) {
    No *t = p->topo;
    p->topo = p->topo->prox;
    free(t);
}

void limpar(Pilha *p) {
    while (!vazio(p))
        pop(p);
}

int main() {
    int n;
    scanf("%d", &n);

    while (n != 0) {

        int x;
        scanf("%d", &x);

        while (x != 0) {

            int seq[1000];
            seq[0] = x;

            for (int i = 1; i < n; i++)
                scanf("%d", &seq[i]);

            Pilha p;
            init(&p);

            int atual = 1;
            int ok = 1;

            for (int i = 0; i < n && ok; i++) {

                int desejado = seq[i];

                while (atual <= desejado) {
                    push(&p, atual);
                    atual++;
                }

                if (!vazio(&p) && topo(&p) == desejado)
                    pop(&p);
                else
                    ok = 0;
            }

            if (ok) printf("Yes\n");
            else    printf("No\n");

            limpar(&p);
            scanf("%d", &x);
        }

        printf("\n");
        scanf("%d", &n);
    }

    return 0;
}
