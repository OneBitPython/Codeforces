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
vector<int>subtree,cost,dp;
void dfs(int u, int p){
    subtree[u] = 1;
    for(int v : adj[u]){
        if(v == p)continue;
        dfs(v,u);
        subtree[u] = max(subtree[u], subtree[v]+1);
    }
}


void solve(){
    int n;
    cin >> n;
    subtree.resize(n+1);
    adj.resize(n+1);
    cost.resize(n+1);
    dp.resize(n+1);
    for(int i = 2;i<=n;++i){
        int p;
        cin >> p;
        adj[p].pb(i);
    }
    dfs(1,0);
    for(int i = 1;i<=n;++i){
        for(int v : adj[i])cost[i]+=subtree[v];
        if(adj[i].size() <= 1)cost[i]++;
    }
    int res = 0;
    for(int i = n;i>=1;--i){
        dp[i] = cost[i];
        int c2 = 0;
        for(int v : adj[i])c2+=dp[v];
        dp[i] = max(dp[i], c2);
        res = max(res, dp[i]);
    }
    cout << res;
}   

int32_t main()  
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    // freopen("optmilk.in", "r", stdin);
    // freopen("optmilk.out", "w", stdout);
    

    int T=1;
    // cin >> T;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}