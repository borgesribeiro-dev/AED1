#include <stdio.h>

void heapify(int v[], int n, int i) {
    int maior = i;
    int esq = 2 * i + 1;
    int dir = 2 * i + 2;

    if (esq < n && v[esq] > v[maior]) maior = esq;
    if (dir < n && v[dir] > v[maior]) maior = dir;

    if (maior != i) {
        int t = v[i];
        v[i] = v[maior];
        v[maior] = t;
        heapify(v, n, maior);
    }
}

void heapsort(int v[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(v, n, i);

    for (int i = n - 1; i > 0; i--) {
        int t = v[0];
        v[0] = v[i];
        v[i] = t;
        heapify(v, i, 0);
    }
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);

        if (n == 0) {
            printf("\n");
            continue;
        }

        int v[n];
        for (int i = 0; i < n; i++) scanf("%d", &v[i]);

        heapsort(v, n);

        for (int i = 0; i < n; i++) {
            if (i == 0) printf("%d", v[i]);
            else printf(" %d", v[i]);
        }
        printf("\n");
    }

    return 0;
}
