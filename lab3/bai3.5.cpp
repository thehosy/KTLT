#include <iostream>
using namespace std;

// Ho Sy The - 20200614

int binom(int n, int k) {
    if (k > n) return 0;
    if (k == 0) return 1;
    return binom(n-1, k) + binom(n-1, k-1);
}

int binom2(int n, int k){
    if (k == 0 || k == n) return 1;
    k = min(k, n - k);
    long long res = 1LL;
    for(int i = 1; i <= k; n--, i++) {
        res = res * n / i;
    }
    return (int) res;
}

int main() {
    int m;
    cin >> m;
    for (int n = 1; n <= m; ++n){
        for (int k = 0; k <= n; ++k)
            printf("%d ", binom(n, k));
        printf("\n");
    }
    for (int n = 1; n <= m; ++n){
        for (int k = 0; k <= n; ++k)
            printf("%d ", binom2(n, k));
        printf("\n");
    }
    return 0;
}