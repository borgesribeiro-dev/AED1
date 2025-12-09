#include <stdio.h>
#include <stdlib.h>

#define INF 1000000000

typedef struct {
    int v, w;
    struct Node *next;
} Node;

typedef struct {
    int u, dist;
} Par;

int n, m;
Node *g[5005];
int dist[5005];
int pos[5005];
Par heap[20000];
int hsz;

void add(int u, int v, int w){
    Node *p = malloc(sizeof(Node));
    p->v = v; p->w = w; p->next = g[u];
    g[u] = p;
}

void swap(int i, int j){
    Par t = heap[i];
    heap[i] = heap[j];
    heap[j] = t;
    pos[heap[i].u] = i;
    pos[heap[j].u] = j;
}

void sobe(int i){
    while(i > 1){
        int p = i/2;
        if(heap[p].dist <= heap[i].dist) break;
        swap(p, i);
        i = p;
    }
}

void desce(int i){
    while(1){
        int e = 2*i, d = e+1, menor = i;
        if(e <= hsz && heap[e].dist < heap[menor].dist) menor = e;
        if(d <= hsz && heap[d].dist < heap[menor].dist) menor = d;
        if(menor == i) break;
        swap(menor, i);
        i = menor;
    }
}

void push(int u, int d){
    ++hsz;
    heap[hsz].u = u;
    heap[hsz].dist = d;
    pos[u] = hsz;
    sobe(hsz);
}

Par pop(){
    Par r = heap[1];
    heap[1] = heap[hsz];
    pos[heap[1].u] = 1;
    hsz--;
    desce(1);
    return r;
}

void relaxa(int s){
    for(int i=1; i<=n; i++){
        dist[i] = INF;
        pos[i] = 0;
    }
    dist[s] = 0;

    hsz = 0;
    push(s, 0);

    while(hsz){
        Par p = pop();
        int u = p.u;
        if(p.dist > dist[u]) continue;

        for(Node *k = g[u]; k; k = k->next){
            int v = k->v;
            int nd = dist[u] + k->w;

            if(nd < dist[v]){
                dist[v] = nd;
                if(pos[v] == 0){
                    push(v, nd);
                } else {
                    heap[pos[v]].dist = nd;
                    sobe(pos[v]);
                }
            }
        }
    }
}

int main(){
    while(1){
        scanf("%d %d", &n, &m);
        if(n == 0 && m == 0) break;

        for(int i=1; i<=n; i++)
            g[i] = NULL;

        for(int i=0; i<m; i++){
            int x, y, h;
            scanf("%d %d %d", &x, &y, &h);

            // Verifica reciprocidade (estradas de ida e volta = custo zero)
            Node *p = g[y];
            int bidi = 0;
            while(p){
                if(p->v == x){ bidi = 1; break; }
                p = p->next;
            }

            if(bidi){
                add(x, y, 0);
                add(y, x, 0);
            } else {
                add(x, y, h);
            }
        }

        int q;
        scanf("%d", &q);

        while(q--){
            int a, b;
            scanf("%d %d", &a, &b);

            relaxa(a);

            if(dist[b] == INF) printf("Nao e possivel entregar a carta\n");
            else printf("%d\n", dist[b]);
        }

        printf("\n");
    }

    return 0;
}
