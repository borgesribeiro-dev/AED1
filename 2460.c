#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int v;
    struct node *l, *r;
} node;

node* add(node* root, int x) {
    if (!root) {
        root = malloc(sizeof(node));
        root->v = x;
        root->l = root->r = NULL;
        return root;
    }
    if (x < root->v) root->l = add(root->l, x);
    else if (x > root->v) root->r = add(root->r, x);
    return root;
}

int find(node* root, int x) {
    while (root) {
        if (x == root->v) return 1;
        if (x < root->v) root = root->l;
        else root = root->r;
    }
    return 0;
}

int main() {
    int n;
    scanf("%d", &n);

    int fila[n];
    for (int i = 0; i < n; i++) scanf("%d", &fila[i]);

    int m;
    scanf("%d", &m);

    node* passouTree = NULL;
    for (int i = 0; i < m; i++) {
        int x;
        scanf("%d", &x);
        passouTree = add(passouTree, x);
    }

    int first = 1;
    for (int i = 0; i < n; i++) {
        if (!find(passouTree, fila[i])) {
            if (!first) printf(" ");
            printf("%d", fila[i]);
            first = 0;
        }
    }
    printf("\n");

    return 0;

}
