#include <stdio.h>

#define MAX 1000

typedef struct {
    int v[MAX];
    int top;
} pilha;

typedef struct {
    int v[MAX];
    int ini, fim;
} fila;

typedef struct {
    int v[MAX];
    int tam;
} fila_prio;

int main() {
    int n, op, x;

    while (scanf("%d", &n) == 1) {

        pilha p;
        fila f;
        fila_prio fp;

        p.top = 0;
        f.ini = f.fim = 0;
        fp.tam = 0;

        int eh_pilha = 1;
        int eh_fila = 1;
        int eh_fp = 1;

        for (int i = 0; i < n; i++) {
            scanf("%d %d", &op, &x);

            if (op == 1) {
                p.v[p.top++] = x;
                f.v[f.fim++] = x;
                fp.v[fp.tam++] = x;
            } else {
                if (p.top == 0 || p.v[p.top - 1] != x)
                    eh_pilha = 0;
                else
                    p.top--;

                if (f.ini == f.fim || f.v[f.ini] != x)
                    eh_fila = 0;
                else
                    f.ini++;

                if (fp.tam == 0) {
                    eh_fp = 0;
                } else {
                    int maior = 0;
                    for (int j = 1; j < fp.tam; j++) {
                        if (fp.v[j] > fp.v[maior])
                            maior = j;
                    }

                    if (fp.v[maior] == x)
                        fp.v[maior] = fp.v[--fp.tam];
                    else
                        eh_fp = 0;
                }
            }
        }

        int qtd = eh_pilha + eh_fila + eh_fp;

        if (qtd == 0) printf("impossible\n");
        else if (qtd > 1) printf("not sure\n");
        else if (eh_pilha) printf("stack\n");
        else if (eh_fila) printf("queue\n");
        else printf("priority queue\n");
    }

    return 0;
}
