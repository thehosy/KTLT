#include <stdio.h>
#include <math.h>

// Ho Sy The - 20200614

float get_hypotenuse(float x, float y) {
    return sqrt(x * x + y * y);
}

int main(){
    float x, y;
    // input
    scanf("%f%f", &x, &y);
    // calculate the hypotenuse  
    float z = get_hypotenuse(x, y);
    // output
    printf("z = %.2f\n", z);
    
    return 0;
}


