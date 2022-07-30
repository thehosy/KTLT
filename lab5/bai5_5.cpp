#include <bits/stdc++.h>
using namespace std;

int main(){
    cout << "Ho Sy The - 20200614\n\n";
    int n;
    cin >> n;
    while(n--){
        int a;
        cin >> a;
        if ((a % 4 == 0 && a % 100 != 0) || (a % 400 == 0)){
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
    return 0;
}