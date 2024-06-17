#include <stdio.h>

void ImprimirValores(int *vetor, int index, int l, int soma, int c) {
    if (index == c) return;

    soma += vetor[index];

    if (soma > l) {
        ImprimirValores(vetor, index+1, l, 0, c);
        printf("%d\n", vetor[index]);
    } else {
        ImprimirValores(vetor, index+1, l, soma, c);
    }
}


int main() {
    int n, l, vetor[1000], c = 0;

    while (scanf("%d", &n) && n != 0){
        vetor[c++] = n;
    } 

    scanf("%d", &l);

    ImprimirValores(vetor, 0, l, 0, c);
    
    return 0;
}