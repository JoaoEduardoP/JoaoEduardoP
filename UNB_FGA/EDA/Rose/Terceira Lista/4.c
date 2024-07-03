#include <stdio.h>
#include <stdlib.h>

typedef struct fila{
    int *Dados;
    int N;
    int p;
    int u;
} fila;

int enfileira(fila *Filas, int x){
    if ((Filas->u + 1) % Filas->N == Filas->p){
        Filas->Dados = realloc(Filas->Dados, 2 * Filas->N * sizeof(int));

        if (Filas->Dados == NULL){
            return 1;
        }
        
        for (int i = Filas->N; i < 2 * Filas->N; i++){
            Filas->Dados[i] = 0;
        }

        if (Filas->p != 0){
            if (Filas->N - Filas->p < Filas->u){
                for (int i = Filas->N - 1; i >= Filas->p; i--){
                    Filas->Dados[i + Filas->N] = Filas->Dados[i];
                }
                Filas->p += Filas->N;
            }
            else{
                for (int i = 0; i < Filas->u; i++){
                    Filas->Dados[i + Filas->N] = Filas->Dados[i];
                }
                Filas->u += Filas->N;
            }
        }

        Filas->N *= 2;
    }

    Filas->Dados[Filas->u] = x;
    Filas->u = (Filas->u + 1) % Filas->N;
    return 0;
}