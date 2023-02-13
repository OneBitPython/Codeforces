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

int n,m;
vector<vector<int>>adj,spa,back,res;
vector<int>visited,in,out,dp;
int t = 1;

void dfs(int u, int p){
    visited[u] = 1;
    in[u] = t;
    t++;
    for(int v : adj[u]){
        if(v==p)continue;
        if(visited[v]==2)continue;
        if(visited[v]==1){
            res[u].pb(v);
            back[u].pb(v);
            back[v].pb(u);
            continue;
        }
        res[u].pb(v);
        spa[u].pb(v);
        dfs(v,u);
    }
    visited[u] = 2;
    out[u] = t;
    t++;
}
int subtree(int u, int v){
    // is v in u's subtree?
    return in[v]>in[u] && out[v]<out[u];
}

void dfs2(int u){
    for(int v : back[u]){
        if(subtree(u,v))dp[u]--;
        else dp[u]++;
    }
    for(int v : spa[u]){
        dfs2(v);
        dp[u]+=dp[v];
    }
}

void solve()
{
    cin >> n >> m;
    adj.resize(n+1);
    spa.resize(n+1);
    back.resize(n+1);
    res.resize(n+1);
    visited.resize(n+1);
    in.resize(n+1);
    out.resize(n+1);
    dp.resize(n+1);
    for(int i = 1;i<=m;++i){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1,-1);
    dfs2(1);
    for(int i =2;i<=n;++i){
        if(dp[i]==0){
            cout << 0 << endl;
            return;
        }
    }
    for(int i = 1;i<=n;++i){
        for(int v : res[i]){
            cout << i << ' ' << v << endl;
        }
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