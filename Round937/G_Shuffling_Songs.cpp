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

int got =0;
void dfs(int u, vector<int>&vis, vector<vector<int>>&adj){
    vis[u] = 1;
    got++;
    for(int v : adj[u]){
        if(vis[v])continue;
        dfs(v,vis,adj);
    }
}
void solve()
{
    int n;
    cin >> n;
    vector<pair<string,string>>a(n+1);
    for(int i = 1;i<=n;++i)cin >> a[i].first >> a[i].second;
    int res = 1;
    set<pair<int,int>>th;
    for(int i = 1;i<(1ll<<n);++i){
        map<string,vector<int>>cnt1,cnt2;
        vector<vector<int>>adj(n+1);
        int c = 0;
        th.clear();
        int use = 0;
        for(int j = 0;j<n;++j){
            if(i&(1ll<<j)){
                c++;
                for(auto x : cnt1[a[j+1].first]){
                    if(th.count({j+1,x}) || x== (j+1))continue;
                    adj[j+1].pb(x);
                    th.insert({j+1,x});
                    th.insert({x,j+1});
                    adj[x].pb(j+1);
                }
                for(auto x : cnt2[a[j+1].second]){
                    if(th.count({j+1,x}) || x == (j+1))continue;
                    adj[j+1].pb(x);
                    th.insert({j+1,x});
                    th.insert({x,j+1});
                    adj[x].pb(j+1);
                }
                cnt1[a[j+1].first].pb(j+1);
                cnt2[a[j+1].second].pb(j+1);
                use = j+1;
            }
        }
        vector<int>vis(n+1);
        got = 0;
        dfs(use,vis,adj);
        if(got==c)res = max(res, c);
    }
    
    cout << n-res << endl;
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