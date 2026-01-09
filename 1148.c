#include <stdio.h>
#include <stdlib.h>

#define INFINITO 1000000000

typedef struct no {
    int vertice;
    int peso;
    struct no *prox;
} No;

typedef struct {
    int vertice;
    int distancia;
} ItemHeap;

int qtd_vertices, qtd_arestas;
No *grafo[5005];

int distancia[5005];
int posicao[5005];

ItemHeap heap[20000];
int tamanho_heap;

void adicionar_aresta(int origem, int destino, int peso) {
    No *novo = malloc(sizeof(No));
    novo->vertice = destino;
    novo->peso = peso;
    novo->prox = grafo[origem];
    grafo[origem] = novo;
}

void trocar(int i, int j) {
    ItemHeap tmp = heap[i];
    heap[i] = heap[j];
    heap[j] = tmp;

    posicao[heap[i].vertice] = i;
    posicao[heap[j].vertice] = j;
}

void subir(int i) {
    while (i > 1) {
        int pai = i / 2;
        if (heap[pai].distancia <= heap[i].distancia)
            break;
        trocar(pai, i);
        i = pai;
    }
}

void descer(int i) {
    while (1) {
        int esq = 2 * i;
        int dir = esq + 1;
        int menor = i;

        if (esq <= tamanho_heap &&
            heap[esq].distancia < heap[menor].distancia)
            menor = esq;

        if (dir <= tamanho_heap &&
            heap[dir].distancia < heap[menor].distancia)
            menor = dir;

        if (menor == i)
            break;

        trocar(menor, i);
        i = menor;
    }
}

void inserir_heap(int vertice, int dist) {
    tamanho_heap++;
    heap[tamanho_heap].vertice = vertice;
    heap[tamanho_heap].distancia = dist;
    posicao[vertice] = tamanho_heap;
    subir(tamanho_heap);
}

ItemHeap remover_minimo() {
    ItemHeap minimo = heap[1];
    heap[1] = heap[tamanho_heap];
    posicao[heap[1].vertice] = 1;
    tamanho_heap--;
    descer(1);
    return minimo;
}

void dijkstra(int origem) {
    for (int i = 1; i <= qtd_vertices; i++) {
        distancia[i] = INFINITO;
        posicao[i] = 0;
    }

    distancia[origem] = 0;
    tamanho_heap = 0;
    inserir_heap(origem, 0);

    while (tamanho_heap > 0) {
        ItemHeap atual = remover_minimo();
        int u = atual.vertice;

        if (atual.distancia > distancia[u])
            continue;

        for (No *aux = grafo[u]; aux; aux = aux->prox) {
            int v = aux->vertice;
            int nova_dist = distancia[u] + aux->peso;

            if (nova_dist < distancia[v]) {
                distancia[v] = nova_dist;

                if (posicao[v] == 0) {
                    inserir_heap(v, nova_dist);
                } else {
                    heap[posicao[v]].distancia = nova_dist;
                    subir(posicao[v]);
                }
            }
        }
    }
}

int main() {
    while (1) {
        scanf("%d %d", &qtd_vertices, &qtd_arestas);
        if (qtd_vertices == 0 && qtd_arestas == 0)
            break;

        for (int i = 1; i <= qtd_vertices; i++)
            grafo[i] = NULL;

        for (int i = 0; i < qtd_arestas; i++) {
            int a, b, peso;
            scanf("%d %d %d", &a, &b, &peso);

            int reciproco = 0;
            for (No *p = grafo[b]; p; p = p->prox) {
                if (p->vertice == a) {
                    reciproco = 1;
                    break;
                }
            }

            if (reciproco) {
                adicionar_aresta(a, b, 0);
                adicionar_aresta(b, a, 0);
            } else {
                adicionar_aresta(a, b, peso);
            }
        }

        int consultas;
        scanf("%d", &consultas);

        while (consultas--) {
            int origem, destino;
            scanf("%d %d", &origem, &destino);

            dijkstra(origem);

            if (distancia[destino] == INFINITO)
                printf("Nao e possivel entregar a carta\n");
            else
                printf("%d\n", distancia[destino]);
        }

        printf("\n");
    }

    return 0;
}
