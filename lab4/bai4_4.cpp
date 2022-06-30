#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void print_vector(const vector<int> &a) {
    for (int v : a) cout << v << ' ';
    cout << endl;
}

void delete_even(vector<int> &a) {
    /*****************/
    int t = 0;
    int n = a.size();
    for(int i= 0; i < n; i++) {
        if(a[i] & 1) {
            a[t] = a[i];
            t++;
        }
    }

    a.erase(a.begin() + t, a.end());
    /*****************/
}

void sort_decrease(vector<int> &a) {
    /*****************/
    sort(a.begin(), a.end(), [](const int &a1, const int &a2) -> bool {
        return a1 > a2;
    });
    /*****************/
}

vector<int> merge_vectors(const vector<int> &a, const vector<int> &b) {
    /*****************/
    vector<int> ans;
    int i = 0, j = 0;
    int na = a.size(), nb = b.size();
    while(i < na && j < nb) {
        if(a[i] > b[j]){
            ans.push_back(a[i]);
            i++;
        } else {
            ans.push_back(b[j]);
            j++;
        }
    }

    while(i < na) {
        ans.push_back(a[i]);
        i++;
    }

    while(j < nb) {
        ans.push_back(b[j]);
        j++;
    }
    return ans;
    /*****************/
}

int main() {
    cout << "Ho Sy The - 20200614\n";

    int m, n, u;
    std::vector<int> a, b;
    
    std::cin >> m >> n;
    for(int i = 0; i < m; i++){
        std:: cin >> u;
        a.push_back(u);
    }
    for(int i = 0; i < n; i++){
        std:: cin >> u;
        b.push_back(u);
    }

    delete_even(a);
    cout << "Odd elements of a: ";
    print_vector(a);

    delete_even(b);
    cout << "Odd elements of b: ";
    print_vector(b);

    sort_decrease(a);
    cout << "Decreasingly sorted a: ";
    print_vector(a);

    sort_decrease(b);
    cout << "Decreasingly sorted b: ";
    print_vector(b);

    vector<int> c = merge_vectors(a, b);
    cout << "Decreasingly sorted c: ";
    print_vector(c);

    return 0;
}