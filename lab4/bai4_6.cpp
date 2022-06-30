#include <bits/stdc++.h>

using namespace std;

void bfs(vector< list<int> > adj) {
    queue<int> Q;
    vector<bool> visited(adj.size());
    Q.push(1); // Bắt đầu từ đỉnh số 1
    
    /*****************/
    visited[1] = true;

    while(!Q.empty()) {
        int u = Q.front();
        Q.pop();

        cout << u << ' ';

        for(const int &v: adj[u]) {
            if(!visited[v]) {
                Q.push(v);
                visited[v] = true;
            }
        }
    }
    /*****************/
}

int main() {
    cout << "Ho Sy The - 20200614\n";

    int n, m;
    cin >> n >> m;
    vector< list<int> > adj(n + 1);

    for(int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bfs(adj);

    return 0;
}