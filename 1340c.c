#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

typedef struct {
    int xelemento[MAX_SIZE];
    int top;
    } Pilha;
   
    typedef struct {
    int xelemento1[MAX_SIZE];
    int front, back;
    } fila;

    typedef struct {
    int xelemento2[MAX_SIZE];
    int size;
    } Pfila;

int main() {
    int n, op, x;

    while (scanf("%d", &n) != EOF) { // lê até o fim do arquivo

        Pilha p;
        fila f;
        Pfila pf;

        // inicialização
        p.top = 0;
        f.front = f.back = 0;
        pf.size = 0;

        int ehPilha = 1, ehFila = 1, ehPfila = 1;

        for (int i = 0; i < n; i++) {
            scanf("%d %d", &op, &x);

            if (op == 1) {
                // inserir nas 3 estruturas
                p.xelemento[p.top++] = x;
                f.xelemento1[f.back++] = x;
                pf.xelemento2[pf.size++] = x;
            } 
            else if (op == 2) {
                // PILHA
                if (p.top == 0) ehPilha = 0;
                else if (p.xelemento[p.top - 1] == x) p.top--;
                else ehPilha = 0;

                // FILA
                if (f.front == f.back) ehFila = 0;
                else if (f.xelemento1[f.front] == x) f.front++;
                else ehFila = 0;

                // FILA DE PRIORIDADE (maior sai primeiro)
                if (pf.size == 0) ehPfila = 0;
                else {
                    // encontrar o maior
                    int max = 0;
                    for (int j = 1; j < pf.size; j++) {
                        if (pf.xelemento2[j] > pf.xelemento2[max]) {
                            max = j;
                        }
                    }

                    if (pf.xelemento2[max] == x) {
                        pf.xelemento2[max] = pf.xelemento2[--pf.size];
                    } else {
                        ehPfila = 0;
                    }
                }
            }
        }

        // decidir qual estrutura é válida
        int total = ehPilha + ehFila + ehPfila;

        if (total == 0) printf("impossible\n");
        else if (total > 1) printf("not sure\n");
        else if (ehPilha) printf("stack\n");
        else if (ehFila) printf("queue\n");
        else printf("priority queue\n");
    }

    return 0;
}