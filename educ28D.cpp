#include <bits/stdc++.h>
#define INF 1011111111
using namespace std;
const int N = 505;
int dp[N][N],n,m,k,q;
typedef struct tripple{
    int x,y,t;
}tripple;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> k >> q;
    vector<tripple>a(q);
    for (int i = 0; i < q; ++i) {
        cin >> a[i].x >> a[i].y >> a[i].t;
    }
    sort(a.begin(),a.end(),[](const tripple &lhs, const tripple &rhs) {
        return lhs.t < rhs.t;
    });
    int l = -1, r = INF;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        for(int i = 0; i <= n; ++i){
            for(int j = 0; j <= m; ++j)
                dp[i][j] = 0;
        }
        for (int i = 0; i < q; ++i) {
            if (a[i].t <= mid) {
                dp[a[i].x][a[i].y] = 1;
            } else
                break;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                dp[i + 1][j + 1] += dp[i + 1][j] + dp[i][j + 1] - dp[i][j];
            }
        }
        bool ok = false;
        for (int i = k; i <= n; ++i) {
            for (int j = k; j <= m; ++j) {
                int sum = dp[i][j] - dp[i - k][j] - dp[i][j - k] + dp[i - k][j - k];
                if (sum == k*k){
                    ok = true;
                }
            }
        }
        if (ok)
            r = mid;
        else
            l = mid;
    }
    cout << (r == INF ? -1 : r) << '\n';
    return 0;
}