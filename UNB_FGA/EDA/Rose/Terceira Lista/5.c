#include <stdlib.h>
#include <stdio.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

celula *enfileira (celula *f, int x){

    celula *Celulas;
    Celulas = malloc (sizeof (celula));
    if(Celulas == NULL){
        return NULL;
    } 

    Celulas->prox = f->prox;
    f->prox = Celulas;
    f->dado = x;

    return Celulas;
}
