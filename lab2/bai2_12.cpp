#include <bits/stdc++.h>

using namespace std;

// Ho Sy The - 20200614
// define Node element with 2 attributes: key and value
struct Node {
    int key, value;
};
vector<Node> v;

int main() {
    int key, value;
    cout << "Ho Sy The - 20200614\n\n";
    freopen("input.txt", "r", stdin);
    // input <key, value>
    while ((cin >> key) and (cin >> value)) {
        v.push_back(Node{key, value});
    }
    // sort using lambda - annonymous function:
    sort(v.begin(), v.end(), [](const Node &a, const Node &b) -> bool { 
        if(a.value != b.value)
            return a.value > b.value;
        return a.key > b.key;
    });

    // print output
    for(Node i: v) {
        cout << i.key << ' ' << i.value << ' ' << '\n';
    }

    return 0;
}

