#include <bits/stdc++.h>
#define INF 1000000000
const int BB = 0, BW = 1, WB = 2, WW = 3;
using namespace std;
using ll = long long;
const int MOD = 998244353;
const int N = 10 * 1000 + 7;
const int M = 100 + 7;
int mul(int a, int b) {return (a * 1ll * b) % MOD;}
int sub(int a, int b) {return ((a - b) % MOD + MOD) % MOD;}
int add(int a, int b) {a += b;if (a >= MOD)a -= MOD;if (a < 0)a += MOD;return a;}
//int choose(int n, int k) {if (n == k)return 1; if (k < 0 || k > n) return 0;return mul(fact[n], mul(rev[n - k], rev[k]));}
int normmod(int a, int n) {int res = 1; while(n) {if (n & 1) {res = mul(res,a); --n;} a = mul(a,a);n = n >> 1;}return res;}
int inv(int x, int MOD) {return normmod(x, MOD - 2);}
int gcd(int a, int b) {while (b) {a %= b;swap (a, b);}return a;}
int lcm(int a, int b) {return a*b/gcd(a,b);}
bool checkmin(int &a, int b) {if (a > b) {a = b; return true;} return false;}
bool checkmax(int &a, int b) {if (a < b) {a = b; return true;} return false;}
bool equalDouble(double a, double b) {return abs(a - b) < std::numeric_limits<double>().epsilon();}
int n,k;
int dp[1001][4000][4];
int additional_components(int second_last, int last)
{
    switch(second_last)
    {
        case BB : switch(last)
                  {
                      case BB : return 0;
                      case BW : return 1;
                      case WB : return 1;
                      case WW : return 1;
                  }
        case BW : switch(last)
                  {
                      case BB : return 0;
                      case BW : return 0;
                      case WB : return 2;
                      case WW : return 0;
                  }
        case WB : switch(last)
                  {
                      case BB : return 0;
                      case BW : return 2;
                      case WB : return 0;
                      case WW : return 0;
                  }
        case WW : switch(last)
                  {
                      case BB : return 1;
                      case BW : return 1;
                      case WB : return 1;
                      case WW : return 0;
                  }
    }
}
int main() {
    cin >> n >> k;
    dp[1][1][0] = dp[1][1][3] = dp[1][2][2] = dp[1][2][1] = 1;
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= 2*i; ++j) {
            for (int mask2 = 0; mask2 < 4; ++mask2) {
                for (int mask1 = 0; mask1 < 4; ++mask1) {
                    int nc = additional_components(mask1,mask2);
                    dp[i][j + nc][mask2] = add(dp[i][j + nc][mask2], dp[i - 1][j][mask1]);
                }
            }
        }
    }
    int ans = 0;
    for (int mask = 0; mask < 4; ++mask) {
        ans = add(ans, dp[n][k][mask]);
    }
    cout << ans << '\n';
    return 0;
}