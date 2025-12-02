#include <stdio.h>

#define MAX 60

typedef struct {
    int v[MAX];
    int f, b;
} Fila;

void init(Fila *q) {
    q->f = 0;
    q->b = 0;
}

int vazia(Fila *q) {
    return q->f == q->b;
}

int tam(Fila *q) {
    int t = q->b - q->f;
    if (t < 0) t += MAX;
    return t;
}

void push(Fila *q, int x) {
    q->v[q->b] = x;
    q->b = (q->b + 1) % MAX;
}

int pop(Fila *q) {
    int x = q->v[q->f];
    q->f = (q->f + 1) % MAX;
    return x;
}

int main() {
    int n;
    while (scanf("%d", &n) && n != 0) {
        Fila q;
        init(&q);

        for (int i = 1; i <= n; i++) push(&q, i);

        int disc[60], d = 0;

        while (tam(&q) > 1) {
            disc[d++] = pop(&q);
            int x = pop(&q);
            push(&q, x);
        }

        if (d == 0) {
            printf("Discarded cards:\n");
        } else {
            printf("Discarded cards: %d", disc[0]);
            for (int i = 1; i < d; i++) printf(", %d", disc[i]);
            printf("\n");
        }

        printf("Remaining card: %d\n", q.v[q.f]);
    }
    return 0;
}
