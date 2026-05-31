#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    char letra;
    int posicao;
    int quantidade;
} LetraQuantidade;

int comparar(const void *a, const void *b) {
    LetraQuantidade *la = (LetraQuantidade *)a;
    LetraQuantidade *lb = (LetraQuantidade *)b;

    if (lb->quantidade != la->quantidade)
        return lb->quantidade - la->quantidade;

    return la->posicao - lb->posicao;
}

int main(){

    LetraQuantidade letras[100001];

    char sequencia[100001];
    int indice = 0;
    bool novo = true;

    scanf("%s", sequencia);

    int comprimento = strlen(sequencia);

    for (size_t i = 0; i < comprimento; i++){

        if( i != 0 && sequencia[i] == sequencia[i-1]) { 

            novo = false;
            letras[indice-1].quantidade++;
        }
        
        if (novo) {
                letras[indice].letra = sequencia[i];
                letras[indice].posicao = i;
                letras[indice].quantidade++;
                indice++;
        }
    
        novo = true;
    };
    
    int n = 0;

    qsort(letras, indice, sizeof(LetraQuantidade), comparar);

    while (letras[n].letra != '\0') {
        printf("%d %c %d\r\n", letras[n].quantidade, letras[n].letra, letras[n].posicao);
        n++;
    }

    return 0;
}