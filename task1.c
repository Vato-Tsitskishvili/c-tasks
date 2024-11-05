#include <stdio.h>

void findAllOdds(int matrixSize, int matrixElementSize, int matrix[matrixSize][matrixElementSize]);

int main() {

    int matrix[4][4] = {
        {1, 7, 3, 6},
        {5, 4, 3, 3},
        {4, 7, 9, 11},
        {5, 9, 8, 21}
    };
    
    int matrixSize = sizeof(matrix) / sizeof(matrix[0]);
    int matrixElementSize = sizeof(matrix[0]) / sizeof(matrix[0][0]);

    findAllOdds(matrixSize, matrixElementSize, matrix);

    for (int i = 0; i < matrixSize; i++) {
        for ( int j = 0; j < matrixElementSize; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}

void findAllOdds(int matrixSize, int matrixElementSize, int matrix[matrixSize][matrixElementSize]) {
    int diagI = 0, diagJ = 0;

    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixElementSize; j++) {
            if (matrix[i][j] % 2 == 0) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[diagI][diagJ];
                matrix[diagI][diagJ] = temp;
                diagI++;
                diagJ++;
                break;
            }
        }
    }
}