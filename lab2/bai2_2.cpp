#include <stdio.h>

// Ho Sy The - 20200614
// pass by reference
void rotate(int &x, int &y, int &z) {
    int a = x, b = y, c = z;
    x = b;
    y = c;
    z = a;
}

int main() {
    int x, y, z;
    // input
    scanf("%d%d%d", &x, &y, &z);
    
    printf("Before: %d, %d, %d\n", x, y, z);
    // circle permutation
    rotate(x, y, z);
    // output
    printf("After: %d, %d, %d\n", x, y, z);
    
    return 0;
}

