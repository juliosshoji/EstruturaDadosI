#include "B-Tree.h"

int printTreeInOrdem(node** root){
    vetor* list = createvetor();
    if(list == NULL){
        exit(EXIT_FAILURE);
    }
    if(list->vetor == NULL){
        free(list);
        exit(EXIT_FAILURE);
    }
    list = searchInOrdem(root, &list);
    if(list != NULL){
        printvetor(list);
    }
    return 0;
};

int printTreePreOrdem(node** root){
    vetor* list = createvetor();
    if(list == NULL){
        exit(EXIT_FAILURE);
    }
    if(list->vetor == NULL){
        free(list);
        exit(EXIT_FAILURE);
    }
    list = searchPreOrdem(root, &list);
    if(list != NULL){
        printvetor(list);
    }    
    return 0;
};

int printTreePostOrdem(node** root){
    vetor* list = createvetor();
    if(list == NULL){
        exit(EXIT_FAILURE);
    }
    if(list->vetor == NULL){
        free(list);
        exit(EXIT_FAILURE);
    }
    list = searchPostOrdem(root, &list);
    if(list != NULL){
        printvetor(list);
    }
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
            return 1;
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
    return 1;
};

int removeNode(node** root, int* info){
    if((*root) == NULL){
        printf("Root Empty\n");
        return 0;
    }
    if((*root)->info == *info){
        printf("\nNode found!\n");
        if((*root)->references > 1){
            (*root)->references--;
            return 0;
        }
        if((*root)->left == NULL && (*root)->right == NULL){
            removeNodeCaseOne(root);
        } else {
            if(((*root)->left != NULL && (*root)->right == NULL)||((*root)->left == NULL && (*root)->right != NULL)){
                removeNodeCaseTwo(root);
            } else {
                if((*root)->left != NULL && (*root)->right != NULL){
                    removeNodeCaseThree(root);
                }
            }
        }
        return 0;
    }
    if((*root)->left != NULL && *info < (*root)->info){
        removeNode(&(*root)->left, info);
        return 0;
    }
    if((*root)->right != NULL && *info > (*root)->info){
        removeNode(&(*root)->right, info);
    }
    return 0;
};

int balanceTree(node** root){
    printf("%d\n", (*root)->info);
    return 0;
};

int generateRandom(node** root, int size){
    int info;
    for(int index = 0; index < size; index++){
        info = M + rand() / (RAND_MAX / (N - M + 1) + 1);
        insertNode(root, &info , NULL);
    }
    return 0;
};

int removeNodeCaseOne(node** rNode){
    if((*rNode)->dad == NULL){
        free(*rNode);
        *rNode = NULL;
        return 0;
    }
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

    return 0;
};

node* goAllLeft(node** rNode){

    if((*rNode)->left == NULL){
        return (*rNode);
    }

    return goAllLeft(&(*rNode)->left);
};

vetor* searchInOrdem(node** root, vetor** list){
    node* run = (*root);
    if(*root == NULL){
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
    if(*root == NULL){
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

void freeTree(node* root){
    if(root == NULL){
        printf("Root Empty\n");
        return;
    }
    if(root->left != NULL){
        freeTree(root->left);
    }
    if(root->right != NULL){
        freeTree(root->right);
    }
    free(root);
    return;
};
