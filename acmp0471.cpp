#include <bits/stdc++.h>
using namespace std;
__int128_t dp[101][10];
int n;
void print(__int128 x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}
int32_t main(){
    cin >> n;
    for(int i = 1; i <= 9; ++i){
        if(i != 8)
            dp[1][i] = 1;
    }
    std::vector<std::vector<int>>next(10);
    next[0].push_back(6); next[0].push_back(4);
    next[1].push_back(6); next[1].push_back(8);
    next[2].push_back(7); next[2].push_back(9);
    next[3].push_back(8); next[3].push_back(4);
    next[4].push_back(3); next[4].push_back(9); next[4].push_back(0);
    next[6].push_back(1); next[6].push_back(7); next[6].push_back(0);
    next[7].push_back(6); next[7].push_back(2);
    next[8].push_back(1); next[8].push_back(3);
    next[9].push_back(2); next[9].push_back(4);
    for(int i = 1; i < n; ++i){
        for(int j = 0; j < 10; ++j){
            for(int k = 0; k < next[j].size(); ++k){
                int p = next[j][k];
                dp[i+1][p] += dp[i][j];
            }
        }
    }
    __int128_t ans = 0;
    for(int j = 0; j < 10; ++j){
        ans += dp[n][j];
    }
    print(ans);
    cout << "\n";
    return 0;
}