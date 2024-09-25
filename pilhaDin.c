#include <stdio.h>
#include <stdlib.h>

//Pilha dinamica
typedef struct Tnode{
    int dado;
    struct Tnode* prox;
} node;

int Inicializar_pilha(node** pilha);
int Incializar_pilha_vazia(node** pilha);
int Inserir_topo(node** pilha, int dado);
int Remover_topo(node** Pilha);
int Obter_topo(node** pilha, int* info);
int Verifica_vazio(node** pilha);

int main(int argc, char* argv[]){

    node* P;
    printf("%d\n", Inicializar_pilha(&P));
    printf("%d\n", Verifica_vazio(&P));

    return 0;
};

int Inicializar_pilha(node** pilha){
    *pilha = NULL;
    return 0;
};

int Inicializar_pilha_vazia(node** pilha){
    node* aux1;
    while((*pilha)->prox != NULL){
        aux1 = (*pilha)->prox;
        free(*pilha);
        *pilha = aux1;
    }
    free(*pilha);
    Inicializar_pilha(pilha);
    return 0;
};

int Inserir_topo(node** pilha, int dado){
    node* aux = (node*)malloc(sizeof(node));
    if(aux == NULL){
        printf("Error alocating node\n");
        return 1;
    }
    aux->dado = dado;
    aux->prox = *pilha;
    *pilha = aux;
    return 0;
}

int Remover_topo(node** pilha){
    node* aux = (*pilha)->prox;
    free(*pilha);
    *pilha = aux;
    return 0;
};

int Obter_topo(node** pilha, int* info){
    if(Verifica_vazio(pilha))
        return 1;
    *info = (*pilha)->dado;
    return 0;
};

int Verifica_vazio(node** pilha){
    if(*pilha == NULL){
        return 1;
    }
    return 0;
};