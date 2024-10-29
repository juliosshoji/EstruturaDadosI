#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define INCREMENT 8
#define M -100000
#define N 100000

typedef struct {
    int* vector;
    long int size;
    long int lastNumIndex;
} vector;

int push_back(vector* list, int* number);
int pop(vector* list);
vector* createVector();
int exitSafe(vector* list);
int printVector(vector* list);
int clean(vector* list);

vector* createVector(){
    vector* list = (vector*)malloc(sizeof(vector));
    if(list == NULL){
        printf("Error alocating memory\n");
        return NULL;
    };

    list->vector = (int*)malloc(INCREMENT*sizeof(int));
    if(list->vector == NULL){
        free(list);
        printf("Error alocating memory\n");
        return NULL;
    }

    list->size = INCREMENT;
    list->lastNumIndex = -1;

    return list;
}

int push_back(vector* list, int* number){
    int info;
    if(number == NULL){
        printf("\nWhat number to insert?\n");
        scanf("%d", &info);
    }
    else {
        info = *number;
    }

    if(list->size == list->lastNumIndex+1){
        list->vector = (int*)reallocarray(list->vector, (list->size)+(INCREMENT), sizeof(int));
        if(list->vector == NULL){
            printf("Error realocating memory\n");
            return 2;
        }

        list->size += INCREMENT;
    }
    list->vector[list->lastNumIndex+1] = info;
    list->lastNumIndex++;

    return 0;
}

int pop(vector* list){
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
            next = list->vector[indexlist+1];
            list->vector[indexlist] = next;
        }
    }
    list->lastNumIndex--;

    if(list->lastNumIndex < (list->size/2)){
        list->vector = (int*)reallocarray(list->vector, list->size/2, sizeof(int));
        if(list->vector == NULL){
            printf("Error realocating memory\n");
            return 2;
        }

        list->size /= 2;
    }
    
    return 0;
}

int printVector(vector* list){
    printf("\n");
    for(int index = 0; index < list->lastNumIndex+1; index++){
        printf("[%d] ", list->vector[index]);
    }
    printf("\n");
    return 0;
}

int clean(vector* list){
    
    free(list->vector);

    list->vector = (int*)malloc(INCREMENT*sizeof(int));
    if(list->vector == NULL){
        free(list);
        printf("Error alocating memory\n");
        return 1;
    }

    list->size = INCREMENT;
    list->lastNumIndex = -1;

    return 0;

}