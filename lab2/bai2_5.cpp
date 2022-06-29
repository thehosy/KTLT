#include <iostream>
#include <ostream>
#include <math.h>
#include <iomanip> 

// Ho Sy The -20200614

using namespace std;
// define Complex number type
struct Complex {
    double real;
    double imag;
};
// overload a + b that both a and b are complex number
Complex operator + (Complex a, Complex b) {
    return Complex{a.real + b.real, a.imag + b.imag};
}
// overload a - b that both a and b are complex number
Complex operator - (Complex a, Complex b) {
    return Complex{a.real - b.real, a.imag - b.imag};
}
// overload a * b that both a and b are complex number
Complex operator * (Complex a, Complex b) {
    double newReal = a.real * b.real - a.imag * b.imag;
    double newImag = a.real * b.imag + b.real * a.imag;
    return Complex{newReal, newImag};
}
// overload a / b that both a and b are complex number
Complex operator / (Complex a, Complex b) {
    double x = b.real * b.real + b.imag * b.imag;
    double newReal = (a.real * b.real + a.imag * b.imag) / x;
    double newImag = (a.imag * b.real - a.real * b.imag) / x;
    return Complex{newReal, newImag};
}
// overload output stream
ostream& operator << (ostream& out, const Complex &a) {
    out << '(' << std::setprecision(2) 
        << a.real << (a.imag >= 0 ? '+' : '-') 
        << std::setprecision(2) << fabs(a.imag) << 'i' << ')';
    return out;
}

int main() {
    double real_a, real_b, img_a, img_b;
    // input two complex numbers
    cin >> real_a >> img_a;
    cin >> real_b >> img_b;
    
    Complex a{real_a, img_a};
    Complex b{real_b, img_b};
    
    // output results with operations on complex numbers
    cout << a << " + " << b << " = " << a + b << endl;
    cout << a << " - " << b << " = " << a - b << endl;
    cout << a << " * " << b << " = " << a * b << endl;
    cout << a << " / " << b << " = " << a / b << endl;
    
    return 0;
}

