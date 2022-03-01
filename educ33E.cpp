#include <bits/stdc++.h>
#define FI(i,n) for(int i = 0; i < n; ++i)
#define FJ(j,n) for(int j = 0; j < n; ++j)
#define REP(i,a,n) for(int i = a; i < n; ++i)
using namespace std;
#define INF 1011111111
using ll = long long;
const int N = 1000100;
const ll MOD = 1000*1000*1000 + 7;
 
int tt;
int x,y;
ll fact[1010101],rev[1010101];
bool sieve[1010101];
vector<int>primes;
ll C(int n, int k) {
    return fact[n] * (ll)rev[k] % MOD * rev[n - k] % MOD;
}
ll binpow(ll a, ll n) {
    ll res = 1;
    while (n) {
        if (n & 1) {
            res = (res * a) % MOD;
            --n;
        }
        a = a * a % MOD;
        n = n >> 1;
    }
    return res;
}
void precalc() {
    for (int i = 2; i <= 1000; ++i) {
        if (!sieve[i]) {
            primes.push_back(i);
            for (int j = i + i; j <= 1000; j += i) {
                sieve[j] = true;
            }
        }
    }
    fact[0] = rev[0] = 1;
    for (int i = 1; i <= N; ++i) {
        fact[i] = fact[i - 1] * (ll) i % MOD;
    }
    rev[N] = binpow(fact[N], MOD-2);
    for (int i = N - 1; i >= 1; --i) {
        rev[i] = rev[i + 1] * (i + 1LL) % MOD;
    }
}
ll solve(ll x, ll y) {
    ll ans = 1;
    for (int p : primes) {
        if (p * p > x)
            break;
        int k = 0;
        while (x % p == 0) {
            ++k;
            x /= p;
        }
        if (k) {
            ans = ans * C(y + k - 1, k) % MOD;
        }
    }
    if (x != 1) {
        ans = ans * (ll)y % MOD;
    }
    ans = ans * (ll)binpow(2, y - 1) % MOD;
    return ans;
}
 
int main() {
    cin >> tt;
    precalc();
    while(tt--) {
        cin >> x >> y;
        cout << solve(x,y) << '\n';
    }
    return 0;
}