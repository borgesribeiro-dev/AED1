#include <stdio.h>

#define MAX_VERTICES 20

int qtd_vertices, qtd_arestas;
int matriz_adj[MAX_VERTICES][MAX_VERTICES];
int visitado[MAX_VERTICES];

int busca_profundidade(int atual, int nivel) {
    int possui_aresta = 0;
    visitado[atual] = 1;

    for (int vizinho = 0; vizinho < qtd_vertices; vizinho++) {
        if (matriz_adj[atual][vizinho]) {
            possui_aresta = 1;

            for (int i = 0; i < nivel; i++)
                putchar(' ');

            if (!visitado[vizinho]) {
                printf("%d-%d pathR(G,%d)\n", atual, vizinho, vizinho);
                busca_profundidade(vizinho, nivel + 2);
            } else {
                printf("%d-%d\n", atual, vizinho);
            }
        }
    }

    return possui_aresta;
}

int main(void) {
    int casos;

    if (scanf("%d", &casos) != 1)
        return 0;

    for (int indice_caso = 1; indice_caso <= casos; indice_caso++) {
        scanf("%d %d", &qtd_vertices, &qtd_arestas);

        for (int i = 0; i < qtd_vertices; i++) {
            visitado[i] = 0;
            for (int j = 0; j < qtd_vertices; j++)
                matriz_adj[i][j] = 0;
        }

        for (int i = 0; i < qtd_arestas; i++) {
            int origem, destino;
            scanf("%d %d", &origem, &destino);

            if (origem >= 0 && origem < qtd_vertices &&
                destino >= 0 && destino < qtd_vertices) {
                matriz_adj[origem][destino] = 1;
            }
        }

        printf("Caso %d:\n", indice_caso);

        for (int vertice = 0; vertice < qtd_vertices; vertice++) {
            if (!visitado[vertice]) {
                int imprimiu = busca_profundidade(vertice, 2);
                if (imprimiu)
                    printf("\n");
            }
        }
    }

    return 0;
}
