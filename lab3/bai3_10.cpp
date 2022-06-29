#include <bits/stdc++.h>
using namespace std;
// Ho Sy The - 20200614
int t, n, h;
int x[20];

bool check(int k, int i) {
    if(h == 0) return i == 0;
    int rest = n - k + 1;
    if(rest > h) return true;
    if (rest == h) return i == 1;
    return false;
}

void solve(int k) {
    for(int i = 0; i < 2; i++) {
        if(check(k, i)) {
            x[k] = i;
            if(i == 1) --h;
            if(k == n) {
                for(int j = 1; j <= n; ++j)
                    cout << x[j];
                cout << '\n';
            } else solve(k + 1);
            if(i) ++h;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cout << "\nHo Sy The - 20200614\n\n";
    cin >> t;

    while(t--) {
        cin >> n >> h;
        solve(1);
    }

    return 0;
}
