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
vector<int>par,dist;

int lca(int u, int v){
    if(dist[v]>dist[u])swap(u,v);
    int k = dist[u]-dist[v];
    for(int i = 0;i<=30;++i){
        if(k&(1ll<<i))u = up[u][i];
    }
    if(u==v)return u;
    for(int i = 30;i>=0;--i){
        if(up[u][i] != up[v][i]){
            u = up[u][i];
            v = up[v][i];
        }
    }
    return up[v][0];
}

void dfs(int u, int p = -1){
    for(int v : adj[u]){
        if(v==p)continue;
        dist[v] = dist[u]+1;
        par[v] = u;
        up[v][0] = u;
        for(int j = 1;j<=30;++j)up[v][j] = up[up[v][j-1]][j-1];
        dfs(v,u);
    }
}
void solve()
{
    int n,q;
    cin >> n >> q;
    up = vector<vector<int>>(n+1, vector<int>(31));
    adj.resize(n+1);
    par.resize(n+1);
    dist.resize(n+1);
    for(int i = 1;i<n;++i){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1);
    while(q--){
        int k;
        cin >> k;   
        vector<int>a(k);
        for(int &u : a)cin >> u;
        sort(all(a), [&](auto one, auto two){
            return dist[one] > dist[two];
        });
        bool ok = 1;
        for(int i = 1;i<k;++i){
            if(lca(a[0],a[i])!=a[i] && lca(a[0],par[a[i]])!=par[a[i]]){
                cout << "NO" << endl;
                ok = 0;
                break;
            }
        }
        if(ok)cout << "YES" << endl;
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