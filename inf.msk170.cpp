#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2*100000;
// u, time_begin, v, time_end
struct p{
    int u;
    int t;
    int w;
    p(int u, int t, int w) : u(u), t(t), w(w) {}
};
vector<p>g[N];
int ss,f,n,r,d[N];
const int INF = 1000000000;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> ss >> f >> r;
    --ss,--f;
    for(int i = 0; i < r; ++i){
        int u,t_b,v,t_e;
        cin >> u >> t_b >> v >> t_e;
        --u,--v;
        int l = t_e - t_b;
        g[u].push_back(p(v,t_b,l));
    }
    
    for(int i = 0; i < n; ++i){
        d[i] = INF;
    }
    d[ss] = 0;
    set<pair<int,int>>s;
    s.insert({d[ss],ss});
    while(!s.empty()){
        int v = s.begin()->second;
        s.erase(s.begin());
        if(d[v] == INF)
            break;
        for(auto u : g[v]){
            int t_b = u.t;
            int to = u.u;
            int l = u.w;
            if(t_b >= d[v] && d[v] + (t_b - d[v]) + l < d[to]){
                s.erase({d[to],to});
                d[to] = d[v] + (t_b - d[v]) + l;
                s.insert({d[to],to});
            }
        }
    }
    if(d[f] == INF)
        cout << -1 << "\n";
    else
        cout << d[f] << "\n";
}