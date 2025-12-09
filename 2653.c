// 2653 / Dijkstra 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 1000005
#define MOD 100003  

typedef struct cel {
    char *str;
    struct cel *prox;
} Cel;

Cel *hash_tab[MOD];

unsigned long long calc_hash(const char *s) {
    unsigned long long h = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        h = h * 131 + (unsigned long long)(unsigned char)s[i];
    }
    return h;
}

int existe_ou_insere(const char *s) {
    unsigned long long h = calc_hash(s);
    int idx = (int)(h % MOD);

    Cel *p = hash_tab[idx];
    while (p != NULL) {
        if (strcmp(p->str, s) == 0) {
            return 0; 
        }
        p = p->prox;
    }

    
    Cel *novo = (Cel*)malloc(sizeof(Cel));
    int len = (int)strlen(s);
    novo->str = (char*)malloc((len + 1) * sizeof(char));
    strcpy(novo->str, s);
    novo->prox = hash_tab[idx];
    hash_tab[idx] = novo;

    return 1; 
}

int main() {
    char buf[MAXLEN];
    int tipos = 0;

    
    for (int i = 0; i < MOD; i++) hash_tab[i] = NULL;

   
    while (fgets(buf, sizeof(buf), stdin) != NULL) {
        
        int len = (int)strlen(buf);
        if (len > 0 && buf[len - 1] == '\n') {
            buf[len - 1] = '\0';
        }

        if (buf[0] == '\0') continue; 
        if (existe_ou_insere(buf)) {
            tipos++;
        }
    }

    printf("%d\n", tipos);

    
    return 0;
}
