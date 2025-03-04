#include "DinamicVector.h"

typedef struct Tnode {
    struct Tnode *dad, *right, *left;
    int info;
    int references;
} node;

int printTreeInOrdem(node** root);
int printTreePreOrdem(node** root);
int printTreePostOrdem(node** root);
int inicializeTree(node** root);
int insertNode(node** root, int* info, node* dad);
int removeNode(node** root, int* info);
int balanceTree(node** root);
int generateRandom(node** random, int size);
int removeNodeCaseOne(node** rNode);
int removeNodeCaseTwo(node** rNode);
int removeNodeCaseThree(node** rNode);
node* goAllLeft(node** rNode);
vetor* searchInOrdem(node** root, vetor** list);
vetor* searchPreOrdem(node** root, vetor** list);
vetor* searchPostOrdem(node** root, vetor** list);
void freeTree(node* root);