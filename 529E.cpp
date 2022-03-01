#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int n;
	string s;
	cin >> n >> s;
	
	string rs(s.rbegin(), s.rend());
	for (int i = 0; i < n; ++i) {
		if (rs[i] == '(') {
			rs[i] = ')';
		} else {
			rs[i] = '(';
		}
	}
	
	vector<int> pref(n + 1), suf(n + 1);
	vector<bool> okp(n + 1), oks(n + 1);
	okp[0] = oks[n] = true;
	for (int i = 0; i < n; ++i) {
		pref[i + 1] = pref[i] + (s[i] == '(' ? +1 : -1);
		okp[i + 1] = okp[i] & (pref[i + 1] >= 0);
		suf[n - i - 1] = suf[n - i] + (rs[i] == '(' ? +1 : -1);
		oks[n - i - 1] = oks[n - i] & (suf[n - i - 1] >= 0);
	}
	
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (!okp[i] || !oks[i + 1]) {
			continue;
		}
		if (s[i] == '(') {
			if (pref[i] > 0 && pref[i] - 1 - suf[i + 1] == 0) {
				++ans;
			}
		} else {
			if (pref[i] + 1 - suf[i + 1] == 0) {
				++ans;
			}
		}
	}
	
	cout << ans << endl;
	
	return 0;
}