#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 16

typedef struct {
    int  Codigo;
    char Comando[MAX_SIZE];
} Instrucoes;

typedef struct {
    Instrucoes* Lista;
    int Valor;
} DataBase;

int Comparacao(const void* a, const void* b) {

    return ((Instrucoes*)a)->Codigo - ((Instrucoes*)b)->Codigo;

}

void Free_Dados(DataBase* DataBase) {

    free(DataBase->Lista);

}

void Carregar_Instrucoes(DataBase* DataBase) {
    scanf("%d", &DataBase->Valor);
    DataBase->Lista = (Instrucoes*) malloc(DataBase->Valor * sizeof(Instrucoes));

    for (int i = 0; i<DataBase->Valor; i++) {

        scanf("%d %s", &DataBase->Lista[i].Codigo, DataBase->Lista[i].Comando);

    }

    qsort(DataBase->Lista, DataBase->Valor, sizeof(Instrucoes), Comparacao);
}

char* Busca_Binaria(DataBase* DataBase, int Codigo) {
    int Esquerda = 0;
    int Direita = DataBase->Valor - 1;
    
    while (Esquerda <= Direita) {
        int Meio = (Esquerda + Direita) / 2;

        if (DataBase->Lista[Meio].Codigo == Codigo) {

            return DataBase->Lista[Meio].Comando;

        } else if (DataBase->Lista[Meio].Codigo < Codigo) {

            Esquerda = Meio + 1;

        } else {

            Direita = Meio - 1;

        }
    }
    return "undefined";
}

int main() {
    DataBase Dados;
    Carregar_Instrucoes(&Dados);
    int Codigo;

    while (scanf("%d", &Codigo) != EOF) {

        printf("%s\n", Busca_Binaria(&Dados, Codigo));

    }

    Free_Dados(&Dados);
    return 0;
}