#include <bits/stdc++.h>
using namespace std;
 
int n;
int dp[21][185][185];
int main(){
   cin >> n;
   if(n == 1){
       cout << "10\n0\n";
       return 0;
   }
   dp[0][0][1] = 1;
   for(int i = 0; i <= 9; ++i){
       dp[1][i][i] = 1;
   }
   for (int i = 1; i < n; ++i){
       for (int digit = 0; digit <= 9; ++digit){
           for(int sum = 0; sum <= 181; ++sum){
               for(int mult = 0; mult <= 181; ++mult){
                   if (sum + digit <= 181 && mult * digit <= 181){
                       dp[i + 1][sum + digit][mult * digit] += dp[i][sum][mult];
                   }
               }
           }
       }
   }
   int total = 0;
   for(int s = 1; s<= 9*n; ++s){
       total += dp[n][s][s];
   }
   cout << total << "\n";
   unsigned long long ans = ~0ull;
   for(int sum = 1; sum <= 9*n; ++sum){
       if (dp[n][sum][sum] > 0){
           unsigned long long res = 0;
           int s = sum;
           int p = sum;
           for (int i = n; i > 0; --i){
               bool found = false;
               for (int digit = 1; digit <= 9; ++digit){
                   if (s - digit >= 0 && p % digit == 0 && dp[i - 1][s - digit][p / digit] > 0){
                       res = res * 10 + digit;
                       s -= digit;
                       p /= digit;
                       found = true;
                       break;
                   }
               }
               assert(found == true);
           }
           ans = std::min(ans, res);
       }
   }
   cout << ans << "\n";
   
  return 0;
}