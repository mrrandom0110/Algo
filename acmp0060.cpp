#include <bits/stdc++.h>
using namespace std;
const int N = 200000;
int lp[N],k;
vector<int>pr;
int main(){
    cin >> k;
    for (int i=2; i<=50000; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
            lp[i * pr[j]] = pr[j];
    }
    pr.resize(pr.size());
    int ans = -1, id = 0;
    for(int i = 1; i < pr.size(); ++i){
        if(i == lp[i]){
            ++id;
            if(id == k){
                ans = pr[i-1];
                break;
            }
        }
    }
    cout << ans << "\n";
}