#include <stdio.h>

void troca(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int part(int v[], int l, int r) {
    int p = v[r];
    int i = l - 1;

    for (int j = l; j < r; j++) {
        if (v[j] <= p) {
            i++;
            troca(&v[i], &v[j]);
        }
    }
    troca(&v[i + 1], &v[r]);
    return i + 1;
}

void quick(int v[], int n) {
    int stack[n];
    int top = -1;

    stack[++top] = 0;
    stack[++top] = n - 1;

    while (top >= 0) {
        int r = stack[top--];
        int l = stack[top--];

        int p = part(v, l, r);

        if (p - 1 > l) {
            stack[++top] = l;
            stack[++top] = p - 1;
        }
        if (p + 1 < r) {
            stack[++top] = p + 1;
            stack[++top] = r;
        }
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

        quick(v, n);

        for (int i = 0; i < n; i++) {
            if (i == 0) printf("%d", v[i]);
            else printf(" %d", v[i]);
        }
        printf("\n");
    }
    return 0;
}
