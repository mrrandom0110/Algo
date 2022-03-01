#include <bits/stdc++.h>

using namespace std;

vector < vector < int > > g;
vector < int > d;

void dfs(int v, int p = -1)
{
    if ((int)g[v].size()==1) d[v]=false;
    d[v] = false;
    for (auto u:g[v])
    {
        if (u == p) continue;
        dfs(u,v);
        if (!d[u]) d[v] = true;
    }
}

int main() {
    int n,root;
    scanf("%d%d",&n,&root);
    g.resize(n+1); d.resize(n+1);
    for (int i=1;i<=n-1;i++)
    {
        int u,v; scanf("%d%d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i = 1; i <= n; ++i){
        sort(g[i].begin(),g[i].end());
    }
    dfs(root);
    if(d[root]){
        for(auto u:g[root]){
            if(!d[u]){
                cout << "First player wins flying to airport " << u << "\n";
                return 0;
            }
        }
    }
    puts("First player loses");
}