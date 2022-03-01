#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 998244353;
template <typename T>
class Matrix {
    public:
        T a[140][140];
        int n;
        int m;
        void id();
        void print();
        Matrix<T> pow(int k);
        Matrix<T> mult(Matrix r);
        void insert();
    
    Matrix(int n, int m) : n(n), m(m) {
        for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) a[i][j] = 0;
    }
    Matrix(int n) : n(n), m(n) {
        for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) a[i][j] = 0;
    }
    Matrix(const Matrix &r) {
        n = r.n, m = r.m;
        for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) a[i][j] = r.a[i][j];
    }
};
template <typename T>
Matrix<T> Matrix<T>::mult(Matrix<T> r) {
    Matrix<T> res(n,r.m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < r.m; ++j) {
            for (int k = 0; k < m; ++k) {
                res.a[i][j] = (res.a[i][j] + a[i][k]*r.a[k][j]) % mod;
            }
        }
    }
    return res;
}
template <typename T>
void Matrix<T>::id() {
    for (int i = 0; i < n; ++i) a[i][i] = 1;
}
template <typename T>
Matrix<T> Matrix<T>::pow(int k) {
    Matrix<T> temp(*this);
    Matrix<T> res(n,n);
    res.id();
    while (k) {
        if (k & 1) {
            res = res.mult(temp);
            --k;
        }
        temp = temp.mult(temp);
        k = k >> 1;
    }
    return res;
}
template <typename T>
void Matrix<T>::print() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            cout << a[i][j] << ' ';
        cout << '\n';
    }
}
template <typename T>
void Matrix<T>::insert() {
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> a[i][j];
}
 
int used[20][20],h,w,a,b; // x - строка, y - столбец, a - 1x1 маты, b - (2x1, 1x2)
int dfs(int i, int j, int a, int b) {
    if (a < 0 || b < 0) return 0;
    if (j == w) j = 0, ++i;
    if (i == h) return 1;
    if (used[i][j]) return dfs(i, j + 1, a, b);
    int res = 0;
    used[i][j] = 1;
    res += dfs(i, j+1, a, b-1);
    if (j+1 < w && !used[i][j+1]) {
        used[i][j+1] = 1;
        res += dfs(i, j+1, a - 1, b);
        used[i][j+1] = 0;
    }
    if (i+1 < h && !used[i+1][j]) {
        used[i+1][j] = 1;
        res += dfs(i, j+1, a - 1, b);
        used[i + 1][j] = 0;
    }
    used[i][j] = 0;
    return res;
}
 
int main() {
    cin >> h >> w >> a >> b;
    int ans = dfs(0,0,a,b);
    cout << ans << '\n';
    return 0;
}