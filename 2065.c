// 2065 - Fila do Supermercado 

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    long long tempo;
    int indice;
} Caixa;

void trocar(Caixa *a, Caixa *b) {
    Caixa temp = *a;
    *a = *b;
    *b = temp;
}

void subir_heap(Caixa heap[], int pos) {
    while (pos > 0) {
        int pai = (pos - 1) / 2;
        if (heap[pos].tempo < heap[pai].tempo || 
           (heap[pos].tempo == heap[pai].tempo && heap[pos].indice < heap[pai].indice)) {
            trocar(&heap[pos], &heap[pai]);
            pos = pai;
        } else break;
    }
}

void descer_heap(Caixa heap[], int tam, int pos) {
    while (1) {
        int filho_esq = 2 * pos + 1;
        int filho_dir = 2 * pos + 2;
        int menor = pos;

        if (filho_esq < tam && 
            (heap[filho_esq].tempo < heap[menor].tempo || 
            (heap[filho_esq].tempo == heap[menor].tempo && heap[filho_esq].indice < heap[menor].indice)))
            menor = filho_esq;

        if (filho_dir < tam && 
            (heap[filho_dir].tempo < heap[menor].tempo || 
            (heap[filho_dir].tempo == heap[menor].tempo && heap[filho_dir].indice < heap[menor].indice)))
            menor = filho_dir;

        if (menor != pos) {
            trocar(&heap[pos], &heap[menor]);
            pos = menor;
        } else break;
    }
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    long long v[N];
    for (int i = 0; i < N; i++)
        scanf("%lld", &v[i]);

    long long c[M];
    for (int i = 0; i < M; i++)
        scanf("%lld", &c[i]);

    Caixa heap[N];
    for (int i = 0; i < N; i++) {
        heap[i].tempo = 0;
        heap[i].indice = i;
    }
    int tam_heap = N;
    long long ultimo = 0;

    for (int i = 0; i < M; i++) {
        Caixa caixa = heap[0];
        caixa.tempo += v[caixa.indice] * c[i];
        if (caixa.tempo > ultimo)
            ultimo = caixa.tempo;
        heap[0] = caixa;
        descer_heap(heap, tam_heap, 0);
    }

    printf("%lld\n", ultimo);
    return 0;
}
