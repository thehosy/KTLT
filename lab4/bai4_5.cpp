#include <bits/stdc++.h>

using namespace std;

void dfs(vector< list<int> > adj) {
    stack<int> S;
    vector<bool> visited(adj.size(), false);
    S.push(1); // Bắt đầu từ đỉnh số 1
    
    /*****************/
    while(!S.empty()) {
        int u = S.top();

        if(!visited[u]) {
            visited[u] = true;
            cout << u << ' ';
        }

        if(adj[u].empty())
            S.pop();
        else {
            int v = adj[u].front();
            adj[u].pop_front();

            if(!visited[v])
                S.push(v);
        }
    }
    /*****************/
}

int main() {
    cout << "Ho Sy The - 20200614\n";

    int n, m; 
    cin >> n >> m; 

    vector<list<int> > adj(n + 1);

    for(int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(adj);

    return 0;
}

/*
1, 2
2, 3
3, 4
4, 6
1, 5
1, 6
6, 7
5, 7
*/