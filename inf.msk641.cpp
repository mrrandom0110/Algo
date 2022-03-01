#include <bits/stdc++.h>
using namespace std;
#define INF 100000
#define int int32_t
const int N = 100000;
#pragma GCC diagnostic ignored "-Woverflow"

int n;
int main(){
    cin >> n;
    vector<pair<int,int>>seg;
    for(int i = 0; i < n; ++i){
        int l,r;
        cin >> l >> r;
        seg.push_back({l,-1});
        seg.push_back({r,1});
    }
    auto cmp = [](pair<int,int> &lhs, pair<int,int> &rhs){
        return lhs.first == rhs.first ? lhs.second < rhs.second : lhs.first < rhs.first;
    };
    sort(seg.begin(),seg.end(),cmp);
    int bal = 0, flag = 1;
    int ans = 0, coor_left = -1, coor_right = 1;
    for(int i = 0; i < seg.size(); ++i){
        if(seg[i].second == -1)
            ++bal;
        if(flag == 1 && seg[i].second == -1){
            coor_left = seg[i].first;
            flag = 0;
            continue;
        }
        if(seg[i].second == 1)
            --bal;
        if(!flag && !bal){
            ans += seg[i].first - coor_left;
            flag = 1;
            coor_left = -1;
        }
    }
    cout << ans << "\n";
}