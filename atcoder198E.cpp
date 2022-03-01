#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> c;
vector<int>g[100010];
int mp[100010];
vector<int> ans;
void dfs(int v, int p = -1) {
    if (mp[c[v]] == 0)
        ans[v] = 1;
    ++mp[c[v]];
    for (auto u : g[v]) {
        if (u != p) {
            dfs(u,v);
        }
    }
    --mp[c[v]];
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    c.resize(n), ans.resize(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        int x,y;
        cin >> x >> y;
        g[x - 1].push_back(y - 1), g[y - 1].push_back(x - 1);
    }
    dfs(0);
    for (int i = 0; i < n; ++i) {
        if (ans[i] == 1) cout << i + 1 << '\n';
    }
    return 0;
}