#include <bits/stdc++.h>
using namespace std;

__int128_t sum[1000000];
int n;
__int128_t get(int l, int r){
    return sum[r] - sum[l];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i){
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i){
        sum[i + 1] = sum[i] + a[i];
    }
    __int128_t max_sum = -1;
    int ix = -1;
    for(int i = 1; i < n; ++i){
        __int128_t temp_sum = get(0,i)*get(i,n);
        if (max_sum < temp_sum){
            max_sum = temp_sum;
            ix = i;
        }
    }
    cout << ix << "\n";
    return 0;
}