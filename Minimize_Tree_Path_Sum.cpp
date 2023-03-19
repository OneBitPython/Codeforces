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
vector<int>a,dist,par;
vector<vector<int>>up;

void comp(int u, int p = -1){
    for(auto &[v, w] : adj[u]){
        if(v==p)continue;
        dist[v] = dist[u]+1;
        par[v] = u;
        up[v][0] = u;
        for(int i = 1;i<=20;++i)up[v][i] = up[up[v][i-1]][i-1];
        comp(v,u);
    }
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

    for(auto &[v,w]: adj[u]){
        if(v==p)continue;
        dfs(v,u);
        a[u]+=a[v];
    }
}
void solve()
{
    int n,k,q;
    cin >> n >> k >> q;
    a = vector<int>(n+1);
    dist = vector<int>(n+1);
    up = vector<vector<int>>(n+1, vector<int>(21));
    adj = vector<vector<pair<int,int>>>(n+1);
    vector<int>weight(n+1);
    par = vector<int>(n+1);
    for(int i = 1;i<n;++i){
        int u,v,d;
        cin >> u >> v >> d;
        adj[u].pb({v, d});
        adj[v].pb({u, d});
    }
    comp(1,-1);
    for(int i =2;i<=n;++i){
        int v = par[i];
        for(auto x : adj[i]){
            if(x.first==v)weight[i] = x.second;
        }
    }
    for(int i = 1;i<=q;++i){
        int u,v;
        cin >> u >> v;
        a[u]++;
        a[v]++;
        a[lca(u,v)]-=2;
    }
    dfs(1,-1);
    vector<int>contrib;
    for(int i = 1;i<=n;++i)contrib.pb(weight[i]*a[i]);
    sort(all(contrib));
    int res = accumulate(all(contrib),0ll);
    int m = contrib.size();
    for(int i = m-1;i>=m-k;--i)res-=contrib[i];
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
    cin >> T;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}