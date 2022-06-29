#include <stdio.h>
#include <stdlib.h>

// Ho Sy The - 20200614

int main() {
    int **matrix;
    int m, n; // dim of matrix
    int ans = 0; // sum of even elements in matrix
    int t; // input
    printf("Enter m, n = ");
    scanf("%d %d", &m, &n);

    matrix = (int**)calloc(m, sizeof(int*));
    for(int i = 0; i < m; ++i) {
        *(matrix + i) = (int*)calloc(n, sizeof(int));
    }

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            printf("mt[%d][%d] = ", i, j);
            scanf("%d", &t);
            *(*(matrix + i) + j) = t;
            if((t & 1) == 0) ans += t;
        }
    }
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", *(*(matrix + i) + j));
        }
        printf("\n");
    }
    printf("The sum of all even elements is %d", ans);
    
    //free
    for(int i = 0; i < m; i++) {
        free(*(matrix + i));
    }
    free(matrix);

    return 0;
}