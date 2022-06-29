#include <bits/stdc++.h>
using namespace std;

// Ho Sy The - 20200614

struct state{
    int i, j, old_L;
    //# constructor
    state(int _i = 0, int _j = 0, int _L = 0):
        i(_i), j(_j), old_L(_L){}
};

int main() {
    int n, k;
    cin >> n >> k;
    int x[n+1];
    stack<state> s;
    //# number of consecutive suffix 1
    int L = 0;
    s.push(state(1, 0));
    while (!s.empty()){
        state &top = s.top();
        //# if a new binary sequence is found
        if (top.i > n){
            for (int i = 1; i <= n; ++i)
                cout << x[i] << " \n"[i == n];
            s.pop();
            continue;
        }
        //# Khử đệ quy
        if (top.j == 2) {
            s.pop();
            continue;
        } 
        L = top.j? top.old_L + 1 : 0;
        x[top.i] = top.j;
        if(L < k or top.j == 0){
            s.push(state(top.i + 1, 0, L));
        }
        top.j++;
    }
    return 0;
}
