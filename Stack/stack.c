#include "stack.h"

int Inicialize_stack(node** stack){
    *stack = NULL;
    return 0;
};

int Reinicialize_stack(node** stack){
    node* run = *stack;
    while(run->next != NULL){
        run = run->next;
        free(*stack);
        *stack = run;
    }
    free(*stack);
    Inicialize_stack(stack);
    return 0;
};

int Insert(node** stack, int info){
    node* aux = (node*)malloc(sizeof(node));
    if(aux == NULL){
        printf("Error alocating node\n");
        return 1;
    }
    if(*stack == NULL){
        aux->next = NULL;
    } else {
        aux->next = *stack;
    }
    aux->info = info;
    *stack = aux;
    return 0;
}

int Remove(node** stack){
    node* aux = (*stack)->next;
    free(*stack);
    *stack = aux;
    return 0;
};

int getTop(node** stack, int* info){
    if(isEmpty(stack))
        return 1;
    *info = (*stack)->info;
    return 0;
};

int isEmpty(node** stack){
    if(*stack == NULL){
        return 1;
    }
    return 0;
};

//stack1 vira topo
int Merge(node** stack1, node** stack2){
    node* run = *stack1;
    while(run->next != NULL){
        run = run->next;
    }
    run->next = *stack2;
    return 0;
};

int getBiggest(node** stack, int* biggest){
    node* run = *stack;
    *biggest = run->info;
    while(run->next != NULL){
        run = run->next;
        if(run->info > *biggest){
            *biggest = run->info;
        }
    }
    return 0;
};

int generateRandom(node** stack, int size){
    for(int index = 0; index < size; index++){
        Insert(stack, rand());
    }
    return 0;
};

int getInfo(node** stack, int* info, int index){
    node* run = *stack;
    if(*stack == NULL)
        return 1;
    while(run->next != NULL && index != 0){
        run = run->next;
        index--;
    }
    if(run->next == NULL && index != 0)
        return 1;
    *info = run->info;
    return 0;
};

int freeStack(node** stack){
    node* run = *stack; 
    while(run->next != NULL){
        run = (*stack)->next;
        free(*stack);
        *stack = run;
    }
    return 0;
};