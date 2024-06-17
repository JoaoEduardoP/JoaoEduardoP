#include <stdio.h>

int pontos_tiro_ao_alvo(int C, int T, int raios[], int tiros[][2]) {
    int pontuacao = 0;
    for (int i = 0; i < T; i++) {
        int x = tiros[i][0];
        int y = tiros[i][1];
        for (int j = 0; j < C; j++) {
            if (x * x + y * y <= raios[j] * raios[j]) {
                pontuacao++;
                break;
            }
        }
    }
    return pontuacao;
}

int main() {
    int C, T;
    scanf("%d %d", &C, &T);

    int raios[C];
    for (int i = 0; i < C; i++) {
        scanf("%d", &raios[i]);
    }

    int tiros[T][2];
    for (int i = 0; i < T; i++) {
        scanf("%d %d", &tiros[i][0], &tiros[i][1]);
    }

    printf("%d\n", pontos_tiro_ao_alvo(C, T, raios, tiros)+5);

    return 0;
}