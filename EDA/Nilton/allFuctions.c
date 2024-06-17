#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
int dado;
struct celula *prox;
} celula;
//Criar

celula * criar_lista ();
//Busca
celula *busca (celula *le, int x);
celula *busca_rec (celula *le, int x);
// Divide
void divide_lista (celula *l, celula *l1, celula *l2);
//Impressão
void imprime (celula *le);
void imprime_rec (celula *le);
//Inserção
void insere_inicio (celula *le, int x);
void insere_antes (celula *le, int x, int y);
//Juntar
void mescla_listas (celula *l1, celula *l2, celula *l3);
//Remove
int remove_depois (celula *p);
void remove_elemento (celula *le, int x);
void remove_todos_elementos (celula *le, int x);

//Função principal

int main () {
    celula *l1 = criar_lista();
    insere_inicio(l1, 118);
    insere_inicio(l1, 117);
    insere_inicio(l1, 117);
     insere_inicio(l1, 118);
    insere_inicio(l1, 117);
    insere_inicio(l1, 117);
    insere_inicio(l1, 115);
    imprime_rec(l1);
    remove_todos_elementos(l1, 118);
    imprime_rec(l1);

    return 0;
}
//Criar
celula * criar_lista () {
    celula *le = malloc(sizeof(celula));
    le->prox = NULL;
    return le;
}
//Insere
void insere_inicio (celula *le, int x) {
    celula *p;
    p = le;
    celula *nova;
    nova = malloc(sizeof(celula));
    nova->dado = x;
    nova->prox = p->prox;
    p->prox = nova;
}
    void insere_antes (celula *le, int x, int y) {
    
    celula *p, *nova;
    p = le;
    nova = malloc(sizeof(celula));
    nova->dado = x;
    if (le == NULL)
    {
        insere_inicio(le, x);
    }
    while (p->prox!= NULL && p->prox->dado != y)
    {
        p = p->prox;
    }
    //
    nova->prox = p->prox;
    p->prox = nova;
}

//imprime
void imprime (celula *le) {
    celula *p;
    p = le->prox;
    while(p != NULL)
    {
        printf("%d -> ", p->dado);
        p = p->prox;
    }
    printf("NULL\n");
}

void imprime_rec (celula *le) {
    if (le->prox != NULL) {
        printf("%d -> ", le->prox->dado);
        imprime_rec(le->prox);
    }
        if(le->prox == NULL) printf("NULL\n");
}

//Mesclar
void mescla_listas (celula *l1, celula *l2, celula *l3) {
    celula *p1 = l1->prox;
    celula *p2 = l2->prox;
    celula *p3 = l3;

    while (p1 != NULL && p2 != NULL)
    {
        if(p1->dado <= p2->dado) {
            p3->prox = p1;
            p1 = p1->prox;
        } else {
            p3->prox = p2;
            p2 = p2->prox;
        }
        p3 = p3->prox;

    }

    if (p1 != NULL) {
        p3->prox = p1;
    } else {
        p3->prox = p2;
    }
}
//remove
int remove_depois (celula *p) {
    if (p->prox != NULL)
    {
     celula *lixo;
    lixo = p->prox;
    p->prox = lixo->prox;
    free(lixo);
    return 1;
    }
    return 0;
}

void remove_elemento (celula *le, int x) {
    celula *lixo;
    celula *p = le;
    while (p->prox != NULL && p->prox->dado != x)
    {
        p = p->prox;
    }
    if (p->prox != NULL)
    {
        lixo = p->prox;
        p->prox = lixo->prox;
        free(lixo);
    }
    return;
}

void remove_todos_elementos (celula *le, int x) {
    celula *p = le;
    while (p->prox != NULL)
    {
        if (p->prox->dado == x)
        {
           celula *lixo = p->prox;
           p->prox = lixo->prox;
           free(lixo);
        } else {
            p = p->prox;
        }
        
    }
    
}

