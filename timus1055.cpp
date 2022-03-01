#include <bits/stdc++.h>
using namespace std;
#define int int64_t
const int N = 100000;
#define INF 100000000000
int gcd (int a, int b) {
	while (b) {
		a %= b;
		swap (a, b);
	}
	return a;
}

int lcm(int a, int b){
    return a*b/gcd(a,b);
}
int lp[N+1],n,k,b;
int denom[N+1],num[N+1];
vector<int>pr;

void solve(int x, int a[]){
    for(int i = 0; i < pr.size(); ++i){
        int p = pr[i];
        int sum = 0;
        while(x / p != 0){
            sum += x / p;
            p*=pr[i];
        }
        a[pr[i]] += sum;
    }
}
int32_t main(){
    cin >> n >> k;
    for (int i=2; i<=n; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back (i);
        }
        for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
            lp[i * pr[j]] = pr[j];
    }
    pr.resize(pr.size());
    solve(n,num);
    solve(k,denom);
    solve(n - k, denom);
    int ans = 0;
    for(int i = 0; i < pr.size(); ++i){
        if(num[pr[i]] - denom[pr[i]] > 0)
            ++ans;
    }
    cout << ans << "\n";
}