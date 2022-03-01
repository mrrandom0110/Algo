#include <bits/stdc++.h>
using namespace std;
#define int int64_t
#define all(v) v.begin(),v.end()
const int N = 6001;
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
int n,a[N],dp[N],d[N];
vector<int>g[N];

void dfs(int v, int p = -1){
    dp[v] = a[v];
    for(auto u : g[v]){
        if(u != p)
            dfs(u,v);
    }
    int sum1 = 0, sum2 = 0;
    for(auto u : g[v]){
        for(auto c : g[u]){
            sum1 += dp[c];
        }
        sum2 += dp[u];
    }
    dp[v] = max({dp[v],a[v] + sum1, sum2});
}
int32_t main(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    while(1){
        int u,v;
        cin >> u >> v;
        if(u == 0 && v == 0)
            break;
        --u,--v;
        g[v].push_back(u);
        ++d[u];
    }
    int root = -1;
    for(int i = 0; i < n; ++i){
        if(!d[i]){
            root = i;
            break;
        }
    }
    dfs(root);
    assert(root != -1);
    cout << dp[root] << "\n";
}