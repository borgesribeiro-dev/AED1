#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int vertice;
    struct no *prox;
} No;

int main() {
    int casos;
    scanf("%d", &casos);

    while (casos--) {
        int inicio, qtd_vertices, qtd_arestas;
        scanf("%d %d %d", &inicio, &qtd_vertices, &qtd_arestas);

        No *grafo[qtd_vertices];
        for (int i = 0; i < qtd_vertices; i++)
            grafo[i] = NULL;

        for (int i = 0; i < qtd_arestas; i++) {
            int origem, destino;
            scanf("%d %d", &origem, &destino);

            No *novo1 = malloc(sizeof(No));
            novo1->vertice = destino;
            novo1->prox = grafo[origem];
            grafo[origem] = novo1;

            No *novo2 = malloc(sizeof(No));
            novo2->vertice = origem;
            novo2->prox = grafo[destino];
            grafo[destino] = novo2;
        }

        int visitado[qtd_vertices];
        for (int i = 0; i < qtd_vertices; i++)
            visitado[i] = 0;

        int pilha[qtd_vertices];
        int topo = 0;

        pilha[topo++] = inicio;
        visitado[inicio] = 1;

        int arestas_utilizadas = 0;

        while (topo > 0) {
            int atual = pilha[--topo];

            for (No *aux = grafo[atual]; aux != NULL; aux = aux->prox) {
                int vizinho = aux->vertice;

                if (!visitado[vizinho]) {
                    visitado[vizinho] = 1;
                    arestas_utilizadas++;
                    pilha[topo++] = vizinho;
                }
            }
        }

        printf("%d\n", arestas_utilizadas * 2);
    }

    return 0;
}
