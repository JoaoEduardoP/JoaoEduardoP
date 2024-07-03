#include <stdio.h>
#include <stdlib.h>

// Implemente o QuickSort

void Troca(int *a, int *b) {
    int Temporario = *a;
    *a = *b;
    *b = Temporario;
}

int MedianaDeTres(int Arr[], int Baixo, int Alto) {
    int Meio = (Baixo + Alto) / 2;
    if (Arr[Baixo] > Arr[Meio])
        Troca(&Arr[Baixo], &Arr[Meio]);
    if (Arr[Baixo] > Arr[Alto])
        Troca(&Arr[Baixo], &Arr[Alto]);
    if (Arr[Meio] > Arr[Alto])
        Troca(&Arr[Meio], &Arr[Alto]);
    Troca(&Arr[Meio], &Arr[Alto - 1]);
    return Arr[Alto - 1];
}

int Particao(int Arr[], int Baixo, int Alto) {
    int Pivô = MedianaDeTres(Arr, Baixo, Alto);
    int i = Baixo;
    int j = Alto - 1;

    while (1) {
        while (Arr[++i] < Pivô);
        while (Arr[--j] > Pivô);
        if (i >= j)
            break;
        Troca(&Arr[i], &Arr[j]);
    }
    Troca(&Arr[i], &Arr[Alto - 1]);
    return i;
}

void QuickSort(int Arr[], int Baixo, int Alto) {
    if (Baixo + 10 <= Alto) {
        int ParticaoIndex = Particao(Arr, Baixo, Alto);
        QuickSort(Arr, Baixo, ParticaoIndex - 1);
        QuickSort(Arr, ParticaoIndex + 1, Alto);
    } else {
        for (int i = Baixo + 1; i <= Alto; i++) {
            int Temporario = Arr[i];
            int j;
            for (j = i; j > Baixo && Arr[j - 1] > Temporario; j--)
                Arr[j] = Arr[j - 1];
            Arr[j] = Temporario;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int Arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &Arr[i]);
    }

    QuickSort(Arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%d", Arr[i]);
        if (i < n - 1) {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}