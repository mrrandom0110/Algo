#include <bits/stdc++.h>
using namespace std;
const int N = 10000001;
const int MOD = 1000*1000*1000 + 7;
int mobius[N];
int lpf[N];
long long F[N];
int n;
void least_prime_factor() {
    for (int i = 2; i < N; ++i) {
        if (!lpf[i]) {
            for (int j = i; j < N; j += i) {
                if (!lpf[j]){
                    lpf[j] = i;
                }
            }
        }
    }
}
 
void Mobius() {
    for (int i = 1; i < N; ++i) {
        if (i == 1) {
            mobius[i] = 1;
        } else {
            if (lpf[i / lpf[i]] == lpf[i]) {
                mobius[i] = 0;
            } else {
                mobius[i] = -1 * mobius[i / lpf[i]];
            }
        }
    }
}
void foo(const vector<int> a) {
    int n = a.size();
    for (int i = 0; i < n; ++i) {
        int x = a[i];
        for (int j = 1; j * j <= a[i]; ++j) {
            bool found = false;
            if (x % j == 0) {
                found = true;
                ++F[j];
                if (j != x / j)
                    ++F[x / j];
            }
        }
    }
}
long long binpow(long long a, int n) {
    long long res = 1;
    while(n) {
        if (n & 1) {
            res = (res * a) % MOD;
            --n;
        }
        a = (a * a) % MOD;
        n = n >> 1;
    }
    return res;
}
 
long long f(int x) {
    return binpow(2, x);
}
void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    least_prime_factor();
    Mobius();
    foo(a);
    long long ans = 0;
    for (int i = 2; i < N; ++i) {
        ans = ((ans + mobius[i] * (((binpow(2,F[i]) - 1) % MOD + MOD) % MOD)) + MOD) % MOD;
    }
    long long subseq = ((f(n) - 1 + MOD) % MOD);
    cout << ((subseq + ans) % MOD + MOD) % MOD;
}
int main() {
    solve();
    return 0;
}