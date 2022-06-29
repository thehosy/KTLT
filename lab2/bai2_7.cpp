#include <iostream>

// Ho Sy The - 20200614

using namespace std;

// sum function for int array and double array
template <typename T>
T arr_sum(T *arrA, int sizeA, T * arrB, int sizeB) {
    T sum = 0;
    for(int i = 0; i < sizeA; ++i)
        sum += *(arrA + i);

    for(int i = 0; i < sizeB; ++i)
        sum += *(arrB + i);

    return sum;
}

int main() {
    int val;
    cin >> val;
    
    {// int array:
        int a[] = {3, 2, 0, val};
        int b[] = {5, 6, 1, 2, 7};
        cout << arr_sum(a, 4, b, 5) << endl;
    }
    {// double array:
        double a[] = {3.0, 2, 0, val * 1.0};
        double b[] = {5, 6.1, 1, 2.3, 7};
        cout << arr_sum(a, 4, b, 5) << endl;
    }

    return 0;
}

