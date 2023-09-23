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

vector<vector<int>>spa, back;
vector<vector<pair<int,int>>>adj;
vector<int>par,vis;
void dfs(int u, int p){
    vis[u] = 1;
    for(auto &[v,i] : adj[u]){
        if(v==p || vis[v]==2)continue;
        if(vis[v]==1){
            back[v].pb(u);
        }else{
            spa[u].pb(v);
            spa[v].pb(u);
            par[v] = u;
            dfs(v,u);
        }
    }
    vis[u] = 2;
}
void solve()
{
    int n,m;
    cin >> n >> m;
    adj = vector<vector<int>>(n+1);
    spa = vector<vector<int>>(n+1);
    back = vector<vector<int>>(n+1);
    vis = vector<int>(n+1);
    par = vector<int>(n+1);
    map<pair<int,int>,int>pos;
    for(int i = 1;i<=m;++i){
        int u,v; cin >> u >> v;
        adj[u].pb({v,i});
        adj[v].pb({u,i});
        pos[{u,v}] = pos[{v,u}] = i;
    }
    dfs(1,-1);
    vector<char>res(m+1,'0');
    for(int i = 1;i<=n;++i){
        for(int v : spa[i]){
            res[pos[{i,v}]] = '1';
        }
    }
    int mx = 0;
    for(int i = 1;i<=n;++i)mx = max(mx,(int)back[i].size());
    assert(mx <= 4);
    for(int u = 1;u<=n;++u){
        for(int v : back[u]){
            for(int w : back[v]){
                bool ok = 0;
                for(int j = 0;j<back[u].size();++j)ok|=(back[u][j]==w);
                if(ok){
                    swap(res[pos[{w,par[w]}]], res[pos[{u,w}]]);
                }
            }
        }
    }
    for(int i= 1;i<=m;++i)cout << res[i];
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