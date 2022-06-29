#include <bits/stdc++.h>
using namespace std;
// Ho Sy The - 20200614
struct state{
    int i, j, sum; // i so lan can, j: +, -
    state(int _i = 0, int _j = 0, int _sum = 0): i(_i), j(_j), sum(_sum) {}
};

int main() {
    cout << "\n\nHo Sy The - 20200614\n\n";
    int n, M;
    cin >> n >> M;
    int m[n+1];
    for (int i = 1; i <= n; ++i) cin >> m[i];
    int x[n+1];
    stack<state> s;
    //# sum of selected weights
    s.push(state(0));
    while (!s.empty()){
        state top = s.top();
        s.pop();
        if (top.i > n){
            if (top.sum == M){
                for (int i = 1; i <= n; ++i){
                    if (x[i] == -1) cout << '-' << m[i];
                    if (x[i] == 1) cout << '+' << m[i];
                }
                cout << "=" << M;
                exit(0);
            }
            continue;
        }
        //# Khử đệ quy
        s.push(state(top.i + 1, -1, top.sum - m[top.i + 1]));
        s.push(state(top.i + 1, 0, top.sum));
        s.push(state(top.i + 1, 1, top.sum + m[top.i + 1]));
        x[top.i] = top.j;
    }
    cout << -1;
    return 0;
}