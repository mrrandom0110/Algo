#include <bits/stdc++.h>
#define int int64_t
using namespace std;
 
int n,m;
int get(int mask, int i){
    return (mask & (1 << i)) > 0;
}
bool check(int mask, int mask2){
    for(int i = 0; i < n - 1; ++i){
        if((get(mask,i) + get(mask,i+1) + get(mask2,i) + get(mask2,i+1)) % 4 == 0){
            return false;
        }
    }
    return true;
}
int32_t main(){
    cin >> n >> m;
    if(n > m)
        swap(n,m);
    std::vector<std::vector<int>>dp(m + 2, std::vector<int>((1 << n), 0));
    int good_mask = 0;
    for(int i = 0; i < n; i = i + 2){
        good_mask |= (1 << i);
    }
    dp[0][good_mask] = 1;
    for(int i = 0; i <= m; ++i){
        for(int mask = 0; mask < (1 << n); ++mask){
            for(int mask2 = 0; mask2 < (1 << n); ++mask2){
                if(check(mask,mask2)){
                    dp[i+1][mask] += dp[i][mask2];
                }
            }
        }
    }
    cout << dp[m+1][good_mask] << "\n";
    return 0;
}