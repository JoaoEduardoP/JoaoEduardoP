#include <stdio.h>
#include <stdlib.h>

#define MAX_INSTRUCTIONS 45000

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    
    int *Carteiro = (int *)malloc(1000000000 * sizeof(int));
    int *Casas = (int *)malloc(N * sizeof(int));
    int *Entregas = (int *)malloc(MAX_INSTRUCTIONS * sizeof(int));

    for (int i = 0; i < N; i++) {
        scanf("%d", &Casas[i]);
        Carteiro[Casas[i]] = i;
    }

    for (int i = 0; i < M; i++) {
        scanf("%d", &Entregas[i]);
    }

    int Tempo_Total = 0;
    int Pos_Carteiro = Carteiro[Casas[0]];

    for (int i = 0; i < M; i++) {
        
        int Proxima_Posicao = Carteiro[Entregas[i]];

        Tempo_Total += abs(Proxima_Posicao - Pos_Carteiro);

        Pos_Carteiro = Proxima_Posicao;
    }

    printf("%d\n", Tempo_Total);

    free(Casas);
    free(Entregas);
    free(Carteiro);

    return 0;
}