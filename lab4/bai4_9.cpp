#include <iostream>
#include <queue>
#include <climits>
using namespace std;
// Ho Sy The - 20200614
auto const prior = [] (const pair<int, int> &a, const pair<int, int> &b) -> bool {
    return a.second > b.second;
};

vector<int> dijkstra(const vector< vector< pair<int, int> > >&adj) {
    /*****************/
    priority_queue<pair<int, int>, vector<pair<int, int> >, decltype(prior)> pq(prior);
    int n = adj.size();
    vector<bool> isFixed(n, false);
    vector<int> dist(n, INT_MAX);

    int k = 0;
    dist[0] = 0;
    pq.push({0, 0});
    while(k++ < n) {
	int s = pq.top().first;
	pq.pop();
	
	isFixed[s] = true;
	for(auto i: adj[s]) {
	    if(!isFixed[i.first]) {
		if(dist[i.first] > dist[s] + i.second) {
		    dist[i.first] = dist[s] + i.second;
		    pq.push({i.first, dist[i.first]});
		}
    	    }
        }

    }
    return dist;
    /*****************/
}

int main() {
    cout << "Ho Sy The - 20200614\n";
    
    int n = 9;
    vector< vector< pair<int, int> > > adj(n);
    auto add_edge = [&adj] (int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    };

    add_edge(0, 1, 4);
    add_edge(0, 7, 8);
    add_edge(1, 7, 11);
    add_edge(1, 2, 8);
    add_edge(2, 3, 7);
    add_edge(2, 8, 2);
    add_edge(3, 4, 9);
    add_edge(3, 5, 14);
    add_edge(4, 5, 10);
    add_edge(5, 6, 2);
    add_edge(6, 7, 1);
    add_edge(6, 8, 6);
    add_edge(7, 8, 7);

    vector<int> distance = dijkstra(adj);
    for (int i = 0; i < distance.size(); ++i) {
        cout << "distance " << 0 << "->" << i << " = " << distance[i] << endl;
    }

    return 0;
}