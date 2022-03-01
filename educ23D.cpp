#include <bits/stdc++.h>
using namespace std;
const int N = 1000001;
using ll = long long;
int n,a[N];
ll cnt[N];
ll leftGreat[N];ll rightGreat[N];ll leftLess[N];ll rightLess[N];ll szMax[N];ll szMin[N];ll cntMax[N];ll cntMin[N];
int f(ll a, ll b) {
    return a <= b;
}
int ff(ll a, ll b) {
    return a < b;
}
int f2(ll a, ll b) {
    return a >= b;
}
int ff2(ll a, ll b) {
    return a > b;
}
void calcSize() {
    for (int i = 0; i < n; ++i) {
        szMax[i] = rightGreat[i] - leftGreat[i] - 1;
        szMin[i] = rightLess[i] - leftLess[i] - 1;
    }
    for (int i = 0; i < n; ++i) {
        if (leftGreat[i] == -1) {
            cntMax[i] = (i + 1) * (szMax[i] - i);
        } else {
            cntMax[i] = (i - leftGreat[i])*(szMax[i] - i + leftGreat[i] + 1);
        }
        if (leftLess[i] == -1) {
            cntMin[i] = (i + 1) * (szMin[i] - i);
        } else {
            cntMin[i] = (i - leftLess[i])*(szMin[i] - i + leftLess[i] + 1);
        }
    }
}
void st(ll cL[], ll cR[], int (*f)(ll,ll), int (*ff)(ll,ll)){
    stack<ll>s;
    s.push(0);
    cL[0] = -1;
    for (int i = 1; i < n; ++i) {
        if (s.empty()) {
            s.push(i);
            continue;
        }
        while (!s.empty() && !f(a[i], a[s.top()])) {
            s.pop();
        }
        if (s.empty()) {
            cL[i] = -1;
        } else {
            cL[i] = s.top();
        }
        s.push(i);
    }
    while(!s.empty()) {
        s.pop();
    }
    s.push(n - 1);
    cR[n - 1] = n;
    for (int i = n - 2; i >= 0; --i) {
        if (s.empty()) {
            s.push(i);
            continue;
        }
        while (!s.empty() && !ff(a[i], a[s.top()])) {
            s.pop();
        }
        if (s.empty()) {
            cR[i] = n;
        } else {
            cR[i] = s.top();
        }
        s.push(i);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    st(leftGreat, rightGreat, f, ff);
    st(leftLess, rightLess, f2, ff2);
    calcSize();
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += cntMax[i]*a[i] - cntMin[i]*a[i];
    }
    cout << ans << '\n';
    return 0;
}