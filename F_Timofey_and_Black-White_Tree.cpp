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

vector<int>subtree,taken,par,dist;
vector<vector<int>>adj,up;
void sub(int u, int p){
    subtree[u] = 1;
    for(int v : adj[u]){
        if(v==p || taken[v])continue;
        sub(v,u);
        subtree[u]+=subtree[v];
    }
}

int centroid(int u, int p, int n){
    for(int v : adj[u]){
        if(v==p || taken[v])continue;
        if(subtree[v] > (n/2))return centroid(v,u,n);
    }
    return u;
}

void decompose(int u, int p){
    sub(u,p);
    int cent = centroid(u,p,subtree[u]);
    par[cent] = p;
    taken[cent] = 1;
    for(int v : adj[cent]){
        if(v==p || taken[v])continue;
        decompose(v,cent);
    }
}
void dfs(int u, int p){
    for(int v : adj[u]){
        if(v==p)continue;
        up[v][0] = u;
        for(int j = 1;j<=20;++j)up[v][j] = up[up[v][j-1]][j-1];
        dist[v] = dist[u]+1;
        dfs(v,u);
    }
}
int lca(int u, int v){
    if(dist[v] > dist[u])swap(u,v);
    int k = dist[u]-dist[v];
    for(int i = 0;i<=20;++i){
        if(k&(1ll<<i))u = up[u][i];
    }
    if(u==v)return u;
    for(int i = 20;i>=0;--i){
        if(up[u][i] != up[v][i])u = up[u][i],v = up[v][i];
    }
    return up[v][0];
}
int d(int u, int v){
    return dist[u] + dist[v] - (2*dist[lca(u,v)]);
}
void prop(int u, vector<int>&node){
    int x = u;
    while(x!=-1){
        node[x] = min(node[x],d(u,x));
        x = par[x];
    }
}
int ans(int u, vector<int>&node){
    int x = u;
    int res = 1e18;
    while(x!=-1){
        res = min(res, node[x]+d(x,u));
        x = par[x];
    }
    return res;
}
void solve()
{
    int n,c;
    cin >> n >> c;
    vector<int>dp(n+1);
    dist = vector<int>(n+1);
    taken = vector<int>(n+1);
    up = vector<vector<int>>(n+1, vector<int>(21));
    subtree = vector<int>(n+1);
    for(int i = 1;i<n;++i)cin >> dp[i];
    par = vector<int>(n+1);
    adj = vector<vector<int>>(n+1);
    for(int i = 1;i<n;++i){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1,-1);
    decompose(1,-1);
    vector<int>node(n+1,1e18);
    prop(c,node);
    int res = 1e18;
    for(int i = 1;i<n;++i){
        res = min(res, ans(dp[i],node));
        prop(dp[i],node);
        cout << res << ' ';
    }
    cout << endl;

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
    cin >> T;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}