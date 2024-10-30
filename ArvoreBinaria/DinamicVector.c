#include "DinamicVector.h"

vetor* createvetor(){
    vetor* list = (vetor*)malloc(sizeof(vetor));
    if(list == NULL){
        printf("Error alocating memory\n");
        return NULL;
    };

    list->vetor = (int*)malloc(INCREMENT*sizeof(int));
    if(list->vetor == NULL){
        free(list);
        printf("Error alocating memory\n");
        return NULL;
    }

    list->size = INCREMENT;
    list->lastNumIndex = -1;

    return list;
}

int push_back(vetor* list, int* number){
    int info;
    if(number == NULL){
        printf("\nWhat number to insert?\n");
        scanf("%d", &info);
    }
    else {
        info = *number;
    }

    if(list->size == list->lastNumIndex+1){
        list->vetor = (int*)reallocarray(list->vetor, (list->size)+(INCREMENT), sizeof(int));
        if(list->vetor == NULL){
            printf("Error realocating memory\n");
            return 2;
        }

        list->size += INCREMENT;
    }
    list->vetor[list->lastNumIndex+1] = info;
    list->lastNumIndex++;

    return 0;
}

int pop(vetor* list){
    if(list->lastNumIndex == -1){
        printf("Empty list\n");
        return 0;
    }
    printf("Where to remove? (index)\n");
    int index;
    while(1){
        scanf("%d", &index);
        if(index > list->lastNumIndex){
            printf("No number in list with index %d, try again: \n", index);
        } else {
            break;
        }
    }
    int next;

    for(int indexlist = index; indexlist <= list->lastNumIndex; indexlist++, index++){
        if(list->lastNumIndex != 0 && indexlist != list->lastNumIndex){
            next = list->vetor[indexlist+1];
            list->vetor[indexlist] = next;
        }
    }
    list->lastNumIndex--;

    if(list->lastNumIndex < (list->size/2)){
        list->vetor = (int*)reallocarray(list->vetor, list->size/2, sizeof(int));
        if(list->vetor == NULL){
            printf("Error realocating memory\n");
            return 2;
        }

        list->size /= 2;
    }
    
    return 0;
}

int printvetor(vetor* list){
    printf("\n");
    for(int index = 0; index < list->lastNumIndex+1; index++){
        printf("[%d] ", list->vetor[index]);
    }
    printf("\n");
    return 0;
}

int clean(vetor* list){
    
    free(list->vetor);

    list->vetor = (int*)malloc(INCREMENT*sizeof(int));
    if(list->vetor == NULL){
        free(list);
        printf("Error alocating memory\n");
        return 1;
    }

    list->size = INCREMENT;
    list->lastNumIndex = -1;

    return 0;

}