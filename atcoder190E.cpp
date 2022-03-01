#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;
using ll = long long;
const int N = 100001;
int dp[(1 << 18)][30];
int n,m,x,y,k;
vector<int>g[N];
const int MOD = 1000*1000*1000 + 7;
int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {cin >> x >> y; g[x-1].push_back(y-1),g[y-1].push_back(x-1);}
    cin >> k;
    vector<int> C(k);
    for (auto &x : C) {cin >> x; --x;}
 
    auto BFS = [&](int s) {
        vector<int>cost(n, INF);
        cost[s] = 0;
        queue<int> q;
        q.push(s);
        while(!q.empty()) {
            int x = q.front();
            q.pop();
            for (auto y : g[x]) {
                if (cost[y] > cost[x] + 1) {
                    cost[y] = cost[x] + 1;
                    q.push(y);
                }
            }
        }
        for (int i = 0; i < k; ++i) cost[i] = cost[C[i]];
        cost.resize(k);
        return cost;
    };
    vector<vector<int>> cost(k);
    for (int i = 0; i < k; ++i) cost[i] = BFS(C[i]);
    vector<vector<int>> dp(1 << k, vector<int>(k,INF));
    for (int i = 0; i < k; ++i) dp[1 << i][i] = 1;
    for (int mask = 0; mask < (1 << k); ++mask) for (int i = 0; i < k; ++i) if (mask & (1 << i)) {
        int mask2 = mask ^ (1 << i);
        for (int j = 0; j < k; ++j) if (mask2 & (1 << j)) {dp[mask][i] = min(dp[mask][i], dp[mask2][j] + cost[i][j]);}
    }
    int ans = *min_element(dp.back().begin(), dp.back().end());
    if (ans == INF)
        ans = -1;
    cout << ans << '\n';
    return 0;
}