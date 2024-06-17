#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *v;      
    int N;       
    int inicio; 
    int fim;    
} fila;

int enfileira(fila *f, int x) {
    int novo_fim = (f->fim + 1) % f->N;
    if (novo_fim == f->inicio) {
        return 0;
    }
    f->v[f->fim] = x;
    f->fim = novo_fim;
    return 1;
}

int desenfileira(fila *f, int *y) {
    if (f->inicio == f->fim) {
        return 0;
    }
    *y = f->v[f->inicio];
    f->inicio = (f->inicio + 1) % f->N;
    return 1;
}