#include <bits/stdc++.h>
using namespace std;

// Ho Sy The - 20200614

struct bigNum{
     char sign;
     char num[101];
};
// support functions
void add(char res[], char * num1, char * num2) {
    int c = 0;

    for(int i = 100; i >= 0; i--) {
        c += (num1[i] - '0') + (num2[i] - '0');
        res[i] = '0' + (c % 10);
        c /= 10;
    }
}

void sub(char res[], char *num1, char* num2){
    int c = 0;

    for(int i = 100; i >= 0; i--){
        int t1 = num1[i] - '0';
        int t2 = num2[i] - '0';

        if(t1 >= t2 + c){
            res[i] = '0' + (t1 - t2 - c);
            c = 0;
        } else {
            res[i] = '0' + (t1 + 10 - t2 - c);
            c = 1;
        }
    }
}

void mul(char res[], char *num1, char *num2){
    for(int i = 0; i < 101; i++) 
        res[i] = '0';

    for(int i = 100; i >= 0; i--){
        char tmp[101];

        int k;
        for(k = 0; k < i; k++)
            tmp[100-k] = '0';

        int c = 0;
        for(int j = 100; j >= 0; j--){
            c += (num1[i] - '0') * (num2[j] - '0');
            tmp[k] = '0' + (c % 10);
            c /= 10;
            k--; 
            if(k < 0) break;
        }

        add(res,tmp,res);
    }
}

bool lessThan(const char *a, const char *b) {
    int n1 = 0;
    int n2 = 0;
    while (a[n1] == '0') ++n1;
    while (b[n2] == '0') ++n2;
    
    if (n1 != n2) return n1 > n2;

    for(int i = n1; i < 101; i++) {
        if(a[i] < b[i]) return true; 
    }
    return false;
}
// define bigNums's operators
istream& operator>>(istream& stream,  bigNum& v){
    string temp;
    stream >> temp;
    v.sign = temp[0];

    int n = temp.length();
    for(int i = 0; i < 101; i++)
        v.num[i] = '0';
    for(int i = 1; i < n; i++) {
        v.num[101 - n + i] = temp[i];
    }
    return stream;
}

ostream& operator<<(ostream& stream,  bigNum& v){
    stream << v.sign;
    int n;
    while (v.num[n] == '0') n++;
    for(int i = n; i < 101; i++) stream << v.num[i];
    return stream;
}

bigNum operator+(bigNum num1, bigNum num2) {
    bigNum result;
    if(num1.sign == num2.sign){
        result.sign = num1.sign;
        add(result.num, num1.num, num2.num);
    } else {
        if(lessThan(num1.num, num2.num)) {
            sub(result.num, num2.num, num1.num);
            result.sign = num2.sign;
        } else {
            sub(result.num, num1.num, num2.num);
            result.sign = num1.sign;
        }
    }
    return result;
}

bigNum operator-(bigNum num1, bigNum num2) {
    bigNum result;

    if(num1.sign == num2.sign) {
        if(lessThan(num1.num, num2.num)) {
            sub(result.num, num2.num, num1.num);
            result.sign = 97 - num1.sign;
        } else {
            sub(result.num, num1.num, num2.num);
            result.sign = num1.sign;
        }
    } else {
        result.sign = num1.sign;

        if(lessThan(num1.num, num2.num)) {
            sub(result.num, num2.num, num1.num);
        } else {
            sub(result.num, num1.num, num2.num);
        }
    }
    return result;
}

bigNum operator*(bigNum num1, bigNum num2) {
    bigNum res;
    mul(res.num,num1.num,num2.num);

    if(num1.sign == num2.sign){
        res.sign = '1';
    } else {
        res.sign = '0';
    }
    return res;
}

int main() {
    cout << "Ho Sy The - 20200614\n\n";
    bigNum a, b, three, four;
    // input a and b
    cin >> a;
    cin >> b;
    // convert 3, 4 to bigNum
    three.sign = '1';
    four.sign = '1';
    for(int i=0; i<100; i++){
        three.num[i] = '0';
        four.num[i] = '0';
    }
    three.num[100] = '3';
    four.num[100] = '4';
    // compute c = ab - 3a + 4b
    bigNum c = a*b - three*a + four*b;
    // print result computed above
    cout << c;
    return 0;
}

