#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n,M;
constexpr int N = 1.6*1000000;
int t[4*N];
int mp[N];
void build(int v, int l, int r) {
    if (l + 1 == r) {
        t[v] = (mp[l] > 0) ? 1 : 0;
        return;
    }
    int m = (l + r) / 2;
    build(2*v, l, m), build(2*v + 1, m, r);
    t[v] = t[2*v] + t[2*v + 1];
}
void upd(int v, int l, int r, int i, int x) {
    if (l + 1 == r) {
        t[v] = x;
        return;
    }
    int m = (l + r) / 2;
    if (i < m) upd(2*v, l, m, i, x);
    else upd(2*v + 1, m, r, i, x);
    t[v] = t[2*v] + t[2*v + 1];
}
int query(int v, int l, int r) {
    while (l + 1 != r) {
        int m = (l + r) / 2;
        if (t[2*v] == (m - l)) {
            v = 2*v + 1;
            l = m;
        } else {
            v = 2*v;
            r = m;
        }
    }
    return l;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> M;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int j = 0; j < M; ++j) {
        ++mp[a[j]];
    }
    build(1,0,N);
    vector<int> ans;
    for (int i = 1; i < n - M + 1; ++i) {
        --mp[a[i - 1]];
        if (mp[a[i - 1]] == 0) {
            upd(1, 0, N, a[i - 1], 0);
        }
        ++mp[a[i + M - 1]];
        if (mp[a[i + M - 1]] == 1) {
            upd(1, 0, N, a[i + M - 1], 1);
        }
        int q = query(1, 0, N);
        ans.push_back(q);
    }
    int ans2 = 1e9;
    for (auto u : ans) {
        ans2 = min(ans2, u);
    }
    if (ans.size() == 0)    
        ans2 = query(1,0,N);
    cout << ans2 << '\n';
}