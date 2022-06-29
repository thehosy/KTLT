#include <bits/stdc++.h>
using namespace std;
// Ho Sy The - 20200614
int n, k, m, ans = 0;
vector<int> e[32];
bool visited[32];

void dfs(int s, int ps, int edges) {
    if(edges == k) {
        ans++;
        return;
    } 
    for(int i = 0; i < e[s].size(); i++) {
        int u = e[s][i];
        if(!visited[u]) {
            visited[u] = true;
            dfs(u, s, edges + 1);
            visited[u] = false;
        }
    }
}

int main() {
    cout << "\nHo Sy The - 20200614\n\n";
    cin >> n >> k >> m;
    for(int i = 0, u, v; i < m; ++i) {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    } 
    for(int i = 1; i <= n; i++) {
        visited[i] = true;
        dfs(i, -1, 0);
        visited[i] = false;
    }
    cout << (ans >> 1);
    return 0;
}
