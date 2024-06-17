#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int Valor;
    int Index;
} Numeros;

int Comparacao(const void *a, const void *b) {
    return ((Numeros *)a)->Valor - ((Numeros *)b)->Valor;
}

int Busca_Binaria(Numeros Array[], int Tamanho, int target) {
    int Esquerda = 0, Direita = Tamanho - 1;
    while (Esquerda <= Direita) {
        int Meio = (Esquerda + Direita) / 2;
        if (Array[Meio].Valor == target) {
            return Array[Meio].Index;
        } else if (Array[Meio].Valor < target) {
            Esquerda = Meio + 1;
        } else {
            Direita = Meio - 1;
        }
    }
    return -1;
}

int main() {
    int N, M;

    scanf("%d %d", &N, &M);

    Numeros *Numero = (Numeros *)malloc(N * sizeof(Numeros));
    int *Busca_Numeros = (int *)malloc(M * sizeof(int));

    for (int i = 0; i < N; i++) {
        scanf("%d", &Numero[i].Valor);
        Numero[i].Index = i;
    }

    for (int i = 0; i < M; i++) {
        scanf("%d", &Busca_Numeros[i]);
    }

    qsort(Numero, N, sizeof(Numeros), Comparacao);

    for (int i = 0; i < M; i++) {
        int Resultado = Busca_Binaria(Numero, N, Busca_Numeros[i]);
        printf("%d\n", Resultado);
    }

    free(Numero);
    free(Busca_Numeros);

    return 0;
}