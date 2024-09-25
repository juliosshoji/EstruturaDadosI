#include <stdio.h>
#include <stdlib.h>
#include "pilhaDin.h"

int Inicializar_pilha(node** pilha){
    *pilha = NULL;
    return 0;
};

int Inicializar_pilha_vazia(node** pilha){
    node* percorre = *pilha;
    while(percorre->next != NULL){
        percorre = percorre->next;
        free(*pilha);
        *pilha = percorre;
    }
    free(*pilha);
    Inicializar_pilha(*pilha);
    return 0;
};

int Inserir_topo(node** pilha, int info){
    node* aux = (node*)malloc(sizeof(node));
    if(aux == NULL){
        printf("Error alocating node\n");
        return 1;
    }
    if(*pilha == NULL){
        aux->next = NULL;
    } else {
        aux->next = *pilha;
    }
    aux->info = info;
    *pilha = aux;
    return 0;
}

int Remover_topo(node** pilha){
    node* aux = (*pilha)->next;
    free(*pilha);
    *pilha = aux;
    return 0;
};

int Obter_topo(node** pilha, int* info){
    if(Verifica_vazio(pilha))
        return 1;
    *info = (*pilha)->info;
    return 0;
};

int Verifica_vazio(node** pilha){
    if(*pilha == NULL){
        return 1;
    }
    return 0;
};

//pilha1 vira topo
int Juntar_pilhas(node** pilha1, node** pilha2){
    node* percorre = *pilha1;
    while(percorre->next != NULL){
        percorre = percorre->next;
    }
    percorre->next = *pilha2;
    return 0;
};

int Obter_maior(node** pilha, int* maior){
    node* percorre = *pilha;
    *maior = percorre->info;
    while(percorre->next != NULL){
        percorre = percorre->next;
        if(percorre->info > *maior){
            *maior = percorre->info;
        }
    }
    return 0;
};
