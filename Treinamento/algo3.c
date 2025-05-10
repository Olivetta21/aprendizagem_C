#include <stdio.h>

void rotateMatrix(int N, int matrix[N][N]) {
    int temp;

    // Transpor a matriz
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
    printf("\nTranspor:\n");
    printMatrix(N, matrix);

    // Inverter as colunas
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N / 2; j++) {
            temp = matrix[i][j];
            matrix[i][j] = matrix[i][N - 1 - j];
            matrix[i][N - 1 - j] = temp;
        }
    }
    printf("\ninvertercoluna: \n");
    printMatrix(N, matrix);
}

void printMatrix(int N, int matrix[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int N = 3; // Tamanho da matriz
    int matrix[N][N];
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            printf("MatA[%d][%d]: ", i+1,i+1);
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("Matriz original:\n");
    printMatrix(N, matrix);

    rotateMatrix(N, matrix);

    printf("\nMatriz girada em 90 graus no sentido horário:\n");
    printMatrix(N, matrix);

    return 0;
}
