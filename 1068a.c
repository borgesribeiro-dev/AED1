#include <stdio.h>
#include <string.h>

#define MAX 1000

typedef struct {
    char data[MAX];
    int top;
} Pilha;

void init(Pilha *p) {
    p->top = 0;
}

void push(Pilha *p, char c) {
    if (p->top < MAX) p->data[p->top++] = c;
}

char pop(Pilha *p) {
    if (p->top == 0) return 0;
    return p->data[--p->top];
}

int isEmpty(Pilha *p) {
    return p->top == 0;
}

int main() {
    char expr[MAX];
    while (fgets(expr, MAX, stdin) != NULL) {
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
    }
    return 0;
}