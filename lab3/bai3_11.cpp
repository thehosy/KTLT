#include <bits/stdc++.h>
using namespace std;
// Ho Sy The - 20200614
int n, r;
int cost[1001][1001];
int vertexes[1001];
int x[1001];
bool visited[1001];
int arr_size;
long long temp;
long long ans;
const long long BOUND = 1LL << 20;

void str_to_int_array(string &s) {
    arr_size = -1;
    stringstream ss(s);
    int num;
    while (ss >> num) {
        vertexes[++arr_size] = num;
    }
}

bool feasible(int k, int i) {
    if(visited[vertexes[i]]) return false;
    if(cost[x[k - 1]][vertexes[i]] == 0) return false;
    return true;
}

void solve(int k) {
    for(int i = 1; i < arr_size; i++) {
        if(feasible(k, i)) {
            visited[vertexes[i]] = true;
            x[k] = vertexes[i];
            temp += cost[x[k - 1]][x[k]];
            
            if(k == arr_size - 1) {
                if(cost[x[k]][vertexes[arr_size]])
                    ans = min(ans, temp + cost[x[k]][vertexes[arr_size]]);
            } else solve(k + 1);
            temp -= cost[x[k - 1]][x[k]];
            visited[vertexes[i]] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cout << "\nHo Sy The - 20200614\n\n";
    string s;

    cin >> n >> r;

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j)
            cin >> cost[i][j];
    }

    getline(cin, s);

    while(r--) {
        getline(cin, s);
        str_to_int_array(s);

        for(int i = 1; i <= n; i++) 
            visited[i] = false;

        ans = BOUND;
        temp = 0;

        x[0] = vertexes[0];

        solve(1);

        cout << ((ans == BOUND)? 0 : ans) << '\n';
    }
    return 0; 
}

/* ----------------------------------------------------------------

6 3
0 1 2 0 1 1
1 0 1 1 1 0
0 2 0 1 3 0
4 3 1 0 0 0
0 0 1 1 0 0
1 0 0 0 0 0
1 3 5
6 3 2 5
6 1 2 3 4 5

*/
