#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;
int a[100][100],dp[100][100],n,m;
bool valid(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < m;
}
int main(){
   cin >> n >> m;
   for (int i = 0; i < n; ++i){
       for (int j = 0; j < m; ++j){
           cin >> a[i][j];
       }
   }
   dp[0][0] = 1;
   for (int i = 0; i < n; ++i){
       for (int j = 0; j < m; ++j){
           if(i == n - 1 && j == m - 1)
            break;
           int x = a[i][j];
           if (x == 0)
            continue;
           if (valid(i, j + x)){
               dp[i][j + x] += dp[i][j];
           }
           if (valid(i + x, j)){
               dp[i + x][j] += dp[i][j];
           }
       }
   }
   cout << dp[n - 1][m - 1] << "\n";
   return 0;
}