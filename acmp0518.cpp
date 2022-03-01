#include <bits/stdc++.h>
using namespace std;
int n,p,cnt[40][40][30],a[40][40];
 
int main(){
    cin >> n >> p;
    cnt[1][1][0] = 1;
    for(int i = 1; i <= n; ++i){
        string s;
        cin >> s;
        for(int j = 0; j < s.length(); ++j){
            int x = s[j] - '0';
            a[i][j+1] = x;
        }
    }
    for(int k = 1; k <= p; ++k){
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                if(a[i][j] != 1){
                    if(a[i-1][j] != 1){
                        cnt[i][j][k] += cnt[i-1][j][k-1];
                    }
                    if(a[i][j-1] != 1){
                        cnt[i][j][k] += cnt[i][j-1][k-1];
                    }
                    if(a[i+1][j] != 1){
                        cnt[i][j][k] += cnt[i+1][j][k-1];
                    }
                    if(a[i][j+1] != 1){
                        cnt[i][j][k] += cnt[i][j+1][k-1];
                    }
                }
            }
        }
    }
    cout << cnt[n][n][p] << "\n";
}