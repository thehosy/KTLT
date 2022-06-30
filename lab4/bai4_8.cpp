#include <iostream>
#include <map>

using namespace std;

template<class T>
map<T, double> fuzzy_set_union(const map<T, double> &a, map<T, double> &b) {
    /*****************/
    map<T, double> ans;
    for(auto p: a) {
        if(b.find(p.first) != b.end()) {
            ans[p.first] = max(p.second, b[p.first]);
        } else ans.insert({p.first, p.second});
    }

    for(auto p: b) {
        if(a.find(p.first) == a.end()) {
            ans.insert({p.first, p.second});
        }
    }
    return ans;
    /*****************/
}

template<class T>
map<T, double> fuzzy_set_intersection(const map<T, double> &a, map<T, double> &b) {
    /*****************/
    map<T, double> ans;
    for(auto p: a) {
        if(b.find(p.first) != b.end()) {
            ans[p.first] = min(p.second, b[p.first]);
        }
    }

    return ans;
    /*****************/
}

template<class T>
void print_fuzzy_set(const std::map<T, double> &a) {
    cout << "{ ";
    for (const auto &x : a) {
        std::cout << "(" << x.first << ", " << x.second << ") ";
    }
    cout << "}";
    std::cout << std::endl;
}

int main() {
    cout << "Ho Sy The - 20200614\n";

    std::map<int, double> a = {{1, 0.2}, {2, 0.5}, {3, 1}, {4, 0.6}, {5, 0.7}};
    std::map<int, double> b = {{1, 0.5}, {2, 0.4}, {4, 0.9}, {5, 0.4}, {6, 1}};
    std::cout << "A = "; print_fuzzy_set(a);
    std::cout << "B = "; print_fuzzy_set(b);
    std::map<int, double> c = fuzzy_set_union(a, b);
    std::map<int, double> d = fuzzy_set_intersection(a, b);
    std::cout << "Union: "; print_fuzzy_set(c);
    std::cout << "Intersection: "; print_fuzzy_set(d);
}