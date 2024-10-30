#include <stdio.h>
#include <stdlib.h> 
#include "../DinamicVector/DinamicVector.h"

typedef struct Tnode {
    struct Tnode *dad, *right, *left;
    int info;
    int references;
} node;

int printTreeInOrdem(node* root);
int printTreePreOrdem(node* root);
int printTreePostOrdem(node* root);
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

int printTreeInOrdem(node* root){
    vetor* list = createvetor();
    list = searchInOrdem(&root, &list);
    printvetor(list);
    return 0;
};

int printTreePreOrdem(node* root){
    vetor* list = createvetor();
    list = searchPreOrdem(&root, &list);
    printvetor(list);
    return 0;
};

int printTreePostOrdem(node* root){

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

vetor* searchInOrdem(node** root, vetor** list){
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

vetor* searchPreOrdem(node** root, vetor** list){
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

vetor* searchPostOrdem(node** root, vetor** list){
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