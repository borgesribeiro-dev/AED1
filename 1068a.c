#include <stdio.h>
#include <string.h>

#define MAX 1000

typedef struct {
    char dados[MAX];
    int topo;
} Pilha;

void inicializar(Pilha *p) {
    p->topo = 0;
}

void empilhar(Pilha *p, char c) {
    if (p->topo < MAX)
        p->dados[p->topo++] = c;
}

char desempilhar(Pilha *p) {
    if (p->topo == 0)
        return 0;
    return p->dados[--p->topo];
}

int pilhaVazia(Pilha *p) {
    return p->topo == 0;
}

int main() {
    char expressao[MAX];

    while (fgets(expressao, MAX, stdin) != NULL) {

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

            if (valida) printf("correct\n");
            else printf("incorrect\n");
    }

    return 0;
}
