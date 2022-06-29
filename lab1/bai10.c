/**
 * @file: bai10.c
 * @author: Ho Sy The - 20200614
 * @date: 2022-05-13
 * @copyright: Copyright (c) Ho Sy The
 * @description:Viết chương trình nhập vào 2 ma trận vuông cùng kích thước n*n, 
 * trong đó n nhập từ bàn phím. Sau đó tính tổng và tích của hai ma trận đó và 
 * đưa kết quả ra màn hình. Yêu cầu sử dụng cấp phát động để cấp phát bộ nhớ cho các ma trận.
 * 
 */

#include <stdio.h>
#include <stdlib.h>

void alloc_matrix(int*** matrix, int n) {
    *matrix = (int**)calloc(n, sizeof(int*));
    for(int i = 0; i < n; i++) {
        *((*matrix) + i) = (int*)calloc(n, sizeof(int));
    }
}

void printMatrix(int *** matrix, int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", *(*((*matrix) + i) + j));
        }
        printf("\n");
    }
}

int **add(int ***matrixA, int ***matrixB, int n) {
    int **matrixAns;
    alloc_matrix(&matrixAns, n);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            *(*(matrixAns + i) + j) = *(*((*matrixA) + i) + j) + *(*((*matrixB) + i) + j);
        }
    }
    return matrixAns;
}

int **multiply(int ***matrixA, int ***matrixB, int n) {
    int **matrixAns;
    alloc_matrix(&matrixAns, n);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++)
                *(*(matrixAns + i) + j) += *(*((*matrixA) + i) + k) * *(*((*matrixB) + k) + j);
        }
    }
    return matrixAns;
}

void free_memory(int ***matrix, int n) {
    for(int i = 0; i < n; i++) {
        free(*((*matrix) + i));
    }
    free(*matrix);
}

int main() {
    int **matrixA, **matrixB, **matrixAnsOfAddition, **matrixAnsOfProduct;
    int n;
    // printf("Ho Sy The - 20200614\n");
    // printf("Enter size of square matrixes: ");
    scanf("%d", &n);
    alloc_matrix(&matrixA, n);
    alloc_matrix(&matrixB, n);
    // printf("Enter matrix A:\n");

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", *(matrixA + i) + j);
        }
    }

    // printf("Enter matrix B:\n");

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", *(matrixB + i) + j);
        }
    }

    matrixAnsOfAddition = add(&matrixA, &matrixB, n);
    matrixAnsOfProduct = multiply(&matrixA, &matrixB, n);

    // printf("\nA + B = \n");
    printMatrix(&matrixAnsOfAddition, n);
    // printf("\nA * B = \n");
    printMatrix(&matrixAnsOfProduct, n);

    free_memory(&matrixA, n);
    free_memory(&matrixB, n);
    free_memory(&matrixAnsOfAddition, n);
    free_memory(&matrixAnsOfProduct, n);

    return 0;
}