#include <bits/stdc++.h>
using namespace std;
int main(){
    cout << "Ho Sy The - 20200614\n\n";
    int n;
    cin >> n;
    int ans = 0, sum = 0;
    while(n--){
        int k, t;
        cin >> k >> t;
        int a;
        if(t == 1) {
            while(k--) {
                cin >> a;
                sum += a;
                ans = max(ans, -sum);
            }
        }
        else {
            while(k--){
                cin >> a;
                sum -= a;
                ans = max(ans, -sum);
            }
        }
    }
    cout << ans;
}