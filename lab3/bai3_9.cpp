#include <bits/stdc++.h>
using namespace std;
// Ho Sy The - 20200614
int n, k1, k2;
int pos0 = 0; // pos0 la vi tri phan tu 0 cuoi cung
int x[207];

bool feasible(int i, int k) {
    if(k == 1) return true;
    if(x[k - 1] + i == 0) return false;
    int r = k - pos0;
    if(i) {
        if(r <= k2) return true;
    } else {
        --r;
        if(r >= k1) return true;
    }
    return false;
}

void printSol() {
    for(int i = 1; i <= n; ++i) {
        cout << x[i];
    }
    cout << '\n';
}

void solve(int k) {
    for(int i = 0; i < 2; ++i) {
        if(feasible(i, k)) {
            int temp;
            x[k] = i;
            if(!i) {
                temp = pos0;
                pos0 = k;
            }
            if(k == n) {
                if(i == 0 || (n - pos0 >= k1 && n - pos0 <= k2))
                    printSol();
            }
            else solve(k + 1);

            if(!i) {
                pos0 = temp;
            }
        }
    }
}

int main() {
    cout << "\\Ho Sy The - 20200614\n\n";
    cin >> n >> k1 >> k2;
    solve(1);
    return 0;
}
