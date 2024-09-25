#include <stdio.h>
#include <stdlib.h>

typedef struct Tnode{
    int info;
    struct Tnode* next;
} node;

int Inicializar_pilha(node** pilha);
int Incializar_pilha_vazia(node** pilha);
int Inserir_topo(node** pilha, int info);
int Remover_topo(node** Pilha);
int Obter_topo(node** pilha, int* info);
int Verifica_vazio(node** pilha);

int Juntar_pilhas(node** pilha1, node** pilha2);
int Obter_maior(node** pilha, int* maior);