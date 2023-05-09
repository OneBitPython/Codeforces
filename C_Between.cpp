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
vector<int>visited;

void dfs(int u){
    visited[u] = 1;
    for(int v : adj[u]){
        if(visited[v])continue;
        dfs(v);
    }
}
void add(vector<int>&res, vector<int>&a){
    for(auto x : a)res.pb(x);
}
void solve()
{
    int n,m;
    cin >> n >> m;
    adj = vector<vector<int>>(n+1);
    vector<int>conn,notconn;
    visited = vector<int>(n+1);
    vector<vector<int>>rev(n+1);
    for(int i = 1;i<=m;++i){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        rev[v].pb(u);
    }
    for(int i= 2;i<=n;++i){
        int have = 0;
        for(int v : adj[i]){
            if(v==1)have = 1;
        }
        if(have)conn.pb(i);
        else notconn.pb(i);
    }
    if(n==1){
        cout << "FINITE\n1\n1" << endl;
        return;
    }
    for(int i = 2;i<=n;++i){
        // check if there exists a path from i to 1
        visited = vector<int>(n+1);
        dfs(i);
        if(!visited[1]){
            cout << "INFINITE" << endl;
            return;
        }
    }
    cout << "FINITE\n";
    
    vector<int>visited(n+1);
    queue<int>q;
    vector<int>dist(n+1,1e18);
    q.push(1);
    dist[1] = dist[0] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        if(visited[u])continue;
        visited[u] = 1;
        for(int v : rev[u]){
            dist[v] = min(dist[v],dist[u]+1);
            q.push(v);
        }
    }
    vector<vector<int>>dp(n+1);
    for(int i = 1;i<=n;++i){
        dp[dist[i]+1].pb(i);
    }
    dbg(dp);
    vector<int>res;
    int val = *max_element(all(dist))+1;
    for(int i = val;i>=2;--i){
        int t = val-i+1;
        add(res,dp[val]);
        for(int j = val-t;j<=val-1;++j)add(res,dp[j]);
    }
    add(res,dp[val]);
    cout << res.size() << endl;
    for(auto x : res)cout << x << ' ';
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