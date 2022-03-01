#include <bits/stdc++.h>
using namespace std;
#define INF 100000000000
#define int int64_t
const int N = 101;
#pragma GCC diagnostic ignored "-Woverflow"

struct point{
    int x;
    int type;
    int id;
    point(int x, int type, int id):x(x),type(type),id(id) {};
    bool operator < (point &rhs){
        return x == rhs.x ? (type == rhs.type ? id < rhs.id : type < rhs.type) : x < rhs.x;
    }
};
int32_t main(){
    vector<point>v;
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i){
        int l,r;
        cin >> l >> r;
        v.push_back(point(l,-1,i+1));
        v.push_back(point(r,1,i+1));
    }
    auto cmp = [](point const &lhs, point const &rhs){
        return lhs.x == rhs.x ? lhs.type > rhs.type : lhs.x < rhs.x;
    };
    sort(v.begin(),v.end(),cmp);
    int last_id = -1, last_x = -1;
    pair<int,int> best_pair = {-1,-1};
    int ans = INF;
    set<int>s;
    for(int i = 0; i < v.size(); ++i){
        if(v[i].type == -1){
            last_x = v[i].x;
            last_id = v[i].id;
            s.insert(v[i].id);
        } else {
            int sz = s.size();
            if(v[i].id == last_id){
                if(sz > 1 && ans > v[i].x - last_x){
                    ans = v[i].x - last_x;
                    s.erase(v[i].id);
                    best_pair = {*s.begin(),v[i].id};
                    s.insert(v[i].id);
                }
            } else {
                if(ans > v[i].x - last_x){
                    ans = v[i].x - last_x;
                    best_pair = {last_id,v[i].id};
                }
            }
            s.erase(v[i].id);
        }
    }
    if(ans == INF){
        cout << "0\n";
    } else {
        cout << min(best_pair.first,best_pair.second) << " " << max(best_pair.first,best_pair.second) << "\n";
    }
    return 0;
}