//1183 - Sudoku

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, cont = 1, erro = 0;
    int sudoku[9][9], vaux[10] = {0};

    scanf("%d", &n);

    if (n <= 0) {
        return 0;
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                scanf("%d", &sudoku[i][j]);
            }
        }

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (sudoku[i][j] < 1 || sudoku[i][j] > 9) {
                    erro = 1;
                    break;
                }
            }
        }

        // lin.
        for (int i = 0; i < 9; i++) {
            for (int x = 0; x < 10; x++) vaux[x] = 0;
            for (int j = 0; j < 9; j++) {
                vaux[sudoku[i][j]]++;
                if (vaux[sudoku[i][j]] > 1) {
                    erro = 1;
                    break;
                }
            }
        }

        // col.
        for (int i = 0; i < 9; i++) {
            for (int x = 0; x < 10; x++) vaux[x] = 0;
            for (int j = 0; j < 9; j++) {
                vaux[sudoku[j][i]]++;
                if (vaux[sudoku[j][i]] > 1) {
                    erro = 1;
                    break;
                }
            }
        }

        // blocos 3x3
        for (int blocolin = 0; blocolin < 9; blocolin += 3) {
            for (int blococol = 0; blococol < 9; blococol += 3) {
                for (int x = 0; x < 10; x++) vaux[x] = 0;
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        vaux[sudoku[blocolin + i][blococol + j]]++;
                        if (vaux[sudoku[blocolin + i][blococol + j]] > 1) {
                            erro = 1;
                            break;
                        }
                    }
                }
            }
        }
        if (erro == 1) {
            printf("Instancia %d\n", cont);
            printf("NAO\n");
            erro = 0;
        } else {
            printf("Instancia %d\n", cont);
            printf("SIM\n");
        }
        cont++;
    }
}