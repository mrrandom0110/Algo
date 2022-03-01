#include <bits/stdc++.h>
using namespace std;
#define int int64_t
const int N = 100;
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

int a[102][502];
int dp[102][502];
int m,n;
pair<int,int>h[102][502];
int32_t main(){

    cin >> m >> n;
    for(int i = 1; i <= m; ++i){
        for(int j = 1; j <= n; ++j){
            cin >> a[i][j];
            dp[i][j] = INF;
        }
    }
    for(int j = 1; j <= n; ++j){
        dp[1][j] = a[1][j];
    }
    set<pair<pair<int,int>,pair<int,int>>>s;
    for(int j = 1; j <= n; ++j){
        //dist, column, row
        s.insert({{dp[1][j],-1},{1,j}});
        h[1][j] = {-1,-1};
    }
    while(!s.empty()){
        auto val = *s.begin();
        s.erase(s.begin());
        int i = val.second.first;
        int j = val.second.second;
        if(dp[i][j-1] > dp[i][j] + a[i][j-1]){
            s.erase({{dp[i][j-1],-1},{i,j-1}});
            dp[i][j-1] = dp[i][j] + a[i][j-1];
            s.insert({{dp[i][j-1],-1},{i,j-1}});
            h[i][j-1] = {i,j};
        }
        if(dp[i][j+1] > dp[i][j] + a[i][j+1]){
            s.erase({{dp[i][j+1],-1},{i,j+1}});
            dp[i][j+1] = dp[i][j] + a[i][j+1];
            s.insert({{dp[i][j+1],-1},{i,j+1}});
            h[i][j+1] = {i,j};
        }
        if(dp[i+1][j] > dp[i][j] + a[i+1][j]){
            s.erase({{dp[i+1][j],-1},{i+1,j}});
            dp[i+1][j] = dp[i][j] + a[i+1][j];
            s.insert({{dp[i+1][j],-1},{i+1,j}});
            h[i+1][j] = {i,j};
        }
    }
    int ans = 1e12;
    int i = m, k = -1;
    for(int j = 1; j <= n; ++j){
        if(ans > dp[m][j]){
            ans = dp[m][j];
            k = j;
        }
    }
    vector<int>anss;
    while(i != -1 && k != -1){
        anss.push_back(k);
        int next_i = h[i][k].first;
        int next_k = h[i][k].second;
        i = next_i;
        k = next_k;
    }
    reverse(anss.begin(),anss.end());
    for(auto u:anss){
        cout << u << " ";
    }
    cout << "\n";
}