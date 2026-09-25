#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int v;
    struct no *prox;
} no;

typedef struct grafoLista{
    int v;
    struct no **Lista;
} grafoLista;

typedef struct grafoMatriz{
    int v;
    int **matriz;
} grafoMatriz;


grafoLista CriaGrafoLista(int n){
    grafoLista *g = malloc(sizeof(grafoLista));
    g->v = n;
    g->Lista = malloc(n * sizeof(no*));

    for (int i = 0; i < n; i++){
        g->Lista[i] = NULL;
    }
    
    return *g;
}

grafoMatriz CriaGrafoMatriz(int n){
    
    grafoMatriz *g = malloc(sizeof(grafoMatriz));
    g->v = n;
    g->matriz = malloc(n * sizeof(int*));

    for(int i = 0; i < n; i++){
        g->matriz[i] = malloc(n * sizeof(int*));

        for(int j = 0; j < n; j++){
            g->matriz[i][j] = 0;
        }

    }

    return *g;
}

void inserirArestaMatriz(grafoMatriz *g, int v, int u){

    g->matriz[v][u] = 1;
    g->matriz[u][v] = 1;
}

void removeArestaMatriz(grafoMatriz *g, int v, int u){

    g->matriz[v][u] = 0;
    g->matriz[u][v] = 0;
}

void inserirArestaLista(grafoLista *g, int v, int u){

    no *novo = malloc(sizeof(no));

    novo->v = u;
    novo->prox = g->Lista[v];
    g->Lista[v] = novo;

    no *novo2 = malloc(sizeof(no));

    novo2->v = v;
    novo2->prox = g->Lista[u];
    g->Lista[u]= novo2;
}

void removeArestaLista(grafoLista *g, int v, int u){

    no *ant = NULL;
    no *p = g->Lista[v];

    while(p && p->v !=u){
        ant = p;
        p = p->prox;
    }
    
    if (p){
        if (ant == NULL){
            g->Lista[v] = p->prox;
        }
        else{
            ant->prox = p->prox;
        }

        free(p);
    }
}

void imprimirMatriz(grafoMatriz *g){
    for(int i = 0; i < g->v; i++){
            printf("%d: ", i);
        for (int j = 0; j < g->v; j++){
            printf("%d",g->matriz[i][j]);
        }
        printf("\n");
    }
}

void imprimirLista(grafoLista *g){
    for(int i = 0; i < g->v; i++){
        printf("%d: ", i);

        no *p = g->Lista[i];

        while (p != NULL){
            printf("%d", p->v);
            p = p->prox;
        }
        printf("\n");
    }
}

int existeArestaMatriz(grafoLista *g, int v, int u){
    int existe = 0;
    no *p = NULL;

    p = g->Lista[v];

    while(p != NULL){
        if (p->v == u){
            existe = 1;
            break;
        }
        p = p->prox;
    }
    return(existe);
}

int existeArestaLista(grafoMatriz *g, int v, int u){

    int existe = 0;

    if (g->matriz[v][u] == 1){
        existe = 1;
    }

    return(existe);
}

int main(){

    grafoMatriz g = CriaGrafoMatriz(10);

    grafoLista g2 = CriaGrafoLista(10);

    for (int i = 0; i < 9; i++){
        inserirArestaMatriz(&g, i, i + 1);
    }

    for (int i = 9; i > 0; i--){
        inserirArestaLista(&g2, i, i - 1);
    }

    imprimirMatriz(&g);
    printf("\n");
    imprimirLista(&g2);

}