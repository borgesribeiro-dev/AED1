#include <stdio.h>

void merge(int v[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int a[n1], b[n2];

    for (int i = 0; i < n1; i++) a[i] = v[l + i];
    for (int i = 0; i < n2; i++) b[i] = v[m + 1 + i];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (a[i] <= b[j]) v[k++] = a[i++];
        else v[k++] = b[j++];
    }

    while (i < n1) v[k++] = a[i++];
    while (j < n2) v[k++] = b[j++];
}

void mergesort(int v[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergesort(v, l, m);
        mergesort(v, m + 1, r);
        merge(v, l, m, r);
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

        mergesort(v, 0, n - 1);

        for (int i = 0; i < n; i++) {
            if (i == 0) printf("%d", v[i]);
            else printf(" %d", v[i]);
        }
        printf("\n");
    }
    return 0;
}
