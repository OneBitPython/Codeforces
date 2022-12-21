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

vector<vector<int>>adj;
vector<int>dist;
vector<vector<int>>up;
set<int>a;
vector<int>cnt;
int res = 0;
void dfs(int u, int p = -1){
    if(a.count(u))cnt[u] = 1;
    for(int v : adj[u]){

        if(v==p)continue;
        up[v][0] = u;
        dist[v] = dist[u]+1;
        for(int j = 1;j<=30;++j)up[v][j] = up[up[v][j-1]][j-1];
        dfs(v,u);
        cnt[u]+=cnt[v];
    }
}

void dfs2(int u, int p){
    for(int v : adj[u]){
        if(cnt[v]==0)continue;
        if(v==p)continue;
        res+=2;
        dbg(v,u);
        dfs2(v,u);
    }
}
int lca(int u, int v){
    if(dist[v] > dist[u])swap(u,v);
    int k = dist[u]-dist[v];
    for(int i = 0;i<=30;++i){
        if(k&(1ll<<i))u = up[u][i];
    }
    if(u==v)return u;
    for(int j = 30;j>=0;--j){
        if(up[u][j] != up[v][j])u = up[u][j], v= up[v][j];
    }
    return up[v][0];
}
int d(int x, int y){
    return dist[x] + dist[y] - (2*dist[lca(x,y)]);
}
void solve()
{
    int n,k;
    cin >> n >> k;
    adj = vector<vector<int>>(n+1);
    dist = vector<int>(n+1);
    up = vector<vector<int>>(n+1, vector<int>(31));
    cnt = vector<int>(n+1);     
    int x,y;
    cin >> x >> y;
    res = 0;
    a.clear();
    for(int i= 0;i<k;++i){
        int v;
        cin >> v;

        a.insert(v);
    }
    
    for(int i= 1;i<n;++i){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(x,-1);
    dfs2(x,-1);
    int ans = 1e18;
    for(auto X: a){
        // you can end at x and then go to y
        ans = min(ans, res-dist[X]+d(X,y));
    }
    cout << ans << endl;
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