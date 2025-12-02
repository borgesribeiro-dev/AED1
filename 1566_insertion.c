#include <stdio.h>

void insertion(int v[], int n) {
    for (int i = 1; i < n; i++) {
        int x = v[i], j = i - 1;
        while (j >= 0 && v[j] > x) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = x;
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int v[n];
        for (int i = 0; i < n; i++) scanf("%d", &v[i]);
        insertion(v, n);
        for (int i = 0; i < n; i++) {
            if (i == 0) printf("%d", v[i]);
            else printf(" %d", v[i]);
        }
        printf("\n");
    }
    return 0;
}