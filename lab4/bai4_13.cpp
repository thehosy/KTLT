#include <bits/stdc++.h>
using namespace std;

// Ho Sy The - 20200614

string s;
unordered_map<int, int> m;

int main() {
    cout << "Ho Sy The - 20200614\n";

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> s;
    int n = s.length();
    int ans = 0;
    int t = 0;
    m[0] = 1;
    for(int i = 0; i < n; i++) {
        /**
         * nếu 1 thì tăng t++, ngược lại: t--
         */
        if(s[i] == '1') {
            t++;
        } else t--;
        if(m.find(t) != m.end()) {
            /**
             * Nếu tại 1 vị trí `i` ta có giá trị `t = t1`.
             * Mà trước đó `t1` đã xuất hiện tại vị trí `j` trước `i`
             * thì xâu con từ `j+1, j+2,... i` là một xâu con cân bằng
             */
            ans += m[t];
        }
        m[t]++;
    }
    cout << ans;
    return 0;
}