#include <bits/stdc++.h>
using namespace std;
const int N = 56;
int dp[N][2];
int n;
int main(){
    cin >> n;
    dp[1][1] = 1;
    for(int i = 2; i <= n; ++i){
        dp[i][1] = dp[i-1][0] + dp[i-1][1];
        dp[i][0] = dp[i-2][1] + 1;
    }
    cout << dp[n][1] << "\n";
}