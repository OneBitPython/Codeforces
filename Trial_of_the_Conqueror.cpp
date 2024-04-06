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

int n,k;
vector<vector<int>>adj,up;
vector<int>dp,depth,deg,val;
vector<pair<int,int>>best;
void dfs(int u, int p){
    if(deg[u]==1 && u!=1)best[u].first = depth[u],best[u].second = u;

    for(int v : adj[u]){
        if(v==p)continue;
        up[v][0] = u;
        depth[v] = depth[u]+1;
        for(int j = 1;j<=20;++j){
            up[v][j] = up[up[v][j-1]][j-1];
        }
        dfs(v,u);
        if(best[v].first < best[u].first){
            best[u] = best[v];
        }
    }
}


int anc(int u, int k){
    for(int i= 0;i<=20;++i){
        if(k&(1ll<<i))u= up[u][i];
    }
    return u;
}
void comp2(int u, int p){
    val[u] = u;
    int get = k-(depth[best[u].second]-depth[u]);
    int kk = anc(u,max(get,0ll));
    kk = max(kk,1ll);
    val[u] = val[kk];
    for(int v : adj[u]){
        if(v==p)continue;
        comp2(v,u);
    }
}
void com(int u, int p){
    int res = 0;
    for(int v : adj[u]){
        if(v==p)continue;
        com(v,u);
        res = max(res, dp[v]);
    }
    dp[u] += res;
}

void solve()
{
    cin >> n >> k;
    adj = vector<vector<int>>(n+1);
    up = vector<vector<int>>(n+1, vector<int>(25));
    dp = vector<int>(n+1);
    depth = vector<int>(n+1);
    best = vector<pair<int,int>>(n+1, {1e18,0}); // stores the lowest depth leaf inside u's subtree
    deg = vector<int>(n+1);
    val = vector<int>(n+1); // stores the highest node you can to (by depth) from a given node
    for(int i = 1;i<n;++i){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
        deg[u]++;
        deg[v]++;
    }
    dfs(1,-1);
    comp2(1,-1);
    for(int i = 2;i<=n;++i){
        if(deg[i]==1){
            int par = max(1ll,anc(i,k));
            dp[val[par]]++;
        }
    }
    com(1,-1);
    cout << dp[1] << endl;
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