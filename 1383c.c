// 1183 - Sudoku (versão dinâmica)

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, cont = 1, erro = 0;
    int *vaux = (int*)calloc(10, sizeof(int)); 
    int **sudoku;

    scanf("%d", &n);
    if (n <= 0) return 0;

    for (int k = 0; k < n; k++) {
        // aloca dinamicamente
        sudoku = (int**)malloc(9 * sizeof(int*));
        for (int i = 0; i < 9; i++) {
            sudoku[i] = (int*)malloc(9 * sizeof(int));
        }

        // recebe sudoku
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                scanf("%d", &sudoku[i][j]);
            }
        }

        // checar valores
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (sudoku[i][j] < 1 || sudoku[i][j] > 9) {
                    erro = 1;
                    break;
                }
            }
        }

        // verifica linhas
        for (int i = 0; i < 9; i++) {
            for (int x = 0; x < 10; x++) vaux[x] = 0;
            for (int j = 0; j < 9; j++) {
                vaux[sudoku[i][j]]++;
                if (vaux[sudoku[i][j]] > 1) erro = 1;
            }
        }

        // verifica colunas
        for (int i = 0; i < 9; i++) {
            for (int x = 0; x < 10; x++) vaux[x] = 0;
            for (int j = 0; j < 9; j++) {
                vaux[sudoku[j][i]]++;
                if (vaux[sudoku[j][i]] > 1) erro = 1;
            }
        }

        // blocos 3x3
        for (int blocolin = 0; blocolin < 9; blocolin += 3) {
            for (int blococol = 0; blococol < 9; blococol += 3) {
                for (int x = 0; x < 10; x++) vaux[x] = 0;
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        vaux[sudoku[blocolin + i][blococol + j]]++;
                        if (vaux[sudoku[blocolin + i][blococol + j]] > 1)
                            erro = 1;
                    }
                }
            }
        }

        // output
        printf("Instancia %d\n", cont);

       if (erro) {
          printf("NAO\n\n");

        } else {
          printf("SIM\n\n");
        }

        erro = 0;
        cont++;

        // libera matriz
        for (int i = 0; i < 9; i++) {

         free(sudoku[i]);

        }

        free(sudoku);
    }

    free(vaux);
    return 0;
}