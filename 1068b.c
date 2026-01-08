#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char valor;
    struct No *prox;
} No;

typedef struct {
    No *topo;
} Pilha;

void inicializar(Pilha *p) {
    p->topo = NULL;
}

void empilhar(Pilha *p, char c) {
    No *novo = (No*) malloc(sizeof(No));
    novo->valor = c;
    novo->prox = p->topo;
    p->topo = novo;
}

char desempilhar(Pilha *p) {
    if (p->topo == NULL)
        return 0;

    No *aux = p->topo;
    char c = aux->valor;
    p->topo = aux->prox;
    free(aux);
    return c;
}

int pilhaVazia(Pilha *p) {
    return p->topo == NULL;
}

int main() {
    char expressao[1000];

    while (fgets(expressao, 1000, stdin) != NULL) {

        Pilha pilha;
        inicializar(&pilha);

        int valida = 1;
        int tamanho = strlen(expressao);

        for (int i = 0; i < tamanho; i++) {

            if (expressao[i] == '(') {
                empilhar(&pilha, '(');
            }
            else if (expressao[i] == ')') {
                if (pilhaVazia(&pilha)) {
                    valida = 0;
                    break;
                } else {
                    desempilhar(&pilha);
                }
            }
        }

        if (!pilhaVazia(&pilha))
            valida = 0;

        printf("%s\n", valida ? "correct" : "incorrect");

        while (!pilhaVazia(&pilha))
            desempilhar(&pilha);
    }

    return 0;
}
