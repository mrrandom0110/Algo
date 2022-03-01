#include <bits/stdc++.h>
using namespace std;
#define int int32_t


int32_t main(){

    vector<int>a(10);
    map<int,int>mp;
    for(int i = 0; i < 10; ++i){
        cin >> a[i];
        for(int j = 2; j*j <= a[i]; ++j){
        while(a[i] % j == 0){
            mp[j] += 1;
            a[i]/=j;
        }
    }
        if(a[i] > 1)
            mp[a[i]] += 1;
    }
    int ans = 1;
    for(auto &[x,y]:mp){
        ans*=(y+1);
    }
    cout << ans % 10 << "\n";
}