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

vector<int>imp,sub,a,par;
vector<vector<int>>adj;
vector<set<pair<int,int>>>dp;
void dfs(int u, int p){
    imp[u] = a[u];
    sub[u] = 1;
    
    for(int v : adj[u]){
        if(v==p)continue;
        dfs(v,u);
        par[v] = u;
        imp[u]+=imp[v];
        sub[u]+=sub[v];
    }
    for(int v : adj[u]){
        if(v==p)continue;
        dp[u].insert({sub[v],-v});
    }
}
pair<int,int>last(set<pair<int,int>>&x){
    return *(--x.end());
}
void solve()
{
    int n,q;
    cin >> n >> q;
    par.resize(n+1);
    a.resize(n+1);
    adj.resize(n+1);
    imp.resize(n+1);
    dp.resize(n+1);
    sub.resize(n+1);
    for(int i =1;i<=n;++i)cin >> a[i];
    for(int i = 1;i<n;++i){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1,-1);
    while(q--){
        int t,x;
        cin >> t >> x;
        if(t==1){
            cout << imp[x] << endl;
        }else{
            int curr = x;
            if(dp[x].empty())continue;
            x = par[x];
            int A = curr;
            pair<int,int>bb = last(dp[A]);
            int B = -bb.second;

            dp[x].erase({sub[A],-A});
            dp[A].erase(bb);
            sub[A]-=sub[B];
            sub[B]+=sub[A];
            imp[A]-=imp[B];
            imp[B]+=imp[A];
            par[A] = B;
            par[B] = x;
            dp[x].insert({sub[B],-B});
            dp[B].insert({sub[A],-A});
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