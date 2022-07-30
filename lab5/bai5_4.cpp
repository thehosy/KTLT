#include <bits/stdc++.h>
using namespace std;

int main(){
    cout << "Ho Sy The - 20200614\n\n";

    for(int iTest = 1; iTest <= 10; iTest++){
    	char tmp[100];
    	sprintf(tmp, "%d", iTest);
        cout << tmp << '\n';
    	string seed(tmp);
        system((string("gentest.exe ") + seed).c_str());
        system(string("sol1.exe").c_str());
        system(string("sol2.exe").c_str());
        if(system(string("fc sol1.out sol2.out").c_str()) != 0){
            cout << "Test " << iTest << ": WRONG!\n";
            return 0;
        }
        cout << "Test " << iTest << ": CORRECT!\n";
    }
}