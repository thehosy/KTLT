#include <bits/stdc++.h>

using namespace std;

int N = 200; // size of square matrix
const int NUM_TEST = 5;
const int NUM_INPUTS = 20;

typedef vector<vector<int> > matrix;

void init(matrix &m, bool fillZeros = false) {
    m.assign(N, vector<int>(N));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            m[i][j] = fillZeros? 0: rand() % 10 - 5;
        }
    }

}

matrix x[NUM_INPUTS];
matrix f;

void prepare_input() {
    for (int i = 0; i < NUM_INPUTS; i++) {
        init(x[i]);
    }
    init(f);
}

ostream &operator<<(ostream &os, const matrix &m) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            os << m[i][j] << ' ';
        }
        os << '\n';
    }

    return os;
}

bool operator==(const matrix &a, const matrix &b) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (a[i][j] != b[i][j]) return false;
        }
    }
    return true;
}

bool operator==(const vector<matrix> &a, const vector<matrix> &b) {
    for(int i = 0; i < a.size(); ++i) {
        if(!(a[i] == b[i])) return false;
    }
    return true;
}

matrix matmul_slow(const matrix &a, const matrix &b) {
    matrix result;
    init(result, true);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return result;
}

matrix matmul_fast(const matrix &a, const matrix &b) {
    matrix result;
    init(result, true);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            int sum = 0;
            for (int k = 0; k < N; ++k) {
                sum += a[i][k] * b[k][j];
            }
            result[i][j] = sum;
        }
    }
    return result;
}

double benchmark(matrix (*multiply) (const matrix&, const matrix&), vector<matrix> &out) {
    clock_t start = clock();
    for (int t = 0; t < NUM_TEST; ++t) {
        for (int i = 0; i < NUM_INPUTS; ++i) {
            out.push_back(multiply(x[i], f));
        }
    }
    clock_t finish = clock();
    return (double)(finish - start);
}

int main() {
    printf("Ho Sy The - 20200614\n\n");
    prepare_input();

    vector<matrix> a, b;

    printf("Slow version: ");
    double slow = benchmark(matmul_slow, a);
    printf("%lf ms\n", slow);
    printf("Fast version: ");
    double fast = benchmark(matmul_fast, b);
    printf("%lf ms\n", fast);

    if (a == b) {
        printf("Correct answer! Your code is %.2f%% faster\n", slow / fast * 100.0);
    } else {
        printf("Wrong answer!\n");
    }
    return 0;
}