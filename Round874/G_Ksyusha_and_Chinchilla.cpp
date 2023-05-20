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


vector<int>sub,par;
map<pair<int,int>,int>pos;
vector<vector<int>>adj;
void comp(int u, int p){
    sub[u] = 1;
    for(int v : adj[u]){
        if(v==p)continue;
        par[v] = u;
        comp(v,u);
        sub[u]+=sub[v];
    }
}
vector<int>res;
int dfs(int u, int p){
    if(sub[u]==3){
        sub[u] = 0;
        if(pos[{p,u}])res.pb(pos[{p,u}]);
        return 3;
    }
    int cut = 0;
    for(int v : adj[u]){
        if(v==p)continue;
        cut+=dfs(v,u);
    }
    sub[u]-=cut;
    if(sub[u]==3){
        sub[u] = 0;
        if(pos[{p,u}])res.pb(pos[{p,u}]);
        cut+=3;
    }
    return cut;
}
void solve()
{
    int n;
    cin >> n;
    adj = vector<vector<int>>(n+1);
    par = vector<int>(n+1);
    sub = vector<int>(n+1);
    vector<vector<int>>edges = {{0,0,0}};
    pos.clear();
    res.clear();
    for(int i = 1;i<n;++i){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
        edges.pb({u,v});
    }
    comp(1,-1);
    for(int i = 1;i<edges.size();++i){
        if(par[edges[i][0]] == edges[i][1])swap(edges[i][0],edges[i][1]);
        pos[{edges[i][0],edges[i][1]}] = i;
    }
    dfs(1,-1);
    if((res.size()+1)*3 != n){
        cout << -1 << endl;
        return;
    }
    cout << res.size() << endl;
    for(auto x: res)cout << x << ' ';
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