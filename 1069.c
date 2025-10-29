#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    char valor;
    struct no *prox;
} No;

typedef struct {
    No *topo;
} Pilha;

void push(Pilha *p, char valor) {
    No *novo = (No*) malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = p->topo;
    p->topo = novo;
}

void pop(Pilha *p) {
    if (p->topo) {
        No *tmp = p->topo;
        p->topo = p->topo->prox;
        free(tmp);
    }
}

int empty(Pilha *p) {
    return p->topo == NULL;
}

void destroi(Pilha *p) {
    while (!empty(p))
        pop(p);
}

int main() {
    int N; 
    char expressao[1001];
    scanf("%d\n", &N);

    for (int k = 0; k < N; ++k) {
        Pilha p = {NULL};
        int diamantes = 0;
        fgets(expressao, 1001, stdin);

        for (int i = 0; expressao[i]; ++i) {
            if (expressao[i] == '<') {
                push(&p, '<');
            } else if (expressao[i] == '>' && !empty(&p)) {
                pop(&p);
                diamantes++;
            }
        }
        printf("%d\n", diamantes);
        destroi(&p);
    }
    return 0;
}
