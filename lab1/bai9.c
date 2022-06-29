/**
 * @file: bai9.c
 * @author: Ho Sy The - 20200614
 * @date: 2022-05-13
 * @copyright: Copyright (c) Ho Sy The
 * @description: Viết chương trình in ra tất cả các dãy con của một dãy cho trước.
 * 
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    int * arr;
    int n;
    // printf("Ho Sy The - 20200614\n");
    scanf("%d", &n);

    arr = (int*)calloc(n, sizeof(int));

    for(int i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }

    for(int i = 0; i < n; i++) {
        int range = n - i;
        for(int j = 0; j < range; j++) {
            for(int k = 0; k <= j; k++) {
                printf("%d ", *(arr + i + k));
            }
            printf("\n");
        }
    }

    free(arr);
    return 0;
}