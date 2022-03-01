#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n;
int main() {
    cin >> n;
    vector<ll> a(n);
    for (auto &x : a) cin >> x;
    ll sum = std::accumulate(a.begin(),a.end(),0);
    ll first = 0;
    for (int i = 0; i < n; ++i) {
        first += a[i]*a[i];
    }
    first = first*n;
    ll second = 0;
    for (int i = 0; i < n; ++i) {
        second += a[i] * sum;
    }
    ll ans = first - second;
    cout << ans << '\n';
    return 0;
}