#include <stdio.h>
#include <stdlib.h>

typedef struct pilha {
    int *dados;
    int N, topo;
} pilha;

int empilha(pilha *p, int x) {
    if (p->topo == p->N) {
        int novo_tamanho = p->N * 2;
        int *novo_dados = (int *)realloc(p->dados, novo_tamanho * sizeof(int));
        if (novo_dados == NULL) {
            return 0;
        }
        p->dados = novo_dados;
        p->N = novo_tamanho;
    }
    p->dados[p->topo++] = x;
    return 1;
}