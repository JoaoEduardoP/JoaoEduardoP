#include <stdio.h>
#include <stdlib.h>

typedef struct NO {
    int Dados;
    struct NO *Esquerda, *Direita;
} NO;

NO* Criar_No(int Dados) {
    NO* Temporario = (NO*)malloc(sizeof(NO));
    Temporario->Dados = Dados;
    Temporario->Esquerda = Temporario->Direita = NULL;
    return Temporario;
}

NO* Inserir(NO* Raiz, int Dados) {
    if (Raiz == NULL) {
        return Criar_No(Dados);
    }
    if (Dados < Raiz->Dados) {
        Raiz->Esquerda = Inserir(Raiz->Esquerda, Dados);
    } else {
        Raiz->Direita = Inserir(Raiz->Direita, Dados);
    }
    return Raiz;
}

typedef struct Pilha {
    NO* Dados;
    struct Pilha* prox;
} Pilha;

void Empilhar(Pilha** topo_ref, NO* novo_no) {
    Pilha* nova_pilha = (Pilha*)malloc(sizeof(Pilha));
    if (nova_pilha == NULL) {
        printf("Erro de memória\n");
        exit(0);
    }
    nova_pilha->Dados = novo_no;
    nova_pilha->prox = (*topo_ref);
    (*topo_ref) = nova_pilha;
}

NO* Desempilhar(Pilha** topo_ref) {
    NO* res;
    Pilha* topo;
    
    if (*topo_ref == NULL) {
        printf("Pilha vazia\n");
        exit(0);
    } else {
        topo = *topo_ref;
        res = topo->Dados;
        *topo_ref = topo->prox;
        free(topo);
        return res;
    }
}

int Vazia(Pilha* topo) {
    return (topo == NULL) ? 1 : 0;
}

void Pre_Ordem(NO* Raiz) {
    if (Raiz == NULL) return;
    
    Pilha* pilha = NULL;
    Empilhar(&pilha, Raiz);

    while (!Vazia(pilha)) {
        NO* No_Local = Desempilhar(&pilha);
        printf("%d ", No_Local->Dados);

        if (No_Local->Direita) Empilhar(&pilha, No_Local->Direita);
        if (No_Local->Esquerda) Empilhar(&pilha, No_Local->Esquerda);
    }
    printf(".\n");
}

void Em_Ordem(NO *Raiz) {
    if (Raiz == NULL) return;

    NO *Atual = Raiz;
    NO *Anterior;

    while (Atual != NULL) {
        if (Atual->Esquerda == NULL) {
            printf("%d ", Atual->Dados);
            Atual = Atual->Direita;
        } else {

            Anterior = Atual->Esquerda;
            while (Anterior->Direita != NULL && Anterior->Direita != Atual) {
                Anterior = Anterior->Direita;
            }

            if (Anterior->Direita == NULL) {
                Anterior->Direita = Atual;
                Atual = Atual->Esquerda;
            } else {
                Anterior->Direita = NULL;
                printf("%d ", Atual->Dados);
                Atual = Atual->Direita;
            }
        }
    }
    printf(".\n");
}

void pos_ordem(NO* Raiz) {
    if (Raiz == NULL) return;
    
    Pilha* pilha1 = NULL;
    Pilha* pilha2 = NULL;

    Empilhar(&pilha1, Raiz);
    NO* No_Local;

    while (!Vazia(pilha1)) {
        No_Local = Desempilhar(&pilha1);
        Empilhar(&pilha2, No_Local);

        if (No_Local->Esquerda) Empilhar(&pilha1, No_Local->Esquerda);
        if (No_Local->Direita) Empilhar(&pilha1, No_Local->Direita);
    }

    while (!Vazia(pilha2)) {
        No_Local = Desempilhar(&pilha2);
        printf("%d ", No_Local->Dados);
    }
    printf(".\n");
}

int main() {
    NO* Raiz = NULL;
    int num;

    while (scanf("%d", &num) != EOF) {
        Raiz = Inserir(Raiz, num);
    }

    Pre_Ordem(Raiz);
    Em_Ordem(Raiz);
    pos_ordem(Raiz);

    return 0;
}
