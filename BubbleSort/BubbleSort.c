#include <stdio.h>
#include <stdlib.h>

#define INCREMENT 8

typedef struct {
    int* vector;
    int size;
    int lastNumIndex;
} vector;

int push_back(vector* list);
int pop(vector* list);
int generateRandom(vector* list);
int sort(vector* list);
vector* createVector();
int exitSafe(vector* list);
int printVector(vector* list);

int main(int argc, char* arv[]){
    vector* list = createVector();

    int option;
    int error = 0;

    while(1){
        printf("\nWhat do you want to do?\n"); 
        printf("\n1) Exit");  
        printf("\n2) Generate Random Numbers");
        printf("\n3) Insert New Number");
        printf("\n4) Remove Number");
        printf("\n5) Print list");
        printf("\n\n");
        printf("");
        scanf("%d", &option);
        
        switch(option){
            case 1:
                exit(0);
                return 0;
            case 2:
                error = generateRandom(list);
                break;
            case 3:
                error = push_back(list);
                break;
            case 4:
                error = pop(list);
                break;
            case 5:
                error = printVector(list);
                break;
            default:
                printf("Invalid input try! Try again!\n");
        }

        if(error != 0){
            printf("Exiting on error state: %d\n", error);
            exit(1);
        }
    }
    return 0;
}

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

int push_back(vector* list){
    int number;
    printf("\nWhat number to insert?\n");
    scanf("%d", &number);

    if(list->size == list->lastNumIndex){
        list->vector = (int*)reallocarray(list->vector, list->size*2, sizeof(int));
        if(list->vector == NULL){
            printf("Error realocating memory\n");
            return 2;
        }

        list->size *= 2;
    }
    list->vector[list->lastNumIndex+1] = number;
    list->lastNumIndex++;

    return 0;
}

int generateRandom(vector* list){
    return 0;
}

int pop(vector* list){
    return 0;
}

int sort(vector* list){
    return 0;
}

int printVector(vector* list){
    printf("\n");
    for(int index = 0; index < list->lastNumIndex+1; index++){
        printf("%d ", list->vector[index]);
    }
    printf("\n");
    return 0;
}