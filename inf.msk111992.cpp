#include <bits/stdc++.h>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace std;
using namespace __gnu_pbds;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set tree<int, pair<int,int>, less<int>, rb_tree_tag,tree_order_statistics_node_update>
using ll = long long;
#define fi first
#define se second
#define pb push_back
#define all(v) v.begin(),v.end()
#define forn(i,n) for(int i = 0; i < n; ++i)
#define rep(i,a,n) for(int i = a; i < n; ++i)
using pi = pair<int,int>;
using vi = vector<int>;
using vii = vector<pair<int,int>>;
#define lead_zero(x) __builtin_clz(x)
#define bit_count(x) __builtin_popcount(x)
#define odd(x) __builtin_parity //true if odd false if even
#define before_zeroes(x) __builtin_ctz(x)
using msp = multiset<pi>;
bool is_power_of_2(int n)
{
    return n && !(n & (n - 1));
}
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
const int MOD = 998244353;
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
const int N = 1e6+10;
int n,m,k;
ll dp[N],pref[N];
ll b[N];
void solve(){
    cin >> n >> m >> k;
    vi a(n + 1);
    vi b(n + 1);
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
        b[i] = b[i - 1] + (a[i] + k - 1) / k;
    }

    for (int i = 1; i <= n; ++i)
        dp[i] = 2e18;
    dp[0] = 0;
    vi p(n + 1);
    for (int i = 1; i <= n; ++i) { 
        for (int j = 1; j <= i && j <= m; ++j) {
            int cur = dp[i - j] + (pref[i] - pref[i - j] + k - 1) / k;
            if (dp[i] > cur) {
                dp[i] = cur;
                p[i] = j;
            }
        }
    }
    cout << b[n] - dp[n] << "\n";
    vii ans;
    int cur = n;
    while (cur > 0) {
        if (p[cur] > 1) {
            ans.push_back({cur - p[cur] + 1, p[cur]});
        }
        cur -= p[cur];
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (auto [a, b]: ans) {
        cout << a << ' ' << b << '\n';
    }
}
int main(){
    solve();
}
