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

int n,m,k;
vector<int>a;
vector<vector<int>>adj;


int cycle(int u, vector<int>&visited, vector<vector<int>>&adj, int p){
    visited[u] = 1;
    for(int v : adj[u]){
        if(visited[v]==1){
            return 1;
        }else if(!visited[v]){
            if(cycle(v,visited,adj,u))return 1;
        }
    }
    visited[u] = 2;
    return 0;
}

bool pos(int x){
    vector<vector<int>>ad(n+1);
    vector<int>in(n+1);
    for(int i = 1;i<=n;++i){
        if(a[i] > x)continue;
        for(int v : adj[i]){
            if(a[v] > x)continue;
            ad[i].pb(v);
            in[v]++;
        }
    }
    // check if there exists a cycle in "ad"
    vector<int>visited(n+1);
    for(int i = 1;i<=n;++i){
        if(a[i] > x || visited[i])continue;
        if(cycle(i,visited,ad,-1)){
            return 1;
        }
    }
    // no cycle in ad so do a topo sort to find the longest path in ad and check if >= k
    queue<int>q;
    visited = vector<int>(n+1);
    vector<int>dp(n+1);
    for(int i = 1;i<=n;++i){
        if(a[i]<=x)dp[i] = 1;
        if(in[i]==0 && a[i]<=x)q.push(i);
    }
    while(!q.empty()){
        int u = q.front();
        q.pop();
        if(visited[u])continue;
        visited[u] = 1;
        for(int v : ad[u]){
            in[v]--;
            dp[v] = max(dp[v], dp[u]+1);
            if(in[v]==0)q.push(v);
        }
    }
    return *max_element(all(dp))>=k;
}

void solve()
{
    cin >> n >> m >> k;
    a.resize(n+1);
    adj.resize(n+1);
    for(int i = 1;i<=n;++i)cin >> a[i];
    for(int i = 1;i<=m;++i){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
    }
    int l = 1, r = 2e9;
    int res = 2e9;
    while(l <= r){
        int m = (l+r)/2;
        if(pos(m))res = m, r = m-1;
        else l = m+1;
    }
    if(res==2e9)res=-1;
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