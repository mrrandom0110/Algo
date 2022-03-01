#include <iostream>
#include <vector>
#include <map>
#include <cassert>
#include <unordered_map>
#include <algorithm>
#include <deque>
#include <set>
#include <queue>
using namespace std;
using ll = long long;
#define fi first
#define se second
#define pb push_back
#define all(v) (v.begin(),v.end())
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
 
vector<pair<int, int>>a;
int n;
ll sum(int pos,vector<ll>& c) {
	ll res = 0;
	for (; pos >= 0; pos = (pos & (pos + 1)) - 1) {
		res += c[pos];
	}
	return res;
}
void upd(int pos, int val, vector<ll>& c) {
	for (; pos < c.size(); pos |= pos + 1) {
		c[pos] += val;
	}
}
int main() {
	cin >> n;
	a.resize(n);
	forn(i, n)cin >> a[i].fi;
	forn(i, n)cin >> a[i].se;
	sort(a.begin(), a.end());
	vector<int>sp;
	forn(i, n) sp.push_back(a[i].se);
	sort(sp.begin(), sp.end());
	sp.resize(unique(sp.begin(),sp.end()) - sp.begin());
	vector<ll>cnt(n, 0);
	vector<ll> pref_sum(n, 0);
	ll ans = 0;
	for (auto x : a) {
		int speed = x.se;
		int coor = x.fi;
		int ix = lower_bound(sp.begin(), sp.end(), x.se) - sp.begin();
		ans += sum(ix, cnt) *1LL* x.fi - sum(ix, pref_sum);
		upd(ix, 1, cnt);
		upd(ix, x.fi, pref_sum);
	}
	cout << ans << "\n";
}