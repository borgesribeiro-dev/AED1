#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int v;
    struct no *p;
} no;

int main(){
    int t, ini, n, a, x, y, i;
    scanf("%d", &t);

    while(t--){
        scanf("%d %d %d", &ini, &n, &a);

        no *g[n];
        for(i=0;i<n;i++) g[i] = NULL;

        for(i=0;i<a;i++){
            scanf("%d %d", &x, &y);
            no *u = malloc(sizeof(no));
            u->v = y; u->p = g[x]; g[x] = u;
            no *w = malloc(sizeof(no));
            w->v = x; w->p = g[y]; g[y] = w;
        }

        int vis[n];
        for(i=0;i<n;i++) vis[i] = 0;

        int pilha[n], topo = 0;
        pilha[topo++] = ini;
        vis[ini] = 1;

        int contA = 0;

        while(topo){
            int u = pilha[--topo];
            for(no *aux = g[u]; aux; aux = aux->p){
                int v = aux->v;
                if(!vis[v]){
                    vis[v] = 1;
                    contA++;
                    pilha[topo++] = v;
                }
            }
        }

        printf("%d\n", contA * 2);
    }
    return 0;
}
