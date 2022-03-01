#include <bits/stdc++.h>
using namespace std;
#define int int64_t
const int N = 102;
const long long INF = 100000000;
using ll = long long;

int n,q;
struct edge{
    int to;
    int apples;
};
struct vertex{
    edge left;
    edge right;
};
vector<vertex>tree;
vector<edge>g[N];
int dp[N][N];

void create_tree(int v, int p){
    if(v == 0)
        return;
    for(edge u : g[v]){
        if(u.to !=  p){
            create_tree(u.to,v);
            if(tree[v].left.to == 0){
                tree[v].left = u;
            } else {
                tree[v].right = u;
        
            }
        }
    }
}

void dfs(int v){
    if(v == 0) return;
    int left = tree[v].left.to;
    int right = tree[v].right.to;
    dfs(left);
    dfs(right);
    if(left != 0){
        for(int z = 1; z <= q; ++z){
            dp[v][z] = max(dp[v][z],dp[left][z-1] + tree[v].left.apples);
        }
    }
    if(right != 0){
        for(int z = 1; z <= q; ++z){
            dp[v][z] = max(dp[v][z],dp[right][z-1] + tree[v].right.apples);
        }
    }
    if(left != 0 && right != 0){
        for(int z = 2; z <= q; ++z){
            for(int j = 1; j <= z - 1; ++j){
                int apples = dp[left][j-1] + tree[v].left.apples + dp[right][z-j-1] + tree[v].right.apples;
                dp[v][z] = max(dp[v][z],apples);
            }
        }
    }
}

int32_t main(){

    cin >> n >> q;
    for(int i = 0; i < n - 1; ++i){
        int u,v,w;
        cin >> u >> v >> w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    tree.resize(n + 1);
    create_tree(1,0);
    dfs(1);
    cout << dp[1][q] << "\n";
}