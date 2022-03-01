#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 998244353;
const int N = 10 * 1000 + 7;
const int M = 100 + 7;
int p,s,r;
ll fact[N],rev[N];
int mul(int a, int b) {
    return (a * 1ll * b) % MOD;
}
int add(int a, int b) {
    a += b;
    if (a >= MOD)
        a -= MOD;
    if (a < 0)
        a += MOD;
    return a;
}
int C(int n, int k) {
    if (n == k)
        return 1;
    if (k < 0 || k > n)
        return 0;
    return mul(fact[n], mul(rev[n - k], rev[k]));
}
int binpow(int a, int n) {
    int res = 1;
    while(n) {
        if (n & 1) {
            res = mul(res,a);
            --n;
        }
        a = mul(a,a);
        n = n >> 1;
    }
    return res;
}
int inv(int a) {
    return binpow(a, MOD - 2);
}
int f(int s, int p, int m) {
    int res = 0;
    for (int i = 0; i <= p; ++i) {
        res = add(res, mul(i & 1 ? MOD - 1 : 1, mul(C(p, i), C(s + p - 1 - i * (m + 1), p - 1))));
    }
    return res;
}
int main() {
    cin >> p >> s >> r;
    fact[0] = 1;
    for (int i = 1; i < N; ++i) {
        fact[i] = mul(fact[i - 1], i);
    }
    rev[N - 1] = binpow(fact[N - 1], MOD - 2);
    for (int i = N - 2; i >= 0; --i) {
        rev[i] = mul(rev[i + 1], i + 1);
    }
    int P = 0;
    int Q = C(s - r + p - 1, p - 1);
    for (int t = r; t <= s; ++t) for (int q = 1; q <= p; ++q)
            P = add(P, mul(mul(C(p - 1, q - 1), inv(q)), f(s - q*t, p - q, t - 1)));
    cout << mul(P, binpow(Q, MOD - 2)) << '\n';
    return 0;
}