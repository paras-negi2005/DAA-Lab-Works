#include <stdio.h>

// Function to input a matrix
void inputMatrix(int rows, int cols, int matrix[rows][cols], char name) {
    printf("Enter elements of Matrix %c (%d x %d):\n", name, rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to print a matrix
void printMatrix(int rows, int cols, int matrix[rows][cols], char name) {
    printf("Matrix %c (%d x %d):\n", name, rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rowsA, colsA, rowsB, colsB;
    long long multiplicationCount = 0;
    long long additionCount = 0;

    // Input dimensions
    printf("Enter rows and columns for Matrix A: ");
    scanf("%d %d", &rowsA, &colsA);

    printf("Enter rows and columns for Matrix B: ");
    scanf("%d %d", &rowsB, &colsB);

    // Check if multiplication is possible
    if (colsA != rowsB) {
        printf("Matrix multiplication not possible! Columns of A must equal rows of B.\n");
        return 1;
    }

    int A[rowsA][colsA];
    int B[rowsB][colsB];
    int C[rowsA][colsB]; // Result matrix

    // Input matrices
    inputMatrix(rowsA, colsA, A, 'A');
    inputMatrix(rowsB, colsB, B, 'B');

    // Initialize result matrix C to 0
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            C[i][j] = 0;
        }
    }

    // Perform matrix multiplication and count operations
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            for (int k = 0; k < colsA; k++) {
                multiplicationCount++;
                additionCount++;
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // Print the matrices
    printMatrix(rowsA, colsA, A, 'A');
    printMatrix(rowsB, colsB, B, 'B');
    printMatrix(rowsA, colsB, C, 'C');

    // Print the operation counts
    printf("Total number of multiplication operations: %lld\n", multiplicationCount);
    printf("Total number of addition operations: %lld\n", additionCount);

    return 0;
}
