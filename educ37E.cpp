#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 200049;
int n,m;
set<int>s[N];
set<int> unused;
vector<int>comps;
int cc;
void dfs(int x) {
    unused.erase(x);
    ++comps[cc];
    int cur = -1;
    while (true) {
        auto it = unused.upper_bound(cur);
        if (it == unused.end())
            break;
        cur = *it;
        if (s[x].count(cur))
            continue;
        dfs(cur);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int x,y;
        cin >> x >> y;
        s[x - 1].insert(y - 1);
        s[y - 1].insert(x - 1);
    }
    for (int i = 0; i < n; ++i) {
        unused.insert(i);
    }
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        if (unused.count(i)) {
            comps.push_back(0);
            dfs(i);
            ans.push_back(comps.back());
            comps.clear();
        }
    }
    sort(ans.begin(),ans.end());
    cout << ans.size() << '\n';
    for (auto u : ans) {
        cout << u << ' ';
    }
    cout << '\n';
    return 0;
}