#include <stdio.h>
#include <stdlib.h>

#define INFINITO 1000000000
#define MAX_CIDADES 1010

int qtd_cidades, qtd_arestas, limite_rota, origem;
int adj[MAX_CIDADES][MAX_CIDADES];
int distancia[MAX_CIDADES];
int fila[MAX_CIDADES];
int inicio_fila, fim_fila;

void inicializar_grafo() {
    for (int i = 0; i < qtd_cidades; i++) {
        distancia[i] = INFINITO;
        for (int j = 0; j < qtd_cidades; j++) {
            adj[i][j] = INFINITO;
        }
    }
}

int dijkstra_simples(int inicio, int destino) {
    inicio_fila = 0;
    fim_fila = 0;

    distancia[inicio] = 0;
    fila[fim_fila++] = inicio;

    while (inicio_fila < fim_fila) {
        int atual = fila[inicio_fila++];

        for (int vizinho = 0; vizinho < qtd_cidades; vizinho++) {
            if (adj[atual][vizinho] != INFINITO &&
                distancia[vizinho] > distancia[atual] + adj[atual][vizinho]) {

                distancia[vizinho] = distancia[atual] + adj[atual][vizinho];
                fila[fim_fila++] = vizinho;
            }
        }
    }

    return distancia[destino];
}

int main() {
    while (1) {
        if (scanf(
                "%d %d %d %d",
                &qtd_cidades,
                &qtd_arestas,
                &limite_rota,
                &origem
            ) != 4)
            return 0;

        if (qtd_cidades == 0 && qtd_arestas == 0 &&
            limite_rota == 0 && origem == 0)
            break;

        inicializar_grafo();

        for (int i = 0; i < qtd_arestas; i++) {
            int a, b, peso;
            scanf("%d %d %d", &a, &b, &peso);

            int a_na_rota = (a < limite_rota);
            int b_na_rota = (b < limite_rota);

            if (!a_na_rota && !b_na_rota) {
                
                if (peso < adj[a][b]) {
                    adj[a][b] = peso;
                    adj[b][a] = peso;
                }
            } else if (!a_na_rota && b_na_rota) {
                
                if (peso < adj[a][b]) {
                    adj[a][b] = peso;
                }
            } else if (a_na_rota && !b_na_rota) {
                
                if (peso < adj[b][a]) {
                    adj[b][a] = peso;
                }
            } else {
                
                if (abs(a - b) == 1 && peso < adj[a][b]) {
                    adj[a][b] = peso;
                    adj[b][a] = peso;
                }
            }
        }

        int menor_custo = dijkstra_simples(origem, limite_rota - 1);
        printf("%d\n", menor_custo);
    }

    return 0;
}

