#include <stdio.h>
#include <stdlib.h>

// Ho Sy The - 20200614

void sort(int *arr, int n) {
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(*(arr + i) > *(arr + j)) {
                int tmp = *(arr + i);
                *(arr + i) = *(arr + j);
                *(arr + j) = tmp;
            }
        }
    }
}

int main() {
    int *arr;
    int n; // size of array arr
    scanf("%d", &n);

    arr = (int *)calloc(n, sizeof(int));
    for(int i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }
    printf("Enter the number of elements: The input array is:\n");
    for(int i = 0; i < n; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\nThe sorted array is:\n");
    sort(arr, n);

    for(int i = 0; i < n; i++) {
        printf("%d ", *(arr + i));
    }
    
    free(arr);

    return 0;
}