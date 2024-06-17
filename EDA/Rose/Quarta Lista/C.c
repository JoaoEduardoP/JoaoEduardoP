#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int *Dado;
    int Tamanho_Maximo;
    int Tamanho;
} Fila_Prioridade;

void PQInit(Fila_Prioridade *Prior_Queue, int Tamanho_Maximo){

    Prior_Queue->Dado = (int *)malloc(Tamanho_Maximo * sizeof(int));
    Prior_Queue->Tamanho_Maximo = Tamanho_Maximo;
    Prior_Queue->Tamanho = 0;

}

void PQInsert(Fila_Prioridade *Prior_Queue, int item){

    Prior_Queue->Dado[++Prior_Queue->Tamanho] = item;
    fixUp(Prior_Queue, Prior_Queue->Tamanho);

}

void PQchange(Fila_Prioridade *Prior_Queue, int n, int valor){

    if (Prior_Queue->Dado[n] < valor){
        
        Prior_Queue->Dado[n] = valor;
        fixDown(Prior_Queue, n, Prior_Queue->Tamanho);

    }
    else{

        Prior_Queue->Dado[n] = valor;
        fixUp(Prior_Queue, n);

    }

}

int PQdelmin(Fila_Prioridade *Prior_Queue){

    swap(&Prior_Queue->Dado[1], &Prior_Queue->Dado[Prior_Queue->Tamanho]);
    fixDown(Prior_Queue, 1, Prior_Queue->Tamanho - 1);
    return Prior_Queue->Dado[Prior_Queue->Tamanho--];
    
}

void swap(int *a, int *b){

    int aux = *a;
    *a = *b;
    *b = aux;

}

void fixUp(Fila_Prioridade *Prior_Queue, int n){

    while (n > 1 && Prior_Queue->Dado[n] < Prior_Queue->Dado[n / 2]){

        swap(&Prior_Queue->Dado[n], &Prior_Queue->Dado[n / 2]);
        n = n / 2;
        
    }

}

void fixDown(Fila_Prioridade *Prior_Queue, int n, int m){

    while (2 * n <= m){

        int j = 2 * n;

        if (j < m && Prior_Queue->Dado[j] > Prior_Queue->Dado[j + 1])
            j++;

        if (Prior_Queue->Dado[n] <= Prior_Queue->Dado[j])
            break;

        swap(&Prior_Queue->Dado[n], &Prior_Queue->Dado[j]);
        n = j;

    }

}

int main(){
    int n, m;
    Fila_Prioridade Prior_Queue;
    PQInit(&Prior_Queue, 100);

    while (scanf("%d %d", &n, &m) == 2){

        if (n == 1){

            if (Prior_Queue.Tamanho == 100){

                int maior = Prior_Queue.Tamanho;
                for (int i = Prior_Queue.Tamanho / 2; i<Prior_Queue.Tamanho; i++){

                    if (Prior_Queue.Dado[i] > Prior_Queue.Dado[maior]){
                        maior = i;
                    }

                }

                if (Prior_Queue.Dado[maior]>m)
                    PQchange(&Prior_Queue, maior, m);
                
            }
            else
                PQInsert(&Prior_Queue, m);
            
        }
        else{
            int aux[100];
            
            for (int i = 0; i<m; i++){

                aux[i] = PQdelmin(&Prior_Queue);
                printf("%d ", aux[i]);
                
            }

            for (int i = 0; i<m; i++){
                PQInsert(&Prior_Queue, aux[i]);
            }

            printf("\n");
        }
    }

    return 0;
}