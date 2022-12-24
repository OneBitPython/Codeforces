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


vector<int>p,h,subtree,good,bad,sum;
vector<vector<int>>adj;
bool ok = 1;
void dfs(int u, int c = -1){
    subtree[u] = p[u];
    for(int v : adj[u]){
        if(v==c)continue;
        dfs(v,u);
        subtree[u]+=subtree[v];
    }
}
void dfs2(int u, int c = -1){
    // x + y = subtree[u]
    // x - y = h[i]
    // x = subtree[u]+h[u]/2
    // y = subtree[u]-x
    if((subtree[u] + h[u]) % 2 || (subtree[u]+h[u])<0)ok = 0;
    else{
        good[u] = (subtree[u]+h[u])/2;
        bad[u] = subtree[u]-good[u];
    }
    for(int v : adj[u]){
        if(v==c)continue;
        dfs2(v,u);
    }
}
void dfs3(int u, int c = -1){
    if(good[u] > subtree[u] || good[u] < 0 || bad[u] < 0 || bad[u]+good[u] != subtree[u] || good[u]-bad[u]!=h[u])ok = 0;
    for(int v: adj[u]){
        if(v==c)continue;
        if(good[v] > good[u])ok = 0;
        sum[u]+=good[v];
        dfs3(v,u);
    }
    if(sum[u] > good[u])ok = 0;
}
void solve()
{
    int n,m;
    cin >> n >> m;
    adj = vector<vector<int>>(n+1);
    p = vector<int>(n+1);
    sum = vector<int>(n+1);
    good = vector<int>(n+1);
    bad = vector<int>(n+1); 

    h = vector<int>(n+1);
    ok = 1;
    subtree = vector<int>(n+1);
    for(int i = 1;i<=n;++i)cin >> p[i];
    for(int i = 1;i<=n;++i)cin >> h[i];
    for(int i = 1;i<n;++i){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1);
    dfs2(1);
    dfs3(1);
    dbg(subtree,good,bad);
    if(!ok){
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
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