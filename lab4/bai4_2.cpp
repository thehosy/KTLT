#include <iostream>
#include <cmath>
#include <iomanip>
#include <utility>
using namespace std;
using Point = pair<double, double>;

double area(Point a, Point b, Point c) {
    // /*****************
    double _a = sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
    double _b = sqrt(pow(a.first - c.first, 2) + pow(a.second - c.second, 2));
    double _c = sqrt(pow(c.first - b.second, 2) + pow(c.second - b.second, 2));

    double p = .5 * (_a + _b + _c);

    return sqrt(p*(p - _a)*(p - _b)*(p - _c));
    // *****************/
}

int main() {
    cout << "Ho Sy The - 20200614\n";

    cout << setprecision(2) << fixed;
    cout << area({0, 0}, {0, 4}, {3, 0}) << endl;
    return 0;
}