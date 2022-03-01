#include <bits/stdc++.h>
using namespace std;
const int N = 1000001;
#define int unsigned long long
int up1[N],down1[N],up2[N],down2[N],n,p;

int32_t main(){
    cin >> n >> p;
    for(int k = 1; k <= p; ++k){
        ++up1[k];
        ++down1[k];
    }
    for(int i = 2; i <= n; ++i){
        if(!(i % 2)){
            for(int j = 0; j < 2; ++j){
                if(j == 0){ // предыдущий был сверху
                    int curSum = 0;
                    for(int k = p; k >= 1; --k){
                        down2[k] = 0;
                        down2[k] += curSum;
                        //cout << "i = " << i << " down2[" << k << "] = " << down2[k] << "\n";
                        curSum += up1[k];
                        
                    }
                } else { // предыдущий был снизу
                    int curSum = 0;
                    for(int k = 1; k <= p; ++k){
                        up2[k] = 0;
                        up2[k] += curSum;
                        //cout << "i = " << i << " up2[" << k << "] = " << up2[k] << "\n";
                        curSum += down1[k];
                    }
                }
            }
        } else {
            for(int j = 0; j < 2; ++j){
                if(j == 0){ // предыдущий был сверху
                    int curSum = 0;
                    for(int k = p; k >= 1; --k){
                        down1[k] = 0;
                        down1[k] += curSum;
                        //cout << "i = " << i << " down1[" << k << "] = " << down1[k] << "\n";
                        curSum += up2[k];
                    }
                } else {
                    int curSum = 0;
                    for(int k = 1; k <= p; ++k){
                        up1[k] = 0;
                        up1[k] += curSum;
                        //cout << "i = " << i << " up1[" << k << "] = " << up1[k] << "\n";
                        curSum += down2[k];
                    }
                }
            }
        }
    }
    int ans = 0;
    bool flag = (n % 2) == 0;
    for(int k = 1; k <= p; ++k){
        if(flag){
            ans += up2[k] + down2[k];
        } else {
            ans += up1[k] + down1[k];
        }
    }
    cout << ans << "\n";
    return 0;
}