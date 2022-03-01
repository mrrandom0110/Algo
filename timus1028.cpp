#include <bits/stdc++.h>
using namespace std;
#define int int64_t
const int N = 50000;
const long long INF = 100000000;

map<pair<int,int>,int>mp;
vector<int>fenwick;
int max_y;

int get(int r){
    int sum = 0;
    for(;r >= 0; r = (r & (r + 1)) - 1){
        sum += fenwick[r];
    }
    return sum;
}

void upd(int pos, int x){
    for(; pos < max_y; pos = (pos | (pos+1))){
        fenwick[pos] += x;
    }
}

int32_t main(){
    int n;
    cin >> n;
    vector<pair<int,int>>v(n);
    for(int i = 0; i < n; ++i){
        int x,y;
        cin >> x >> y;
        v[i] = {x,i};
        mp[{x,i}] = y;
        max_y = max(max_y,y);
    }
    ++max_y;
    fenwick.resize(max_y);
    vector<int>a(n,0);
    sort(v.begin(),v.end(),[](pair<int,int> &lhs, pair<int,int> &rhs){
        return lhs.first == rhs.first ? lhs.second < rhs.second : lhs.first < rhs.first;
    });

    for(int i = 0; i < n; ++i){
        int x = v[i].first;
        int j = v[i].second;
        int y = mp[{x,j}];
        int cnt = get(y);
        ++a[cnt];
        upd(y,1);
    }
    for(int i = 0; i < n; ++i){
        cout << a[i] << "\n";
    }
}