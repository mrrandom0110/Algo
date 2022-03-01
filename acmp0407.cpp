#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;
const int N = 100001;
int n,k;
int dp[1000001];
int main(){
   cin >> n;
   vector<int> a(n);
   for (int i = 0; i <= 1000001; ++i){
       dp[i] = INF;
   }
   for (int i = 0; i < n; ++i){
       cin >> a[i];
       dp[a[i]] = 1;
   }
   cin >> k;
   // dp[s] = мин. кол-во монет, чтобы набрать сумму s
   for (int s = 0; s <= k; ++s){
       for (int i = 0; i < n; ++i){
           if(s + a[i] <= k)
                dp[s + a[i]] = std::min(dp[s + a[i]], dp[s] + 1);
       }
   }
   if (dp[k] == INF){
       cout << "-1\n";
       return 0;
   }
   cout << dp[k] << "\n";
   return 0;
}