#include <stdio.h>
#include <stdlib.h> 
#include "../DinamicVector/DinamicVector.h"

typedef struct Tnode {
    struct Tnode *dad, *right, *left;
    int info;
    int references;
} node;

int printTree(node* root);
int inicializeTree(node** root);
int insertNode(node** root, int* info, node* dad);
int removeNode(node** root, int* info);
int balanceTree(node** root);
int generateRandom(node** random, int size);
int removeNodeCaseOne(node** rNode);
int removeNodeCaseTwo(node** rNode);
int removeNodeCaseThree(node** rNode);
node* goAllLeft(node** rNode);
vector* searchInOrdem(node** root, vector** list);
vector* searchPreOrdem(node** root, vector** list);
vector* searchPostOrdem(node** root, vector** list);

int main(int argc, char* argv[]){

    node* root;
    inicializeTree(&root);

    int option;
    int condition = 1;
    int info;

    while(condition){
        printf("B-Tree\n");
        printf("\n1) Exit");
        printf("\n2) Insert Node");
        printf("\n3) Remove Node");
        printf("\n4) Balance Tree");
        printf("\n5) Print Tree");
        printf("\n6) Generate Random Numbers");
        printf("\n");

        scanf("%d", &option);

        switch (option)
        {
        case 1:
            exit(0);
            break;
        case 2:
            printf("\nWhat info to store?\n");
            scanf("%d", &info);
            insertNode(&root, &info, NULL);
            break;
        case 3:
            printf("\nWhat info to remove?\n");
            scanf("%d", &info);
            removeNode(&root, &info);
            break;
        case 4:
            balanceTree(&root);
            printf("\nBalanced!\n");
            break;
        case 5:
            printTree(root);
            break;
        case 6:
            printf("How many info to generate?\n");
            scanf("%d", &info);
            generateRandom(&root, info);
            break;
        default:
            printf("\nPlease input a valid option!\n");
            break;
        }

    }

    return 0;
}

int printTree(node* root){
    vector* list = createVector();
    int option;
    int condition = 1;
    while(condition){
        printf("\n\n1) Exit");
        printf("\n2) Print in ordem");
        printf("\n3) Print in Pre-Ordem");
        printf("\n4) Print in Post-Ordem");
        printf("\n");

        scanf("%d", &option);

        switch(option){
            case 1:
                return 0;
            case 2:
                list = searchInOrdem(&root, &list);
                condition = 0;
                break;
            case 3:
                list = searchPreOrdem(&root, &list);
                condition = 0;
                break;
            case 4:
                list = searchPostOrdem(&root, &list);
                condition = 0;
                break;
            default:
                printf("Input a valid option\n");
        }
    }
    printVector(list);

    return 0;
};

int inicializeTree(node** root){
    *root = NULL;
    return 0;
}

int insertNode(node** root, int* info, node* dad){
    node** run = root;
    if(*run == NULL){
        *run = (node*)malloc(sizeof(node));
        if(*root == NULL){
            exit(1);
        }

        (*run)->info = *info;

        (*run)->left = NULL;
        (*run)->right = NULL;
        (*run)->dad = dad;

        return 0;
    }
    if((*run)->info > *info){
        insertNode(&(*run)->left, info, *run);
        return 0;
    }
    if((*run)->info < *info){
        insertNode(&(*run)->right, info, *run);
        return 0;
    }
    if((*run)->info == *info){
        (*run)->references++;
        return 0;
    }
};

int removeNode(node** root, int* info){
    node* run = (*root);
    if(run == NULL){
        printf("Root Empty\n");
        return 0;
    }
    if(run->info == *info){
        if(run->references > 1){
            run->references--;
            return 0;
        }
        if(run->left == NULL && run->right == NULL){
            removeNodeCaseOne(&run);
        } else {
            if((run->left != NULL && run->right == NULL)||(run->left == NULL && run->right != NULL)){
                removeNodeCaseTwo(&run);
            } else {
                if(run->left != NULL && run->right != NULL){
                    removeNodeCaseThree(&run);
                }
            }
        }
    }
    if(run->left != NULL && *info < run->info){
        removeNode(&run->left, info);
    }
    if(run->right != NULL && *info > run->info){
        removeNode(&run->right, info);
    }
    return 0;
};

int balanceTree(node** root){};

int generateRandom(node** root, int size){
    int info;
    for(int index = 0; index < size; index++){
        info = M + rand() / (RAND_MAX / (N - M + 1) + 1);
        insertNode(root, &info , NULL);
    }
    return 0;
};

int removeNodeCaseOne(node** rNode){
    if((*rNode)->dad->right == (*rNode)){
        (*rNode)->dad->right = NULL;
        free((*rNode));
        return 0;
    }
    if((*rNode)->dad->left == (*rNode)){
        (*rNode)->dad->left = NULL;
        free((*rNode));
        return 0;
    }
    return 1;
};

int removeNodeCaseTwo(node** rNode){
    node* son;
    if((*rNode)->left != NULL){
        son = (*rNode)->left;
    }
    if((*rNode)->right != NULL){
        son = (*rNode)->right;
    }
    if((*rNode)->dad->right == (*rNode)){
        (*rNode)->dad->right = son;
        free((*rNode));
        return 0;
    }
    if((*rNode)->dad->left == (*rNode)){
        (*rNode)->dad->left = son;
        free((*rNode));
        return 0;
    }
    return 1;
};

int removeNodeCaseThree(node** rNode){
    node* run = (*rNode)->right;
    
    run = goAllLeft(&run);
    
    (*rNode)->info = run->info;
    (*rNode)->references = run->references;
    
    
    if(run->left != NULL || run->right != NULL){
        removeNodeCaseTwo(&run);
    } else {
        if(run->left == NULL && run->right == NULL){
            removeNodeCaseOne(&run);
        }
    }
};

node* goAllLeft(node** rNode){

    if((*rNode)->left == NULL){
        return (*rNode);
    }

    return goAllLeft(&(*rNode)->left);
};

vector* searchInOrdem(node** root, vector** list){
    node* run = (*root);
    if(run == NULL){
        printf("Root Empty\n");
        return NULL;
    }
    if(run->left != NULL){
        searchInOrdem(&run->left, list);
    }
    push_back((*list), &run->info);
    if(run->right != NULL){
        searchInOrdem(&run->right, list);
    }
    return *list;
};

vector* searchPreOrdem(node** root, vector** list){
    node* run = (*root);
    if(run == NULL){
        printf("Root Empty\n");
        return NULL;
    }
    push_back((*list), &run->info);
    if(run->left != NULL){
        searchPreOrdem(&run->left, list);
    }
    if(run->right != NULL){
        searchPreOrdem(&run->right, list);
    }
    return *list;
};

vector* searchPostOrdem(node** root, vector** list){
    node* run = (*root);
    if(run == NULL){
        printf("Root Empty\n");
        return NULL;
    }
    if(run->left != NULL){
        searchPostOrdem(&run->left, list);
    }
    if(run->right != NULL){
        searchPostOrdem(&run->right, list);
    }
    push_back((*list), &run->info);
    return *list;
}