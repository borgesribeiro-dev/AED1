#include <stdio.h>

void selection(int v[], int n) {

    for (int i = 0; i < n - 1; i++) {
        int m = i;
        for (int j = i + 1; j < n; j++)
            if (v[j] < v[m]) m = j;
        int t = v[i];
        v[i] = v[m];
        v[m] = t;
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

        selection(v, n);

        for (int i = 0; i < n; i++) {
            if (i == 0) printf("%d", v[i]);
            else printf(" %d", v[i]);
        }
        printf("\n");
    }
    return 0;
}
