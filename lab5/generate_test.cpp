#include <bits/stdc++.h>
using namespace std;
/* Ho Sy The - 20200614 */
vector<vector<bool> > mark;

int random(int L, int H){
	return (rand()<<16|rand()) % (H-L+1) + L;
}

int main(int argc, char** argv){
    int id = atoi(argv[1]);
    int n = random(2, min(id * 2, 20));
    int m = random(n, n * n - n);
    mark.assign(n + 1, vector<bool> (n + 1, false));
    for(int i = 1; i <= n; i++) mark[i][i] = true;
	if (argc > 1) srand(atoi(argv[1]));
    else srand(time(NULL));
	freopen("TSP.inp", "w", stdout);

    cout << n << " " << m << '\n';

    for(int i = 0, x, y; i < m; i++) {
        do {
        x = random(1, n);
        y = random(1, n);
        } while(mark[x][y]);
        mark[x][y] = true;
        
        int bounded = 1000000;

        if(n < 13) bounded = 10000;
        if(n < 6) bounded = 50;

        cout << x << ' ' << y << ' ' << random (1, bounded) << '\n';
    }
    return 0;
}