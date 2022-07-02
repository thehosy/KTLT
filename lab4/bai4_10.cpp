#include <bits/stdc++.h>
using namespace std;

// Ho Sy The - 20200614

int N, Q;
unordered_map<string, int> dict[1001];
unordered_map<string, int> mark;
vector<string> qr[1001]; // tất cả query
int maxfd[1001];

void compute() {
    // $max_f(d)$ là giá trị lớn nhất của $f(t, d)$ với mọi $t$
    for(int i = 0; i < N; i++) {
        unordered_map<string, int> ump = dict[i];
        int mmax = 0;
        for(auto t: ump) {
            mmax = max(mmax, t.second);
        }
        maxfd[i] = mmax;
    }
}

inline int ftd(string t, int d) {
    return dict[d][t];
}

int dft(string t) {
    if(mark.find(t) != mark.end()) return mark[t];
    int ans = 0;
    for(int i = 0; i < N; i++) {
        if(dict[i][t] != 0) ans++;
    }
    mark.insert({t, ans});
    return ans;
}

void cal_TF_IDF(int sz, vector<string> &query) {
    int ans = 0;
    double sc = INT_MIN;

    for(int i = 0; i < N; i++) {
        double temp_sc = 0;
        for(int j = 0; j < sz; j++) {
            int f_td = ftd(query[j], i);
            int d_ft = dft(query[j]);
            if(f_td == 0) continue;
            int max_fd = maxfd[i];

            double TF = 0.5 + (0.5 * f_td) / max_fd;
            double IDF = log2(1.0 * N / d_ft);
            temp_sc += TF * IDF; 
        }
        if(temp_sc > sc) {
            sc = temp_sc;
            ans = i + 1;
        }
    }

    cout << ans << '\n';
} 

int main() {
    cout << "Ho Sy The - 20200614\n";
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    string temp;
    for(int i = 0; i < N; i++) {
        cin >> temp;
        temp.push_back(',');
        int n = temp.size();
        int b = 0;
        for(int j = 0; j < n; j++) {
            if(temp[j] == ',') {
                dict[i][string(temp.begin() + b, temp.begin() + j)]++;
                b = j + 1;
            }
        }
    }

    compute();

    cin >> Q;


    for(int i = 0; i < Q; i++) {
        cin >> temp;
        temp.push_back(',');
        int n = temp.size();
        int b = 0, t = 0;
        for(int j = 0; j < n; j++) {
            if(temp[j] == ',') {
                qr[i].push_back(string(temp.begin() + b, temp.begin() + j));
                b = j + 1;
            }
        }      
    }

    for(int i = 0; i < Q; i++) cal_TF_IDF(qr[i].size(), qr[i]);

    return 0;
}