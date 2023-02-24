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

int n,d;
vector<vector<int>>adj,up;
vector<pair<int,int>>order;
set<int>a,b;
vector<int>pos(2),dist;

void comp(int u, int p){
    for(int v : adj[u]){
        if(v==p)continue;
        up[v][0] = u;
        for(int j = 1;j<=20;++j)up[v][j] = up[up[v][j-1]][j-1];
        dist[v] = dist[u]+1;
        comp(v,u);
    }
}
void dfs(int u, int p){
    if(a.count(u))order.pb({0, u});
    if(b.count(u))order.pb({1, u});
    for(int v : adj[u]){
        if(v==p)continue;
        dfs(v,u);
    }
}

int lca(int u, int v ){
    if(dist[v] > dist[u])swap(u,v);
    int k = dist[u]-dist[v];
    for(int j = 0;j<=20;++j){
        if(k&(1ll<<j))u = up[u][j];
    }
    if(u==v)return u;
    for(int i = 20;i>=0;--i){
        if(up[u][i] != up[v][i])u = up[u][i], v = up[v][i];
    }
    return up[v][0];
}

int di(int u, int v){
    return dist[u]+dist[v]-2*dist[lca(u,v)];
}
int give(int u, int d){
    // move d places from u
    for(int j = 0;j<=20;++j){
        if(d&(1ll<<j))u = up[u][j];
    }
    return u;
}
int move(int u, int v){
    if(di(u,v)<=d)return v;
    // move v close to u
    if(lca(u,v)==v)return give(u,d);
    if(lca(u,v)==u){
        int k = di(u,v);
        return give(v,k-d);
    }
    int one = di(u,lca(u,v));
    if(one >= d)return give(u,d);
    int left = d-one;
    int rem = di(v,lca(u,v))-left;
    return give(v,rem);
}

void solve()
{
    cin >> n >> d;
    adj.resize(n+1);
    up = vector<vector<int>>(n+1, vector<int>(21));
    dist.resize(n+1);
    for(int i = 1;i<n;++i){
        int  u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    comp(1,-1);
    int c__;
    cin >> c__;
    for(int i = 0;i<c__;++i){
        int v;
        cin >> v;
        a.insert(v);
    }
    int c_;
    cin >> c_;
    for(int i = 0;i<c_;++i){
        int v;
        cin >> v;
        b.insert(v);
    }
    dfs(1,-1);
    for(int v : {0,1})pos[v] = 1;
    int res = 0;
    int curr_dist = 0;
    order.pb({0,1});
    order.pb({1, 1});
    for(auto x : order){
        int piece = x.first, go = x.second;
        if(pos[piece]==go)continue;
        res+=di(pos[piece],go);
        pos[piece] = go;
        int k = move(pos[piece], pos[1-piece]);
        res+=di(k,pos[1-piece]);
        pos[1-piece] = k;
        pos[piece] = go;
    }
    cout << res << endl;
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