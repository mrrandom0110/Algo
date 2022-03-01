#include <bits/stdc++.h>
using namespace std;
 
long long Count[51][10003];
int n, m;
 
int32_t main(){
   cin >> n >> m;
   std::vector<int>a(n + 1);
   long long sum_array = 0;
   for (int i = 1; i <= n; ++i){
       cin >> a[i];
       sum_array += a[i];
   }
   if (sum_array < 2 * m){
       cout << "0\n";
       return 0;
   }
   Count[0][0] = 1;
   for (int i = 1; i <= n; ++i){
       for (int s = 0; s < m; ++s){
           Count[i][s] = Count[i - 1][s];
           if (s >= a[i]){
               Count[i][s] += Count[i - 1][s - a[i]];
           }
       }
   }
   long long ans = 0;
   for (int k = 0; k < m; ++k){
       ans += Count[n][k];
   }
   cout << ((1LL << n) - 2 * ans) << "\n";
   return 0;
}