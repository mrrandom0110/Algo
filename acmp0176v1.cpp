#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000*1000*1000 + 7;
const int N = 300;
__int128_t dp[N][N][2];
int n,k;
void print(__int128 x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}
int32_t main(){
  
    cin >> n >> k;
    dp[0][0][0] = 1;
    dp[1][1][0] = 1;
    n = 2 * n;
    for (int length = 2; length <= n; ++length){
        for(int balance = 0; balance <= min(k,length); ++balance){
            if(balance == k){
                dp[length][balance][1] = dp[length - 1][balance - 1][0] + dp[length - 1][balance -1][1];
            } else {
                if(balance > 0){
                    dp[length][balance][1] = dp[length - 1][balance - 1][1] + dp[length - 1][balance + 1][1];
                    dp[length][balance][0] = dp[length - 1][balance - 1][0] + dp[length - 1][balance + 1][0];
                } else {
                    dp[length][balance][1] = dp[length - 1][balance + 1][1];
                    dp[length][balance][0] = dp[length - 1][balance + 1][0];
                }
            }
        }
    }
    print(dp[n][0][1]);
    cout << "\n";
    return 0;
}