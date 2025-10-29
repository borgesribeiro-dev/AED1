#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data;
    struct Node *next;
} Node;

typedef struct {
    Node *top;
} Pilha;

void init(Pilha *p) {
    p->top = NULL;
}

void push(Pilha *p, char c) {
    Node *novo = (Node*)malloc(sizeof(Node));
    novo->data = c;
    novo->next = p->top;
    p->top = novo;
}

char pop(Pilha *p) {
    if (!p->top) return 0;
    Node *aux = p->top;
    char c = aux->data;
    p->top = aux->next;
    free(aux);
    return c;
}

int isEmpty(Pilha *p) {
    return p->top == NULL;
}

int main() {
    char expr[1000];
    while (fgets(expr, 1000, stdin) != NULL) {
        Pilha s;
        init(&s);
        int correct = 1;
        int len = strlen(expr);

        for (int i = 0; i < len; i++) {
            if (expr[i] == '(') push(&s, '(');
            else if (expr[i] == ')') {
                if (isEmpty(&s)) {
                    correct = 0;
                    break;
                } else pop(&s);
            }
        }

        if (!isEmpty(&s)) correct = 0;
        printf("%s\n", correct ? "correct" : "incorrect");

        // liberar a pilha restante
        while (!isEmpty(&s)) pop(&s);
    }
    return 0;
}
