#include <stdio.h>

#define N 8

int dist[N][N];
int qx[N * N], qy[N * N];

int dx[8] = { 1,  2,  2,  1, -1, -2, -2, -1};
int dy[8] = { 2,  1, -1, -2, -2, -1,  1,  2};

int bfs(int sx, int sy, int tx, int ty) {
    int ini = 0, fim = 0;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            dist[i][j] = -1;

    dist[sx][sy] = 0;
    qx[fim] = sx;
    qy[fim] = sy;
    fim++;

    while (ini < fim) {
        int x = qx[ini];
        int y = qy[ini];
        ini++;

        if (x == tx && y == ty)
            return dist[x][y];

        for (int k = 0; k < 8; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                if (dist[nx][ny] == -1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    qx[fim] = nx;
                    qy[fim] = ny;
                    fim++;
                }
            }
        }
    }

    return -1;
}

int main(void) {
    char a[3], b[3];

    while (scanf("%2s %2s", a, b) == 2) {
        int sx = a[0] - 'a';
        int sy = a[1] - '1';
        int tx = b[0] - 'a';
        int ty = b[1] - '1';

        int moves = bfs(sx, sy, tx, ty);

        printf("To get from %s to %s takes %d knight moves.\n", a, b, moves);
    }

    return 0;
}
