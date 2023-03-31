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
vector<int>a,sub,dist;
vector<vector<int>>adj;
int res = 0;

void dfs(int u, int p){
    sub[u] = a[u];
    vector<int>c;
    for(int v : adj[u]){
        if(v==p)continue;
        dist[v] = dist[u]+1;
        if(a[v])res+=(dist[v]*(k-1));
        dfs(v,u);
        sub[u]+=sub[v];
        c.pb(sub[v]);
    }
    int sum = accumulate(all(c),0ll);
    if(a[u])res-=(2*dist[u]*sum);
    for(int i = 0;i<(int)(c.size())-1;++i){
        sum-=c[i];
        res-=(2*dist[u]*c[i]*sum);
    }
}
void solve()
{
    cin >> n;
    adj.resize(n+1);
    sub.resize(n+1);
    a.resize(n+1);
    dist.resize(n+1);
    for(int i = 1;i<n;++i){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    cin >> k;
    for(int i = 1;i<=n;++i){
        int v;
        cin >> v;
        a[v] = 1;
    }
    dfs(1,-1);
    res+=(k*(k-1))/2;
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