#include <stdio.h>
#include <stdlib.h>

//1180 - Menor e Posição - sem ponteiros e estático.
int main() {

    int n, aux, aux2;

    scanf("%d", &n);

    if((n < 1) || (n > 1000)){
    return 0;
    }

    int nvetor[n];

    for (int i = 0; i < n; i++) {
    scanf("%d", &nvetor[i]);
    }

    aux = nvetor[0];
    aux2 = 0;

    for ( int k = 0; k < n; k++) {

    if(nvetor[k]<aux){
    aux = nvetor[k];
    aux2 = k;
    
    }
    }

    printf("Menor valor: %d\n",aux);
    printf("Posicao: %d\n",aux2);



}
