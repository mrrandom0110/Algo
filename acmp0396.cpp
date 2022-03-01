#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <map>
using namespace std;
using ll = long long;
#define fi first
#define se second
#define pb push_back
#define all(v) v.begin(),v.end()
#define forn(i,n) for(int i = 0; i < n; ++i)
int gcd(ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}
 
int lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}
const int MOD = 1e9 + 7;
ll binpow(ll a, int n) {
    ll res = 1;
    while (n) {
        if (n & 1) {
            res = res * a % MOD;
            --n;
        }
        else {
            a = a * a % MOD;
            n >>= 1;
        }
    }
    return res;
}
 
 
int n, m;
struct p {
    int x, type, ix;
    p(int x, int type, int ix) :
        x(x), type(type), ix(ix) {}
};
void solve() {
    cin >> n >> m;
    vector<p>a;
    forn(i, n) {
        int l, r;
        cin >> l >> r;
        a.push_back(p(min(l, r), -1, -1));
        a.push_back(p(max(l, r), 1, -1));
    }
    forn(i, m) {
        int x;
        cin >> x;
        a.push_back(p(x, 0, i));
    }
    sort(all(a), [](const p& l, const p& r) {
        if (l.x != r.x)
            return l.x < r.x;
        else
            return l.type < r.type;
        });
    vector<int>ans(m);
    int bal = 0;
    for (auto u : a) {
        int t = u.type;
        int x = u.x;
        if (t == -1)
            ++bal;
        else if (t == 1)
            --bal;
        else {
            ans[u.ix] = bal;
        }
    }
    for (int i = 0; i < m; ++i)
        cout << ans[i] << " ";
    cout << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}