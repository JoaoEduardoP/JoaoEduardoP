#include <stdio.h>
#include <stdlib.h>

// Número Proibido

int Compara(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int N;
    scanf("%d", &N);

    int *Proibidos = (int *)malloc(N * sizeof(int));
    if (Proibidos == NULL) {
        fprintf(stderr, "Erro de alocação de memória\n");
        return 1;
    }

    for (int i = 0; i < N; i++) {
        scanf("%d", &Proibidos[i]);
    }

    qsort(Proibidos, N, sizeof(int), Compara);

    int Query;

    while (scanf("%d", &Query) != EOF) {
        if (bsearch(&Query, Proibidos, N, sizeof(int), Compara) != NULL) {
            printf("sim\n");
        } else {
            printf("nao\n");
        }
    }

    free(Proibidos);

    return 0;
}