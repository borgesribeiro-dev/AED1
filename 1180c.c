#include <stdio.h>


int Min(int *v, int n, int *posicao) {
    if (n == 1) {
        *posicao = 0;
        return *v;  
    } else {
        int posAnterior;
        int menorAnterior = Min(v, n - 1, &posAnterior);

        if (*(v + n - 1) < menorAnterior) {
            *posicao = n - 1;
            return *(v + n - 1);
        } else {
            *posicao = posAnterior;
            return menorAnterior;
        }
    }
}

int main() {
    int n, posicao;
    int vetor[1000];     
    int *p = vetor;      

    scanf("%d", &n);
    if (n < 1 || n > 1000) return 0;

    
    for (int i = 0; i < n; i++) {
        scanf("%d", p + i);  
    }

    int menor = Min(p, n, &posicao);

    printf("Menor valor: %d\n", menor);
    printf("Posicao: %d\n", posicao);

    return 0;
}

