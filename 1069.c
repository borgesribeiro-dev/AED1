#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    char simbolo;
    struct no *prox;
} No;

typedef struct {
    No *topo;
} Pilha;

void empilhar(Pilha *p, char simbolo) {
    No *novo = (No*) malloc(sizeof(No));
    novo->simbolo = simbolo;
    novo->prox = p->topo;
    p->topo = novo;
}

void desempilhar(Pilha *p) {
    if (p->topo) {
        No *aux = p->topo;
        p->topo = p->topo->prox;
        free(aux);
    }
}

int pilha_vazia(Pilha *p) {
    return p->topo == NULL;
}

void destruir_pilha(Pilha *p) {
    while (!pilha_vazia(p))
        desempilhar(p);
}

int main() {
    int quantidade;
    char expressao[1001];

    scanf("%d\n", &quantidade);

    for (int i = 0; i < quantidade; i++) {
        Pilha pilha = { NULL };
        int total_diamantes = 0;

        fgets(expressao, 1001, stdin);

        for (int j = 0; expressao[j]; j++) {
            if (expressao[j] == '<') {
                empilhar(&pilha, '<');
            } else if (expressao[j] == '>' && !pilha_vazia(&pilha)) {
                desempilhar(&pilha);
                total_diamantes++;
            }
        }

        printf("%d\n", total_diamantes);
        destruir_pilha(&pilha);
    }

    return 0;
}
