#include <bits/stdc++.h>
using namespace std;
#define INF 1011111111
#define FI(n) for(int i = 0; i < n; ++i)
#define FJ(n) for(int j = 0; j < n; ++j)
#define FK(n) for(int k = 0; k < n; ++k)
#define REP(i,n) for(int i = 0; i < n; ++i)
#define ff first
#define ss second
#define all(v) v.begin(), v.end()
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vii = vector<pair<int,int>>;
using pii = pair<int,int>;
template <typename T>
T binpow(T a, T n) {
    T res = 1;
    while(n) {
        if (n & 1) {
            res = res * a;
            --n;
        }
        a = a * a;
        n = n >> 1;
    }
    return res;
}
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}
int n,m;
int main() {
    fast_io();
    cin >> n >> m;
    vector<ll> a(n);
    FI(n) cin >> a[i];
    set<ll>s;
    REP(i,1L << min(n,18)) {
        ll sum = 0;
        REP(j,min(n,18)) {
            if (i & (1L<<j)){
                sum = (sum+a[j])%m;
            }
        }
        s.insert(sum);
    }
    ll ans = 0;
    s.insert(0);
    REP(i,1L << max(0,18)){
        ll sum = 0;
        REP(j,max(0,n-18)){
            if(i & (1L<<j))
                sum = (sum+a[18 + j])%m;
        }
        sum += *prev(s.upper_bound(m-sum-1),1);
        ans = max(ans,sum);
    }
    cout << ans << '\n';
}