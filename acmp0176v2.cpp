#include <bits/stdc++.h>
using namespace std;
const int N = 102;
__int128_t dp[N][N], dp2[N][N];
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
    dp[0][0] = dp2[0][0] = dp[1][1] = dp2[1][1] = 1;
    for(int i = 1; i <= 2*n; ++i){
        for(int j = 0; j <= k; ++j){
            if(j == 0){
                dp[i][j] = dp[i -1][j + 1];
            } else if(j == k){
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = dp[i - 1][j + 1] + dp[i - 1][j - 1];
            }
        }
    }
    for(int i = 1; i <= 2*n; ++i){
        for(int j = 0; j <= k - 1; ++j){
            if(j == 0){
                dp2[i][j] = dp2[i -1][j + 1];
            } else if(j == k){
                dp2[i][j] = dp2[i - 1][j - 1];
            } else {
                dp2[i][j] = dp2[i - 1][j + 1] + dp2[i - 1][j - 1];
            }
        }
    }
    print(dp[2*n][0] - dp2[2*n][0]);
    cout << "\n";
    return 0;
}