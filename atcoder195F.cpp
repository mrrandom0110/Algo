#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;
using ll = long long;
const ll N = (1 << 20) + 1;
ll dp[80][N];
ll L, R;
const ll prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71};
ll msk[80];
int main() {
    ll U = (1 << 20) - 1;
    cin >> L >> R;
    for (ll i = L; i <= R; ++i) for (int j = 0; j < 20; ++j) if (i % prime[j] == 0) msk[i - L + 1] |= 1 << j;
    dp[0][0] = 1;
    for (ll i = L; i <= R; ++i) {
        for (int mask = 0; mask <= U; ++mask) {
            dp[i - L + 1][mask] += dp[i - L][mask];
            if ((mask & msk[i - L + 1]) == 0) dp[i - L + 1][mask | msk[i - L + 1]] += dp[i - L][mask];
        }
    }
    ll ans = 0;
    for (ll mask = 0; mask <= U; ++mask)
        ans += dp[R - L + 1][mask];
 
    cout << ans << '\n';
    return 0;
}