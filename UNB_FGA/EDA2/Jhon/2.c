#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned long long codigo;
    int nota;
} Semente;

// 1ª ordenação: por nota (menor = melhor), desempate por código (menor)
static int comparaNota(const void *a, const void *b) {
    const Semente *s1 = (Semente *) a;
    const Semente *s2 = (Semente *) b;
    if (s1->nota != s2->nota)
        return (s1->nota > s2->nota) - (s1->nota < s2->nota);
    return (s1->codigo > s2->codigo) - (s1->codigo < s2->codigo);
}

// 2ª ordenação: por código (menor para maior)
static int comparaCodigo(const void *a, const void *b) {
    const Semente *s1 = (Semente *) a;
    const Semente *s2 = (Semente *) b;
    return (s1->codigo > s2->codigo) - (s1->codigo < s2->codigo);
}
int main(){

    int possivel_Amostra = 10000000;
    int quantidade_Filtro = 0;
    int quantidade_Real = 0;

    Semente *sementes = malloc( possivel_Amostra *sizeof(Semente));

    scanf("%d", &quantidade_Filtro);

    while(scanf("%llu %d", &sementes[quantidade_Real].codigo, &sementes[quantidade_Real].nota) == 2){
        quantidade_Real++;
    }

    qsort(sementes, quantidade_Real, sizeof(Semente), comparaNota);

    int saida = quantidade_Real < quantidade_Filtro ? quantidade_Real : quantidade_Filtro;

    qsort(sementes, saida, sizeof(Semente), comparaCodigo);

    for (int i = 0; i < saida; i++) {
        printf("%llu %d\n", sementes[i].codigo, sementes[i].nota);
    }


    free(sementes);
    return 0;
}