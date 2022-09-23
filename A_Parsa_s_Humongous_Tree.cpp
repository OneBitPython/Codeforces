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

vector<pair<int,int>>a;
vector<vector<int>>adj;
vector<vector<int>>dp;
void dfs(int u, int p){
    for(int v : adj[u]){
        if(v==p)continue;
        dfs(v, u);
        dp[u][0] += max(dp[v][0]+(abs(a[u].first-a[v].first)), dp[v][1]+abs(a[u].first-a[v].second));
        dp[u][1] += max(dp[v][0] + (abs(a[u].second - a[v].first)), dp[v][1] + abs(a[u].second - a[v].second));
    }
}

void solve()
{
    int n;
    cin >> n;
    a.resize(n+1);
    adj.resize(n+1);
    dp = vector<vector<int>>(n+1, vector<int>(2));
    for(int i = 1;i<=n;++i)adj[i].clear();
    for(int i = 1;i<=n;++i)cin >>a[i].first >> a[i].second;
    for(int i = 0;i<n-1;++i){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1,-1);
    cout << max(dp[1][0],dp[1][1]) << endl;
}   

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    

    int T=1;
    cin >> T;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}