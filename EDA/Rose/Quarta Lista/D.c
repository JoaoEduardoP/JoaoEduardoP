#include <stdio.h>

#define MAX_SIZE 1000

void bubbleSort(int Array[], int Tamanho) {
    int i, j, temp;
    for (i = 0; i < Tamanho - 1; i++) {
        for (j = 0; j < Tamanho - i - 1; j++) {
            if (Array[j] > Array[j + 1]) {
                temp = Array[j];
                Array[j] = Array[j + 1];
                Array[j + 1] = temp;
            }
        }
    }
}

int main() {
    int Numeros[MAX_SIZE];
    int Numero, Tamanho = 0;

    while (scanf("%d", &Numero) != EOF && Tamanho < MAX_SIZE) {
        Numeros[Tamanho++] = Numero;
    }

    bubbleSort(Numeros, Tamanho);

    for (int i = 0; i < Tamanho; i++) {
        printf("%d", Numeros[i]);
        if (i != Tamanho - 1) {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}
