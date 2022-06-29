#include <bits/stdc++.h>

using namespace std;

// Ho Sy The - 20200614

int lucas(int n) {
    
    if (n == 0) return 2;
    if (n == 1) return 1;
    return lucas(n - 1) + lucas(n - 2);
}

int main() {

    int n;
    cin >> n;

    cout << lucas(n);

    return 0;
}