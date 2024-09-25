#include <stdio.h>

//Pilha dinamica
typedef struct Tnode{
    int dado;
    struct node* prox;
} node;

int Inicializar_pilha(node* pilha);
int Incializar_pilha_vazia(node* pilha);
int Inserir_topo(node* pilha, int dado);
int Remover_topo(node* Pilha);
int Obter_topo(node* pilha);
int Verifica_vazio(node* pilha);

int main(int argc, char* argv[]){



    return 0;
}

int Incializar_pilha(node* pilha){
    pilha = NULL;
    return 0;
}

int Inicializar_pilha_vazia(node* pilha){
    node* aux1;
    while(pilha->prox != NULL){
        aux1 = pilha->prox;
        free(pilha);
        pilha = aux1;
    }
    free(pilha);
    Incializar_pilha(pilha);
    return 0;
}

int Inserir_topo(node* pilha, int dado){
    node* aux = (node*)malloc(sizeof(node));
    if(aux == NULL){
        printf("Error alocating node\n");
        return 1;
    }
    aux->dado = dado;
    aux->prox = pilha;
    pilha = aux;
    return 0;
}
int Remover_topo(node* pilha){
    node* aux = pilha->prox;
    free(pilha);
    pilha = aux;
    return 0;
}