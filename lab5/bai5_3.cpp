#include <iostream>
using namespace std;
#include <string.h>
#include <stack>
 
int par(string str){
    int a = str.length();
    stack<char> S;
    char x; // y khong duoc su dung, co the loai bo
    for (int i = 0; i<a; i++){
        x = str[i];
        if (x == '(' || x == '[' || x == '{'){
            S.push(x);
        }
        else {
            /**
             * Neu x la ngoac dong va stack S trong thi tra ve 0
             * 
             */
            if(S.empty()) return 0; 
            if (x == ')') {
                if (S.top() == '('){
                    S.pop();
                }
                else return 0;
            }
            else if (x == ']') {
                if (S.top() == '['){
                    S.pop();
                }
                else return 0;
            }
            else if (x == '}') {
                if (S.top() == '{'){
                    S.pop();
                }
                else return 0;
            }
        }
    }
    if (S.empty()){ // kiem tra stack S neu trong thi tra ve 1, nguoc lai tra ve 0
        return 1;
    }
    else return 0;
}
 
int main(){
    cout << "\nHo Sy The - 20200614\n\n";
    int n;
    string str;
    
    cin >> n;
    for(int i=0; i < n; i++){
        cin >> str;
        cout << par(str) << endl;
    }
    
    return 0;
}