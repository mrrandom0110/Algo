#include <bits/stdc++.h>
using namespace std;
#define INF 100000000
int n;
string s;
int dp[2001][2001];
int main() {
    cin >> s;
    n = s.length();
    for (int i = 0; i < 2001; ++i) for (int j = 0; j < 2001; ++j) dp[i][j] = INF;
    for (int i = 0; i < n; ++i) dp[i][i] = 0;
    for (int len = 2; len <= n; ++len) {
        for (int j = 0; j + len - 1 < n; ++j) {
            int k = j + len - 1;
            if (len == 2) {
                if (s[j] == s[k]) dp[j][k] = 0;
                else dp[j][k] = 1;
            } else {
                if (s[j] == s[k]) dp[j][k] = (dp[j + 1][k - 1] == 0 ? 0 : min(dp[j][k], dp[j + 1][k - 1]) + 2);
                for (int p = j + 1; p <= k - 1; ++p) {
                    dp[j][k] = min({dp[j][k], dp[j][p] + dp[p + 1][k] + 1, dp[j][p - 1] + dp[p][k] + 1});
                }
            }
        }
    }
    cout << dp[0][n - 1] << '\n';
    return 0;
}