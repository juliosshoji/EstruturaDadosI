#include <stdio.h>

typedef struct {
    void* info;
    int row, column;
    node *nextRow, *nextColumn;
} node;

typedef struct {

    node *row, *column;

} matrix;

int main(int argc, char* argv[]){



    return 0;
}

int insertInfo(matrix** myMatrix, int info, int row, int column){

};

int removeInfo(int row, int column){

};

int updateInfo(int info, int row, int column){

};

matrix* createMatrix(int row, int column){

};

matrix* resizeMatrix(int row, int column){

};

int deleteMatrix(matrix* myMatrix){

};