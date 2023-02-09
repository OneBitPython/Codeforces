#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(c) c.begin(), c.end()
#define endl "\n"

const double PI=3.141592653589;


void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define dbg(x...) cerr << "LINE(" << __LINE__ << ") -> " <<"[" << #x << "] = ["; _print(x)
#else
#define dbg(x...)
#endif

vector<vector<pair<int,int>>>adj;
vector<int>dist,taken,subtree,par,depth;
vector<vector<int>>up,dp;
void compute(int u, int p){
    for(auto [w,v] : adj[u]){
        if(v==p)continue;
        up[v][0] = u;
        for(int j = 1;j<=20;++j)up[v][j] = up[up[v][j-1]][j-1];
        dist[v] = dist[u]+w;
        depth[v] = depth[u]+1;
        compute(v,u);
    }
}

int lca(int u, int v){
    if(depth[v] > depth[u])swap(u,v);
    int k = depth[u]-depth[v];
    for(int i = 20;i>=0;--i){
        if(k&(1ll<<i))u = up[u][i];
    }
    if(u==v)return u;
    for(int i = 20;i>=0;--i){
        if(up[u][i] != up[v][i])u = up[u][i], v = up[v][i];
    }
    return up[v][0];
}

int d(int a, int b){
    return dist[a]+dist[b]-(2*dist[lca(a,b)]);
}

void sub(int u, int p){
    subtree[u] = 1;
    for(auto [w,v] : adj[u]){
        if(v==p || taken[v])continue;
        sub(v,u);
        subtree[u]+=subtree[v];
    }
}


int centroid(int u, int p, int n){
    for(auto [w,v] : adj[u]){
        if(v==p || taken[v])continue;
        if(subtree[v] > (n/2))return centroid(v,u,n);
    }
    return u;
}

void dfs2(int u, int p, vector<int>&c, int og){
    c.pb(d(u,og));
    for(auto [w,v] :adj[u]){
        if(taken[v] || v == p)continue;
        dfs2(v,u,c,og);
    }
}

void decompose(int u, int p){
    sub(u,p);
    int cent = centroid(u,p,subtree[u]);
    par[cent] = p;
    taken[cent] = 1;
    vector<int>c;
    dfs2(cent,p,c,cent);
    dp[cent] = c;
    for(auto [w,v] : adj[cent]){
        if(v==p || taken[v])continue;
        decompose(v,cent);
    }
}


int query(int u, int l){
    int res = upper_bound(all(dp[u]),l)-dp[u].begin();
    int x= u;
    while(par[x]!=-1){
        int di = l-d(par[x], u);
        res+=upper_bound(all(dp[par[x]]),di)-dp[par[x]].begin();
        res-=upper_bound(all(dp[x]),di-d(x,par[x]))-dp[x].begin();
        x = par[x];
    }
    return res;
}

void solve()
{
    int n,q;
    cin >> n >> q;
    adj.resize(n+1);
    up = vector<vector<int>>(n+1, vector<int>(21));
    dist = vector<int>(n+1);
    taken = vector<int>(n+1);
    subtree = vector<int>(n+1);
    par = vector<int>(n+1);
    depth = vector<int>(n+1);
    dp.resize(n+1);
    for(int i = 1;i<n;++i){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].pb({w, v});
        adj[v].pb({w, u});
    }
    // compute lca and distance array of the original tree
    // then find the centroid tree 
    //for each node in centroid tree also add a sorted vector of all the distances to the nodes in subtree
    compute(1,-1);
    decompose(1,-1);
    for(int i = 1;i<=n;++i){
        sort(all(dp[i]));
    }
    while(q--){
        int u,l;
        cin >> u >> l;
        cout << query(u,l) << endl;
    }
}   

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // freopen("error.txt", "w", stderr);
    // #endif

    int T=1;
    // cin >> T;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}