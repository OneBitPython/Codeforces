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


void dfs(int u, int p, vector<int>&dp, vector<vector<pair<int,int>>>&adj, int b, bool m = 0){
    if(m){
        if(u==b)return;
    }
    for(auto &[v,c] : adj[u]){
        if(v==p)continue;
        dp[v] = dp[u]^c;
        dfs(v,u, dp, adj,b,m);
    }
}
void solve()
{
    int n,a,b;
    cin >> n >> a >> b;
    vector<vector<pair<int,int>>>adj(n+1);
    for(int i = 1;i<n;++i){
        int u,v, c;
        cin >> u >> v >> c;
        adj[u].pb({v, c});
        adj[v].pb({u, c});
    }
    // compute xor from node b to every other node
    // if you go from a to some other nodes, then you hve stop at b
    vector<int>dpb(n+1),dpa(n+1,-1);
    dpa[a] = 0;
    dfs(b,0,dpb,adj, -1, 0);
    dfs(a,0,dpa,adj, b, 1);
    if(dpb[a] == 0){
        cout << "YES" << endl;
        return;
    }
    // go from b to some other node
    set<int>dp;
    for(int i = 1;i<=n;++i){
        if(i==b)continue;
        dp.insert(dpb[i]);
        // you travel from i to b
        if(dpb[i]==0){
            cout << "YES" << endl;
            return;
        }
    }
    for(int i = 1;i<=n;++i){
        if(i == b)continue;
        // you travel from a to node i
        if(dp.count(dpa[i])){
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;

}   

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif

    int T=1;
    cin >> T;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}