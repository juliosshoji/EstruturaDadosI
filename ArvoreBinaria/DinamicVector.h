#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define INCREMENT 8

typedef struct {
    int* vetor;
    long int size;
    long int lastNumIndex;
} vetor;

int push_back(vetor* list, int* number);
int pop(vetor* list);
vetor* createvetor();
int printvetor(vetor* list);
int clean(vetor* list);