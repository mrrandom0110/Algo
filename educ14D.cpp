#include <bits/stdc++.h>
using namespace std;
 
const int N = 1000001;
int n,m,k;
vector<int>g[N];
vector<int> used,a,perm,pos;
vector<pair<int,int>>b;
 
void dfs(int v) {
    if (used[v])
        return;
    used[v] = 1;
    pos.push_back(v);
    perm.push_back(a[v]);
    for (auto u : g[v]) {
        dfs(u);
    }
}
 
void solve() {
    cin >> n >> m;
    a.resize(n), used.resize(n, 0), b.resize(m);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i].first >> b[i].second;
        int& x = b[i].first;
        int& y = b[i].second;
        --x; --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
        if (used[i] == 0) {
            dfs(i);
            sort(begin(pos), end(pos));
            sort(begin(perm), end(perm), greater<int>());
            for (int j = 0; j < perm.size(); ++j) {
                ans[pos[j]] = perm[j];
            }
            pos.clear();
            perm.clear();
        }
    }
    for (auto& u : ans) {
        cout << u + 1 << ' ';
    }
    cout << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
