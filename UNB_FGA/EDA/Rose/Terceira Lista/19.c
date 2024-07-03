#include <stdio.h>
#include <stdlib.h>

void Turno(int* Participantes, int Ordem, int* Tamanho, int* Movimentos) {
    int newSize = 0;
    for (int i = 0; i < *Tamanho; i++) {
        if (i < Tamanho && Movimentos[i] == Ordem) {
            Participantes[newSize++] = Participantes[i];
        }
    }
    *Tamanho = newSize;
}

int main() {
    int Teste_n = 1;
    while (1) {
        int P, R;
        scanf("%d %d", &P, &R);
        if (P == 0 && R == 0){
            break;
        } 

        int* Participantes = (int*)malloc(P * sizeof(int));
        for (int i = 0; i < P; i++) {
            scanf("%d", &Participantes[i]);
        }

        for (int r = 0; r < R; r++) {
            int Tamanho;
            int Ordem;

            scanf("%d %d", &Tamanho, &Ordem);

            int* Movimentos = (int*)malloc(Tamanho * sizeof(int));
            for (int i = 0; i < Tamanho; i++) {
                scanf("%d", &Movimentos[i]);
            }

            Turno(Participantes, Ordem, &P, Movimentos);

            free(Movimentos);
        }

        printf("Teste %d\n", Teste_n++);
        if (P == 1) {
            printf("%d\n", Participantes[0]);
        }
        printf("\n");

        free(Participantes);
    }

    return 0;
}