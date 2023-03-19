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


vector<vector<int>>adj,up;
vector<int>second,dp,par,dp2,dist;
void comp(int u, int p){
    for(int v : adj[u]){
        if(v==p)continue;

        up[v][0] = u;
        dist[v] = dist[u]+1;
        for(int i = 1;i<=20;++i)up[v][i] = up[up[v][i-1]][i-1];

        comp(v,u);
        par[v] = u;
        dp[u] = max(dp[u], dp[v]+1);
    }
    int c = 0, s = 0;
    for(int v : adj[u]){
        if(v==p)continue;
        c+=((dp[v]+1) == dp[u]);
        if((dp[v]+1) < dp[u])s = max(s, dp[v]+1);
    }
    if(c>1)second[u] = max(second[u], dp[u]);
    else second[u] = max(second[u], s);
 
}
int lca(int u, int v){
    if(dist[v] > dist[u])swap(u,v);
    int k = dist[u]-dist[v];
    for(int i= 0;i<=20;++i){
        if(k&(1ll<<i))u = up[u][i];
    }
    if(u==v)return u;
    for(int i = 20;i>=0;--i){
        if(up[u][i] != up[v][i])u = up[u][i], v = up[v][i];
    }
    return up[v][0];
}
void dfs(int u, int p){
    for(int v : adj[u]){
        if(v==p)continue;
        int use = dp[u];
        if((dp[v]+1)==dp[u])use = second[u];
        dp2[v] = max(dp2[u]+1,use+1);
        dfs(v,u);
    }
}
int d(int u, int v){
    return dist[u]+dist[v]-(2*dist[lca(u,v)]);
}
void solve()
{
    int n;
    cin >> n;
    up = vector<vector<int>>(n+1, vector<int>(21));
    dist = vector<int>(n+1);
    second = vector<int>(n+1);
    dp = vector<int>(n+1);
    dp2 = vector<int>(n+1);
    par = vector<int>(n+1);
    adj = vector<vector<int>>(n+1);
    for(int i = 1;i<n;++i){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dp2[1] = -1e18;
    comp(1,-1);
    dfs(1,-1);
    // dp max distance downwards, dp2 max distance upwards
    int q;
    cin >> q;
    for(int i = 1;i<=q;++i){
        int u,v;
        cin >> u >> v;
        int res = d(u,v);
        if(lca(u,v)==u){
            // you can go upwards from u or you can go downwards
            int use = dp[u];
            if(dp[v]+res == dp[u])use = second[u];
            res+=max({use,dp2[u],dp[v]});
        }else if(lca(u,v)==v){

            int use = dp[v];
            if(dp[u]+res == dp[v])use = second[v];
            res+=max({dp[u],use,dp2[v]});

        }else{
            res+=max(dp[u],dp[v]);
        }
        cout << res << endl;
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
    cin >> T;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}