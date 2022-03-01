#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1000*1000*1000 + 7;
const int N = 5001;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll powb(ll a,ll b) {ll res=1;a ; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a;a=a*a;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
 
ll fact[N+2],invf[N+2];
 
void calc(){
	fact[0]=1;
	for(int i = 1; i <= N; ++i){
		fact[i]=fact[i-1]*i%mod;
	}
	invf[N]=powmod(fact[N],mod-2);
	for(int i=N-1;i>=0;i--){
		invf[i]=invf[i+1]*(i+1)%mod;
	}
}
 
ll choose(int n,int r){
	if(n<r)return 0;
	return fact[n]*invf[r]%mod * invf[n-r]%mod;
}

ll solve(ll n){
    ll result = 0;
    for(ll k = 0; k <= n; ++k){
        ll kth = choose(n,k) * powmod(2,choose(n - k, 2)) % mod;
        if(k % 2){
            result = ((result - kth) % mod + mod) % mod;
            continue;
        }
        result = (result + kth) % mod;
    }
    return result;
}
int main(){
    ll n,k;
    cin >> n;
    calc();
    cout << (n * solve(n - 1)) % mod << "\n";
    return 0;
}