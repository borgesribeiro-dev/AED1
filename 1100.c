#include <stdio.h>

#define TAM_TABULEIRO 8

int distancia[TAM_TABULEIRO][TAM_TABULEIRO];
int fila_x[TAM_TABULEIRO * TAM_TABULEIRO];
int fila_y[TAM_TABULEIRO * TAM_TABULEIRO];

int mov_x[8] = { 1,  2,  2,  1, -1, -2, -2, -1 };
int mov_y[8] = { 2,  1, -1, -2, -2, -1,  1,  2 };

int busca_largura(int x_ini, int y_ini, int x_fim, int y_fim) {
    int inicio = 0, fim = 0;

    for (int i = 0; i < TAM_TABULEIRO; i++)
        for (int j = 0; j < TAM_TABULEIRO; j++)
            distancia[i][j] = -1;

    distancia[x_ini][y_ini] = 0;
    fila_x[fim] = x_ini;
    fila_y[fim] = y_ini;
    fim++;

    while (inicio < fim) {
        int x_atual = fila_x[inicio];
        int y_atual = fila_y[inicio];
        inicio++;

        if (x_atual == x_fim && y_atual == y_fim)
            return distancia[x_atual][y_atual];

        for (int k = 0; k < 8; k++) {
            int novo_x = x_atual + mov_x[k];
            int novo_y = y_atual + mov_y[k];

            if (novo_x >= 0 && novo_x < TAM_TABULEIRO &&
                novo_y >= 0 && novo_y < TAM_TABULEIRO) {

                if (distancia[novo_x][novo_y] == -1) {
                    distancia[novo_x][novo_y] =
                        distancia[x_atual][y_atual] + 1;

                    fila_x[fim] = novo_x;
                    fila_y[fim] = novo_y;
                    fim++;
                }
            }
        }
    }

    return -1;
}

int main(void) {
    char origem[3], destino[3];

    while (scanf("%2s %2s", origem, destino) == 2) {
        int x_inicio = origem[0] - 'a';
        int y_inicio = origem[1] - '1';
        int x_destino = destino[0] - 'a';
        int y_destino = destino[1] - '1';

        int movimentos = busca_largura(
            x_inicio, y_inicio, x_destino, y_destino
        );

        printf(
            "To get from %s to %s takes %d knight moves.\n",
            origem, destino, movimentos
        );
    }

    return 0;
}

