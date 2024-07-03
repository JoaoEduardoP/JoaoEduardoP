#include <stdio.h>
#include <stdlib.h>

// Eleição U.R.S.A.L

typedef struct {
    int Numero;
    int Votos;
} Candidato;

int Compara(const void *a, const void *b) {
    Candidato *candidatoA = (Candidato *)a;
    Candidato *candidatoB = (Candidato *)b;

    if (candidatoA->Votos == candidatoB->Votos) {
        return candidatoB->Numero - candidatoA->Numero;
    }
    return candidatoB->Votos - candidatoA->Votos;
}

void Eleger(Candidato *Candidatos, int Total, int Quantidade) {
    qsort(Candidatos, Total, sizeof(Candidato), Compara);
    for (int i = 0; i < Quantidade && i < 100000; i++) {
        if (i > 0) printf(" ");
        printf("%d", Candidatos[i].Numero);
    }
    printf("\n");
}

int main() {
    int S, F, E;
    scanf("%d %d %d", &S, &F, &E);
    Candidato Presidentes[100] = {0};
    Candidato Senadores[1000] = {0};
    Candidato DeputadoFederal[10000] = {0};
    Candidato DeputadoEstadual[100000] = {0};

    int TotalPresidentes = 0;
    int TotalSenadores = 0;
    int TotalDeputadoFederal = 0;
    int TotalDeputadoEstadual = 0;

    int TotalVotosPresidentes = 0;
    int TotalVotosValidos = 0;
    int TotalVotosInvalidos = 0;

    int Voto;
    while (scanf("%d", &Voto) != EOF) {
        if (Voto < 0) {
            TotalVotosInvalidos++;
            continue;
        }
        TotalVotosValidos++;

        int nDigitos = snprintf(NULL, 0, "%d", Voto);
        Candidato *Candidatos;
        int *TotalCandidatos;

        switch (nDigitos) {
            case 2:
                Candidatos = Presidentes;
                TotalCandidatos = &TotalPresidentes;
                TotalVotosPresidentes++;
                break;
            case 3:
                Candidatos = Senadores;
                TotalCandidatos = &TotalSenadores;
                break;
            case 4:
                Candidatos = DeputadoFederal;
                TotalCandidatos = &TotalDeputadoFederal;
                break;
            case 5:
                Candidatos = DeputadoEstadual;
                TotalCandidatos = &TotalDeputadoEstadual;
                break;
            default:
                printf("Inválido\n");
                TotalVotosInvalidos++;
                TotalVotosValidos--;
                continue;
        }

        int Achou = 0;
        for (int i = 0; i < *TotalCandidatos && i < 100000; i++) {
            if (Candidatos[i].Numero == Voto) {
                Candidatos[i].Votos++;
                Achou = 1;
                break;
            }
        }
        if (!Achou) {
            Candidatos[*TotalCandidatos].Numero = Voto;
            Candidatos[*TotalCandidatos].Votos = 1;
            (*TotalCandidatos)++;
        }
    }

    printf("%d %d\n", TotalVotosValidos, TotalVotosInvalidos);
    
    int GanhadorEleicao = 0;
    for (int i = 0; i < TotalPresidentes; i++){
        if ((double)Presidentes[i].Votos / TotalVotosPresidentes > 0.5) {
            printf("%d\n", Presidentes[i].Numero);
            GanhadorEleicao = 1;
            break;
        }
    }
    if (!GanhadorEleicao){
        printf("Segundo turno\n");
    }

    Eleger(Senadores, TotalSenadores, S);
    Eleger(DeputadoFederal, TotalDeputadoFederal, F);
    Eleger(DeputadoEstadual, TotalDeputadoEstadual, E);

    return 0;
}