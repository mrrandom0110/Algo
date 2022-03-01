#include <iostream>
#include <vector>
#include <map>
#include <cassert>
#include <unordered_map>
#include <algorithm>
#include <deque>
using namespace std;
#define forn(i,n) for(int i=0; i<n; ++i)
#define rep(i,n) for(int i = n-1; i>=0; --i)
#define ssort(v) sort(v.begin(),v.end())
using ll = intmax_t;
 
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
string s;
int n, tt;
ll k;
void solve() {
	cin >> n >> k >> s;
	string res = "";
	int cnt = 0;
	bool print = false;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '0') {
			if (cnt <= k) {
				res += '0';
				k -= cnt;
			}
			else {
				res += string(cnt - k, '1');
				res += '0';
				res += string(k, '1');
				res += s.substr(i + 1);
				cout << res << "\n";
				print = true;
				break;
			}
		}
		else
			++cnt;
	}
	if (!print) {
		res += string(cnt, '1');
		cout << res << "\n";
	}
}
 
int main() {
	cin >> tt;
	while (tt--) {
		solve();
	}
}