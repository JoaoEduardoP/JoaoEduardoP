#include <stdio.h>
#include <stdlib.h>

// Números Malucos Únicos Reinseridos

int Compara(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int Remove_Duplicados(int *Array, int n) {
    if (n == 0) return 0;
    int j = 0;
    for (int i = 1; i < n; i++) {
        if (Array[i] != Array[j]) {
            j++;
            Array[j] = Array[i];
        }
    }
    return j + 1;
}

int main() {
    int N;
    scanf("%d", &N);

    int *Numeros = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &Numeros[i]);
    }

    qsort(Numeros, N, sizeof(int), Compara);
    N = Remove_Duplicados(Numeros, N);

    if (N % 2 != 0) {
        Numeros = (int *)realloc(Numeros, (N + 1) * sizeof(int));
        Numeros[N] = 1000000000;
        N++;
    }

    int *nmu = (int *)malloc((N / 2) * sizeof(int));
    int nmu_count = 0;
    for (int i = 0; i < N; i += 2) {
        nmu[nmu_count++] = Numeros[i] + Numeros[i + 1];
    }

    int Novo_Tamanho = N;
    for (int i = 0; i < nmu_count; i++) {
        int found = 0;
        for (int j = 0; j < N; j++) {
            if (Numeros[j] == nmu[i]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            Numeros = (int *)realloc(Numeros, (Novo_Tamanho + 1) * sizeof(int));
            Numeros[Novo_Tamanho++] = nmu[i];
        }
    }

    qsort(Numeros, Novo_Tamanho, sizeof(int), Compara);

    for (int i = 0; i < Novo_Tamanho; i += 4) {
        printf("%d\n", Numeros[i]);
    }

    printf("Elementos: %d\n", Novo_Tamanho);

    free(Numeros);
    free(nmu);

    return 0;
}