#include <stdio.h>
#include <stdlib.h>

typedef struct Paciente{
    unsigned long long Codigo;
    int Gravidade; 
} Paciente;

int Compara_Gravidade(const void *a, const void *b){
    Paciente *pa = (Paciente *) a;
    Paciente *pb = (Paciente *) b;

    if ( pa->Gravidade != pb->Gravidade)
        return(( pa->Gravidade > pb->Gravidade ) - ( pa->Gravidade < pb->Gravidade));
    return(( pa->Codigo > pb->Codigo ) - ( pa->Codigo < pb->Codigo));
}

int Compara_Codigo(const void *a, const void *b){
    Paciente *pa = (Paciente *) a;
    Paciente *pb = (Paciente *) b;

    return(( pa->Codigo > pb->Codigo ) - ( pa->Codigo < pb->Codigo));
}


int main(){

    int Maximo_Pacientes = 10000000;
    int Quantidade_Filtro = 0;
    int Quantidade_Pacientes = 0;
    int Quantidade_Final = 0;

    scanf("%d", &Quantidade_Filtro);

    Paciente *pacientes = malloc( Maximo_Pacientes * sizeof(Paciente));

    if (pacientes == NULL){
        printf("Erro ao Alocar a Memória\n");
    }
    else{
        while(scanf("%llu %d", &pacientes[Quantidade_Pacientes].Codigo, &pacientes[Quantidade_Pacientes].Gravidade) == 2){
            Quantidade_Pacientes++;
        }
        
        qsort(pacientes, Quantidade_Pacientes, sizeof(Paciente), Compara_Gravidade);
        
        Quantidade_Final = Quantidade_Pacientes < Quantidade_Filtro ? Quantidade_Pacientes : Quantidade_Filtro;

        qsort(pacientes, Quantidade_Final, sizeof(Paciente), Compara_Codigo);

        for (size_t i = 0; i < Quantidade_Final; i++){
            printf("%llu %d\n", pacientes[i].Codigo, pacientes[i].Gravidade);
        }

        free(pacientes);
    }
}