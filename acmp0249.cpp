#include <bits/stdc++.h>
#define int int64_t
#define INF 100000000
using namespace std;
 
string s;
int dp[300][300];
char rev(char c){
    if(c == ')')
        return '(';
 
    else if(c == ']')
        return '[';
 
    else if (c == '}')
        return '{';
    return '*';
}
bool isOpen(char c){
    if(c == '(' || c == '[' || c == '{')
        return true;
    return false;
}
int32_t main(){
    cin >> s;
    int n = s.size();
    if(s == ""){
        cout << 0 << "\n";
        return 0;
    }
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            dp[i][j] = INF;
        }
    }
    for (int i = 0; i < n; ++i){
        dp[i][i] = 1;
    }
    for (int len = 2; len <= n; ++len){
        for (int j = 0; j + len - 1 < n; ++j){
            int k = j + len - 1;
            if (len == 2){
                if (s[j] == '(' && s[k] == ')' || s[j] == '[' && s[k] == ']' || s[j] == '{' && s[k] == '}'){
                    dp[j][k] = 0;
                } else {
                    dp[j][k] = 2;
                }
            } else {
                if (isOpen(s[j]) && s[j] == rev(s[k])){
                    dp[j][k] = std::min(dp[j][k], dp[j + 1][k - 1]);
                }
                for (int jj = j; jj < k; ++jj){
                    int kk = jj + 1;
                    dp[j][k] = std::min(dp[j][k], dp[j][jj] + dp[kk][k]);
                }
            }
        }
    }
    cout << dp[0][n-1] << "\n";
    return 0;
}