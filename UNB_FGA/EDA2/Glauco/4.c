#include <stdio.h>
#include <stdlib.h>

typedef struct Grafo{
    int v;
    int **matriz;
}Grafo;

Grafo* cria_Grafo(int V){
    
    Grafo *n = malloc(sizeof(Grafo));
    n->v = V;
    n->matriz = malloc(V * sizeof(int*));

    for(int i = 0; i < V; i++){
        n->matriz[i] = malloc(V * sizeof(int));

        for(int j = 0; j < V; j++){
            n->matriz[i][j] = 0;
        }
    }

    return n;
};

int acha_Caminho(int c1, int c2, Grafo *g){
    int R = 0;

    if (c1 == c2)
        return 1;

    while (R < g->v){
        if(g->matriz[c1][R] == 1){
            if(acha_Caminho(R, c2, g) == 1){
                return 1;
            }
        }
            
        R++;
    }
    return 0;
};

void inserir_Aresta(Grafo *g, int v,int a){
    g->matriz[v][a] = 1;
    g->matriz[a][v] = 1;
};

void libera_Grafo(Grafo *g) {
    for (int i = 0; i < g->v; i++)
        free(g->matriz[i]);
    free(g->matriz);
    free(g);
}


int main() {
    int V, A, v1, v2, c1, c2;

    scanf("%d %d", &V, &A);
    Grafo *g = cria_Grafo(V);

    for(int k = 0; k < A; k++){
        
        scanf("%d %d", &v1, &v2);

        inserir_Aresta(g, v1, v2);
    }

    scanf("%d %d", &c1, &c2);

    if(acha_Caminho(c1,c2, g)){
        printf("Existe caminho\n");
    }
    else{
        printf("Nao existe caminho\n");
    }

    libera_Grafo(g);
    return 0;
}