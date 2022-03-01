#include <bits/stdc++.h>
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
int ask(int l, int r){
	cout << "? " << l+1 << " " << r+1 << endl;
	int x;
	cin >> x;
	return x-1;
}
void solve(){
	int n;
	cin >> n;
	int max2pos = ask(0,n-1);
	if(max2pos == 0 || ask(0,max2pos) != max2pos){
		int l = max2pos, r = n-1;
		while(r - l > 1){
			int mid = (l+r)/2;
			if(ask(max2pos,mid) == max2pos){
				r = mid;
			}
			else{
				l = mid;
			}
		}
		cout << "! " << r+1 << endl;
	}
	else{
		int l = 0, r = max2pos;
		while(r-l>1){
			int mid = (l+r)/2;
			if(ask(mid,max2pos) == max2pos){
				l = mid;
			}
			else{
				r = mid;
			}
		}
		cout << "! " << l+1 << endl;
	}
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();        
}
