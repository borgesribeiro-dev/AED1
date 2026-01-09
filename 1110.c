#include <stdio.h>

#define MAX_CARTAS 60

typedef struct {
    int dados[MAX_CARTAS];
    int inicio, fim;
} Fila;

void inicializar_fila(Fila *f) {
    f->inicio = 0;
    f->fim = 0;
}

int fila_vazia(Fila *f) {
    return f->inicio == f->fim;
}

int tamanho_fila(Fila *f) {
    int tamanho = f->fim - f->inicio;
    if (tamanho < 0)
        tamanho += MAX_CARTAS;
    return tamanho;
}

void enfileirar(Fila *f, int valor) {
    f->dados[f->fim] = valor;
    f->fim = (f->fim + 1) % MAX_CARTAS;
}

int desenfileirar(Fila *f) {
    int valor = f->dados[f->inicio];
    f->inicio = (f->inicio + 1) % MAX_CARTAS;
    return valor;
}

int main() {
    int quantidade;

    while (scanf("%d", &quantidade) && quantidade != 0) {
        Fila fila;
        inicializar_fila(&fila);

        for (int i = 1; i <= quantidade; i++)
            enfileirar(&fila, i);

        int descartadas[MAX_CARTAS];
        int qtd_descartadas = 0;

        while (tamanho_fila(&fila) > 1) {
            descartadas[qtd_descartadas++] = desenfileirar(&fila);
            int topo = desenfileirar(&fila);
            enfileirar(&fila, topo);
        }

        if (qtd_descartadas == 0) {
            printf("Discarded cards:\n");
        } else {
            printf("Discarded cards: %d", descartadas[0]);
            for (int i = 1; i < qtd_descartadas; i++)
                printf(", %d", descartadas[i]);
            printf("\n");
        }

        printf("Remaining card: %d\n", fila.dados[fila.inicio]);
    }

    return 0;
}

