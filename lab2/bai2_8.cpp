#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

// Ho Sy The - 20200614

using namespace std;

int main() {
    int val1, val2;
    cin >> val1 >> val2;
    vector< vector<int> > a = {
        {1, 3, 7},
        {2, 3, 4, val1},
        {9, 8, 15},
        {10, val2},
    };
    // inline void std::sort(begin iterator, end iterator, compare function -> bool)
    // so define comapre function by using lambda expression 
    sort(a.begin(), a.end(), [](const vector<int> &x, const vector<int> &y){
            int sumX = 0;
            for(int i: x) sumX += i;

            int sumY = 0;
            for(int i: y) sumY += i;
	    
            return sumX > sumY;
        });

    for (const auto &v : a) {
        for (int it : v) {
            cout << it << ' ';
        }
        cout << endl;
    }
    return 0;
}

