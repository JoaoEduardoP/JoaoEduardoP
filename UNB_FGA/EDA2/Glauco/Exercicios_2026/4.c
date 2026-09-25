#include <stdio.h>
#include <stdlib.h>

typedef struct No{

    int vertice;
    struct No *prox;

} No;

typedef struct Grafo{   

    int v;
    No **lista;

} Grafo;

Grafo* CriaGrafo(int v){ 

    Grafo *g = (Grafo*) malloc(sizeof(Grafo));

    g->lista = (No**) malloc( v * sizeof(No*));

    g->v = v;

    for(int i = 0; i < v; i++){
        g->lista[i] = NULL;
    }

    return g;
}

void InsereAresta(Grafo *g, int verGrafo, int vertice){

    No *novo = (No*) malloc(sizeof(No));

    novo->vertice = vertice;

    novo->prox = g->lista[verGrafo];

    g->lista[verGrafo] = novo;
}

void LiberaMemoria(Grafo *g, int *visitados){

    for (int i = 0; i < g->v; i++){

        No *n = g->lista[i];
        
        while ( n != NULL){
            No *prox = n->prox;
            free(n);
            n = prox;
        }

    }

    free(g->lista);
    free(g);
    free(visitados);
}

int BuscaCaminho(Grafo *g, int x, int y, int *visitado){

    if (x == y){
        return 1;
    }

    visitado[x] = 1;

    No *Busca = g->lista[x];

    while ( Busca != NULL){
        if(!visitado[Busca->vertice] && BuscaCaminho( g, Busca->vertice, y, visitado)){
            return 1;
        }

        Busca = Busca->prox;
    }
    
    return 0;

}

int main() {

    int V, A, v, a, x, y;
    
    scanf("%d %d", &V, &A);

    Grafo *grafo = CriaGrafo(V+1);

    int *visitado = (int*) calloc(V, sizeof(int));

    for(int i = 0; i < A; i++){
        scanf("%d %d", &v, &a);

        InsereAresta(grafo,v,a);
        InsereAresta(grafo,a,v);
    }

    int lidos = scanf("%d %d", &x, &y);

    if ( lidos != 2 || BuscaCaminho(grafo, x, y, visitado)){
        printf("SIM");
    }
    else{
        printf("NAO");
    }
    
    LiberaMemoria(grafo, visitado);
    
    return 0;
}