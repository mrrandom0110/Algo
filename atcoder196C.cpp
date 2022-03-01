#include <bits/stdc++.h>
using namespace std;
vector<string> st;
void gen(int i, int len, string s) {
    if (i == len) {
        st.push_back(s);
        return;
    }
    for (int d = 0; d <= 9; ++d) {
        char c = d + '0';
        gen(i + 1, len, s + c);
    }
}
 
int main() {
    long long N;
    cin >> N;
    for (int len = 1; len <= 6; ++len) {
        string s = "";
        for (int d = 1; d <= 9; ++d) {
            char c = d + '0';
            gen(1, len, (s + c));
        }
    }
    long long ans = 0;
    for (int i = 0; i < st.size(); ++i) {
        string s = st[i];
        long long c = stoll(s + s);
        if (c <= N) ++ans;
    }
    cout << ans << '\n';
}