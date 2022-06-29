#include <stdio.h>
#include <stdlib.h>
// Ho Sy The - 20200614

int *a, *b;
inline int min(int a, int b) { 
    return (a > b)? b : a; 
}

int main() {
    printf("Ho Sy The - 20200614\n");
    int Na, Nb, ans = 0; // Na: degree of A(x), Nb: degree of B(x)
    /* input coefficient of two polinomials A(x) and B(x) */
    scanf("%d", &Na);
    a = (int *)calloc(Na + 1, sizeof(int));
    for(int i = 0, t = 0; i <= Na; i++) {
        scanf("%d", a + i);
    }
    scanf("%d", &Nb);
    b = (int *)calloc(Nb + 1, sizeof(int));
    for(int i = 0, t = 0; i <= Nb; i++) {
        scanf("%d", b + i);
    }
    /*******/
    for(int i = 0; i <= (Na + Nb); i++) {
        int part = 0;
        for(int j = 0; j <= i; j++) {
            if((j > Na) || (i - j > Nb)) continue;
            part += a[j] * b[i - j];
        }
        ans ^= part;
    }

    printf("%d\n", ans);

    free(a);
    free(b);
    return 0;
}

