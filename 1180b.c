#include <stdio.h>
#include <stdlib.h>


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

    scanf("%d", &n);

    if (n < 1 || n > 1000) return 0;

    
    int *p = (int*) malloc(n * sizeof(int));
    if (p == NULL) return 1;  

    
    for (int i = 0; i < n; i++) {
        scanf("%d", p + i);  
    }

    int menor = Min(p, n, &posicao);

    printf("Menor valor: %d\n", menor);
    printf("Posicao: %d\n", posicao);

    free(p);  
    return 0;
}