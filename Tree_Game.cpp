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
vector<int>a,dp1,dp2,depth,leaf,leaf2;
void comp(int u, int p, vector<int>&dp){
    dp[u] += a[u];
    for(int v : adj[u]){
        if(v==p)continue;
        dp[v]+=dp[u];
        depth[v] = depth[u]+1;
        comp(v,u,dp);
    }
}
deque<int>st;
int res = 0;
int n,x,y;
void best(int u, int p,int d, int val, vector<int>&a, int de){
    if(d>de)return;
    if(dp2[u]<st[d])val++;
    a[u] = val;
    for(int v : adj[u]){
        if(v==p)continue;
        best(v,u,d+1,val,a,de);
    }
}

void dfs(int u, int p, int d){
    st.push_back(dp1[u]);
    vector<int>a(n+1);
    best(y,-1,0,0,a,d);
    int r = 1e18;
    for(int i = 1;i<=n;++i){
        if(depth[i]>d)continue;
        if(depth[i]==d || leaf[i])r = min(r, a[i]);
    } 
    if(leaf2[u])res = max(res, r);

    for(int v : adj[u]){
        if(v==p)continue;
        // find best path for bob
        dfs(v,u,d+1);
    }
    st.pop_back();
}
void solve()
{
    cin >> n >> x >> y;
    adj = vector<vector<int>>(n+1);
    a = vector<int>(n+1);
    leaf = vector<int>(n+1);
    leaf2 = vector<int>(n+1);
    depth = vector<int>(n+1);
    res = 0;
    dp1 = vector<int>(n+1);
    dp2 = vector<int>(n+1);
    vector<int>deg(n+1);
    while(!st.empty())st.pop_front();
    for(int i = 1;i<=n;++i)cin >> a[i],adj[i].clear();
    for(int i = 1;i<n;++i){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        deg[u]++;
        deg[v]++;
        adj[v].pb(u);
    }
    for(int i = 1;i<=n;++i){
        if(i==y)continue;
        if(deg[i]==1)leaf[i] = 1;
    }
    for(int i = 1;i<=n;++i){
        if(i==x)continue;
        if(deg[i]==1)leaf2[i] = 1;
    }
    /*
    fix the path that alice goes through by rooting her tree at x then find the best path for bob
    */
    comp(x,-1,dp1);
    depth[y] = 0;
    comp(y,-1,dp2);
    dfs(x,-1,0);
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