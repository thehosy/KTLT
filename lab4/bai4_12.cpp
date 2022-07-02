#include <bits/stdc++.h>

using namespace std;

// Ho Sy The - 20200614

int n;
int a[1000007];
stack<int> op;

int main() {

    cout << "Ho Sy The - 20200614\n";
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++) cin >> a[i];
    /**
     * @left: left[i] chính là vị trí gần nhất trước vị trí i mà a[left[i]] < a[i]
     * @right: right[i] chính là vị trí gần nhất sau vị trí i mà a[right[i]] < a[i]
     * @solution: diện tích lớn nhất ứng với mỗi vị trí i là a[i] * (right[i] - left[i] - 1)
     */
    vector<int> left(n, -1), right(n, n);

    for(int i = 0; i < n; i++) {
        if(op.empty()) op.push(i);
        else {
            if(a[i] > a[op.top()]) {
                left[i] = op.top();
                op.push(i);
            } else if(a[i] == a[op.top()]) {
                left[i] = left[op.top()];
                op.push(i);
            }
            else {
                while(!op.empty()) {
                    right[op.top()] = i;
                    if(a[i] < a[op.top()]) op.pop();
                    else break;
                }
                if(!op.empty()) {
                    if(a[i] == a[op.top()]) {
                        left[i] = left[op.top()];
                    } else left[i] = op.top();
                }
                op.push(i);
            }
        }
    }

    long long ans = 0;

    for(int i = 0; i < n; i++) {
        ans = max(ans, (long long)a[i] * (right[i] - left[i] - 1));
    }

    cout <<  ans;

    return 0;
}