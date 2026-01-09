#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int vertice;
    struct no *prox;
} No;

void adicionar_aresta(No **grafo, int origem, int destino) {
    No *novo = malloc(sizeof(No));
    novo->vertice = destino;
    novo->prox = grafo[origem];
    grafo[origem] = novo;
}

void busca_profundidade(int atual, No **grafo, int *visitado, int *componente, int *tam){
    visitado[atual] = 1;
    componente[(*tam)++] = atual;

    for (No *aux = grafo[atual]; aux != NULL; aux = aux->prox) {
        if (!visitado[aux->vertice]) {
            busca_profundidade(
                aux->vertice,
                grafo,
                visitado,
                componente,
                tam
            );
        }
    }
}

int comparar_inteiros(const void *a, const void *b) {
    int x = *(const int*)a;
    int y = *(const int*)b;
    return x - y;
}

int main() {
    int casos;

    if (scanf("%d", &casos) != 1)
        return 0;

    for (int indice_caso = 1; indice_caso <= casos; indice_caso++) {
        int qtd_vertices, qtd_arestas;
        scanf("%d %d", &qtd_vertices, &qtd_arestas);

        No **grafo = calloc(qtd_vertices, sizeof(No*));
        int *visitado = calloc(qtd_vertices, sizeof(int));

        for (int i = 0; i < qtd_arestas; i++) {
            char a, b;
            scanf(" %c %c", &a, &b);

            int u = a - 'a';
            int v = b - 'a';

            adicionar_aresta(grafo, u, v);
            adicionar_aresta(grafo, v, u);
        }

        printf("Case #%d:\n", indice_caso);

        int total_componentes = 0;

        for (int i = 0; i < qtd_vertices; i++) {
            if (!visitado[i]) {
                int *componente = malloc(qtd_vertices * sizeof(int));
                int tamanho = 0;

                busca_profundidade(
                    i,
                    grafo,
                    visitado,
                    componente,
                    &tamanho
                );

                qsort(
                    componente,
                    tamanho,
                    sizeof(int),
                    comparar_inteiros
                );

                for (int j = 0; j < tamanho; j++) {
                    printf("%c,", (char)(componente[j] + 'a'));
                }
                printf("\n");

                total_componentes++;
                free(componente);
            }
        }

        printf("%d connected components\n\n", total_componentes);

        for (int i = 0; i < qtd_vertices; i++) {
            No *aux = grafo[i];
            while (aux) {
                No *tmp = aux;
                aux = aux->prox;
                free(tmp);
            }
        }

        free(grafo);
        free(visitado);
    }

    return 0;
}