#include <stdio.h>

// Ho Sy The - 20200614

int cube(int x) {
    //# trả về lập phương của x
    return x * x * x;
}

//# viết hàm tính lập phương của một số kiểu double
double cube(double x) {
    return x * x * x;
}

int main() {
    int n;
    double f;
    // input n and f
    scanf("%d %lf", &n, &f);
    
    // get n^3:
    printf("Int: %d\n", cube(n));
    // get f^3
    printf("Double: %.2lf\n", cube(f));
    
    return 0;
}

