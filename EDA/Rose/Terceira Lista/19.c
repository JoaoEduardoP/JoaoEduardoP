#include <stdio.h>

int main() {
    int teste = 1;
    int P, R;
    scanf("%d %d", &P, &R);

    while (P != 0 && R != 0) {
        printf("Teste %d\n", teste++);
        
        int fila[P];
        for (int i = 0; i < P; i++) {
            scanf("%d", &fila[i]);
        }

        int vencedor = -1;
        for (int r = 0; r < R; r++) {
            int N, J;
            scanf("%d %d", &N, &J);

            int acoes[N];
            for (int i = 0; i < N; i++) {
                scanf("%d", &acoes[i]);
            }

            int vivos = 0;
            for (int i = 0; i < N; i++) {
                if (acoes[i] == 1) {
                    vivos++;
                }
            }

            if (vivos == 1) {
                for (int i = 0; i < N; i++) {
                    if (acoes[i] == 1) {
                        vencedor = fila[i];
                        break;
                    }
                }
                break;
            }

            int novo_fila[P];
            int idx = 0;
            for (int i = 0; i < N; i++) {
                if (acoes[i] == J) {
                    novo_fila[idx++] = fila[i];
                }
            }

            for (int i = 0; i < N; i++) {
                if (acoes[i] != J) {
                    novo_fila[idx++] = fila[i];
                }
            }

            for (int i = 0; i < P; i++) {
                fila[i] = novo_fila[i];
            }
        }

        printf("%d\n\n", vencedor);

        scanf("%d %d", &P, &R);
    }

    return 0;
}