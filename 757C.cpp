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
int n, m, tt;
ll l, r, x;
void solve() {
	cin >> n >> m;
	ll res = 0;
	forn(i, m) {
		cin >> l >> r >> x;
		res |= x;
	}
	res = res % MOD;
	res = res * binpow(2, n - 1);
	res = res % MOD;
	cout << res << "\n";
}
 
int main() {
	cin >> tt;
	while (tt--) {
		solve();
	}
}