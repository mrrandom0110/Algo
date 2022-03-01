#include <bits/stdc++.h>
using namespace std;
 
int n,k;
unordered_map<char, int> mp;
string s;
int main(){
    cin >> n >> k >> s;
    int l = 0;
    long long ans = 0;
    for (int r = 0; r < n; ++r) {
        ++mp[s[r]];
        while (mp[s[r]] > k) {
            --mp[s[l]];
            ++l;
        }
        ans += r - l  + 1;
    }
    cout << ans << "\n";
    return 0;
}