#include <bits/stdc++.h>
#define FI(i,n) for(int i = 0; i < n; ++i)
#define FJ(j,n) for(int j = 0; j < n; ++j)
#define REP(i,a,n) for(int i = a; i < n; ++i)
using namespace std;
#define INF 1011111111
using ll = long long;
const int N = 200002;
const int MOD = 1000*1000*1000 + 7;
int n;
ll pref[N];
map<ll,ll>mp;
ll get(int l, int r) {
    return pref[r] - pref[l];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        pref[i + 1] = pref[i] + a[i];
    }
    long double fake_sum = 0;
    int start_coeff = n - 1;
    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            ++mp[a[i]];
            fake_sum += (long double)start_coeff*a[i];
            start_coeff-=2;
        } else {
            ll cnt = mp[a[i] - 1];
            fake_sum += (long double)cnt;
            ll cnt2 = mp[a[i] + 1];
            fake_sum -= (long double)cnt2;
            ++mp[a[i]];
            fake_sum += (long double)start_coeff*a[i];
            start_coeff-=2;
        }
    }
    fake_sum = -fake_sum;
    ll test_ans = fake_sum;
    if (test_ans == 0) {
        cout << "0\n";
        return 0;
    }
    printf("%.0Lf\n", fake_sum);
    return 0;
}