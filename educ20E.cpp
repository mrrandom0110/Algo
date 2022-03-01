#include <bits/stdc++.h>
using namespace std;
 
const int Z = 1002;
const int N = 2007;
int n,k;
int dp[N][N];
int par[N][N];
string s;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k >> s;
    dp[0][Z] = 1;
    for (int i = 0; i < n; ++i) {
        for (int bal = -k + 1; bal < k; ++bal) {
            if (dp[i][Z + bal] == 0) continue;
            if (s[i] == 'W' || s[i] == '?') {
                dp[i + 1][Z + bal + 1] = 1;
                par[i + 1][Z + bal + 1] = 1;
            }
            if (s[i] == 'D' || s[i] == '?') {
                dp[i + 1][Z + bal] = 1;
                par[i + 1][Z + bal] = 0;
            }
            if (s[i] == 'L' || s[i] == '?') {
                dp[i + 1][Z + bal - 1] = 1;
                par[i + 1][Z + bal - 1] = -1;
            }
        }
    }
    if (dp[n][Z - k] > 0) {
        int p = n, w = Z - k;
        while (p > 0) {
            int d = par[p][w];
            w -= d;
            --p;
            if (d == 1) {
                s[p] = 'W';
            }
            if (d == 0) {
                s[p] = 'D';
            }
            if (d == -1) {
                s[p] = 'L';
            }
        }
        cout << s << '\n';
    } else if (dp[n][Z + k] > 0) {
        int p = n, w = Z + k;
        while (p > 0) {
            int d = par[p][w];
            w -= d;
            --p;
            if (d == 1) {
                s[p] = 'W';
            }
            if (d == 0) {
                s[p] = 'D';
            }
            if (d == -1) {
                s[p] = 'L';
            }
        }
        cout << s << '\n';
    } else {
        cout << "NO\n";
    }
    return 0;
}