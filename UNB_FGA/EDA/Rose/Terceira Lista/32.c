#include <stdio.h>

int main() {
    int P, R, teste = 1;

    while (scanf("%d %d", &P, &R), P || R) {
        int fila[100];
        for (int i = 0; i < P; i++) {
            scanf("%d", &fila[i]);
        }

        for (int r = 0; r < R; r++) {
            int N, J, acao[100];
            scanf("%d %d", &N);

            for (int i = 0; i < N; i++) {
                scanf("%d", &acao[i]);
            }
            scanf("%d", &J);

            int nova_fila[100], nova_tamanho = 0;

            for (int i = 0, j = 0; i < P; i++) {
                if (j < N && fila[i] == acao[j]) {
                    j++;
                    if (acao[j - 1] == J) {
                        nova_fila[nova_tamanho++] = fila[i];
                    }
                } else {
                    nova_fila[nova_tamanho++] = fila[i];
                }
            }

            P = nova_tamanho;
            for (int i = 0; i < P; i++) {
                fila[i] = nova_fila[i];
            }
        }

        printf("Teste %d\n%d\n\n", teste++, fila[0]);
    }

    return 0;
}