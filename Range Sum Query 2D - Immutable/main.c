#include <stdio.h>
#include <stdlib.h>

struct NumMatrix {
    int **sumMatrix;
    int matrixRowSize;
};

/** Initialize your data structure here. */
struct NumMatrix* NumMatrixCreate(int** matrix, int matrixRowSize, int matrixColSize) {
    if(!matrixRowSize||!matrixColSize) return 0;

    int i,j;
    struct NumMatrix *numMatrix = (struct NumMatrix*)calloc(1,sizeof(struct NumMatrix));
    numMatrix->sumMatrix = (int**)calloc(matrixRowSize,sizeof(int*));
    numMatrix->matrixRowSize = matrixRowSize;
    for(i=0;i<matrixRowSize;i++) {
        (numMatrix->sumMatrix)[i] = (int*)calloc(matrixColSize,sizeof(int));
    }

    (numMatrix->sumMatrix)[0][0] = matrix[0][0];
    for(i=1;i<matrixRowSize;i++) {
        numMatrix->sumMatrix[i][0] = numMatrix->sumMatrix[i-1][0]+matrix[i][0];printf("%d\n",matrix[i][0]);
    }
    for(j=1;j<matrixColSize;j++) {
        numMatrix->sumMatrix[0][j] = numMatrix->sumMatrix[0][j-1]+matrix[0][j];printf("%d\n",matrix[0][j]);
    }
    for(i=1;i<matrixRowSize;i++) {
        for(j=1;j<matrixColSize;j++) {
            numMatrix->sumMatrix[i][j] = matrix[i][j]
                +numMatrix->sumMatrix[i][j-1]+numMatrix->sumMatrix[i-1][j]
                -numMatrix->sumMatrix[i-1][j-1];printf("%d\n",matrix[i][j]);
        }
    }

    return numMatrix;
}

int sumRegion(struct NumMatrix* numMatrix, int row1, int col1, int row2, int col2) {
    int **A = numMatrix->sumMatrix;
    return (A[row2][col2]
        - (col1?A[row2][col1-1]:0)
        - (row1?A[row1-1][col2]:0)
        + ((row1&&col2)?A[row1-1][col1-1]:0));
}

/** Deallocates memory previously allocated for the data structure. */
void NumMatrixFree(struct NumMatrix* numMatrix) {
    int i;
    for(i=0;i<numMatrix->matrixRowSize;i++) {
        free((void *)numMatrix->sumMatrix[i]);
    }
    free((void *)numMatrix->sumMatrix);
    free((void *)numMatrix);
}

int main()
{
    printf("Hello world!\n");

    // Your NumMatrix object will be instantiated and called as such:
    int matrix[4][4] = {{1,2,3,4},{5,6,7,8},{1,2,3,4},{1,2,3,4}};
    struct NumMatrix* numMatrix = NumMatrixCreate(matrix, 4, 4);
    sumRegion(numMatrix, 0, 1, 2, 3);
    sumRegion(numMatrix, 1, 2, 3, 4);
    NumMatrixFree(numMatrix);

    return 0;
}
