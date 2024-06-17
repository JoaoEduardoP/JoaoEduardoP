#include <stdio.h>

#define MAX_SIZE 1000

void selectionSort(int array[], int Tamanho) {
    int i, j, minIndex, temp;
    for (i = 0; i < Tamanho - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < Tamanho; j++) {
            if (array[j] < array[minIndex]) {
                minIndex = j;
            }
        }

        temp = array[minIndex];
        array[minIndex] = array[i];
        array[i] = temp;
    }
}

int main() {
    int Numeros[MAX_SIZE];
    int Numero, Tamanho = 0;

    while (scanf("%d", &Numero) != EOF && Tamanho < MAX_SIZE) {
        Numeros[Tamanho++] = Numero;
    }

    selectionSort(Numeros, Tamanho);

    for (int i = 0; i < Tamanho; i++) {
        printf("%d", Numeros[i]);
        if (i != Tamanho - 1) {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}