#include <stdio.h>

#define MAX_SIZE 50000

void insertionSort(int array[], int Tamanho) {
    int i, j, key;
    for (i = 1; i < Tamanho; i++) {
        key = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
}

int main() {
    int Numeros[MAX_SIZE];
    int Numero, Tamanho = 0;

    while (scanf("%d", &Numero) != EOF && Tamanho < MAX_SIZE) {
        Numeros[Tamanho++] = Numero;
    }

    insertionSort(Numeros, Tamanho);

    for (int i = 0; i < Tamanho; i++) {
        printf("%d", Numeros[i]);
        if (i != Tamanho - 1) {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}