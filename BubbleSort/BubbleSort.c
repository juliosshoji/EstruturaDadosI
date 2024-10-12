#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define INCREMENT 8
#define M -100000
#define N 100000

typedef struct {
    int* vector;
    int size;
    int lastNumIndex;
} vector;

int push_back(vector* list, int* number);
int pop(vector* list);
int generateRandom(vector* list);
int sort(vector* list);
vector* createVector();
int exitSafe(vector* list);
int printVector(vector* list);
int clean(vector* list);

int main(int argc, char* argv[]){

    srand(time(NULL));

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
        printf("\n6) Sort list");
        printf("\n7) Biggest Index");
        printf("\n8) Alocation size");
        printf("\n9) Clean");
        printf("\n\n");
        scanf("%d", &option);
        
        switch(option){
            case 1:
                free(list->vector);
                free(list);
                exit(0);
                return 0;
            case 2:
                error = generateRandom(list);
                break;
            case 3:
                error = push_back(list, NULL);
                break;
            case 4:
                error = pop(list);
                break;
            case 5:
                error = printVector(list);
                break;
            case 6:
                error = sort(list);
                break;
            case 7:
                if(list->lastNumIndex == -1){
                    printf("\nNo index was created\n");
                } else {
                    printf("\nBiggest Index: %d\n", list->lastNumIndex);
                }
                break;
            case 8:
                printf("\nAlocation Size: %d\n", list->size);
                break;
            case 9:
                error = clean(list);
                break;
            default:
                printf("Invalid input try! Try again!\n");
        }

        if(error != 0){
            printf("Exiting on error state: %d\n", error);
            free(list->vector);
            free(list);
            exit(1);
        }
    }
    free(list->vector);
    free(list);
    exit(0);
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
        list->vector = (int*)reallocarray(list->vector, (list->size)*2, sizeof(int));
        if(list->vector == NULL){
            printf("Error realocating memory\n");
            return 2;
        }

        list->size *= 2;
    }
    list->vector[list->lastNumIndex+1] = info;
    list->lastNumIndex++;

    return 0;
}

int generateRandom(vector* list){

    printf("How many number to generate?\n");
    int qtd;
    scanf("%d", &qtd);
    int newNumber;
    while(qtd != 0){
        
        newNumber = M + rand() / (RAND_MAX / (N - M + 1) + 1);
        push_back(list, &newNumber);
        
        qtd--;
    }

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

int sort(vector* list){
    int swapped = 0;
    int temp;
    for(int macro = list->lastNumIndex-1; macro > 0; macro--){
        swapped = 0;
        for(int micro = 0; micro <= macro; micro++){
            if(list->vector[micro] > list->vector[micro + 1]){
                temp = list->vector[micro];
                list->vector[micro] = list->vector[micro + 1];
                list->vector[micro + 1] = temp;
                swapped = 1;
            } 
        }
        if(swapped == 0){
                break;
        }
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