#include <stdio.h>
#include <stdlib.h>

typedef struct Tnode{
    int info;
    struct Tnode* next;
} node;

int Inicialize_stack(node** stack);
int Reinicialize_stack(node** stack);
int Insert(node** stack, int info);
int Remove(node** stack);
int getTop(node** stack, int* info);
int isEmpty(node** stack);

int Merge(node** stack1, node** stack2);
int getBiggest(node** stack, int* biggest);

int generateRandom(node** stack, int size);
int getInfo(node** stack, int* info, int index);

int freeStack(node** stack);