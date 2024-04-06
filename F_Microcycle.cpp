#include <bits/stdc++.h>
using namespace std;

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

int n,m;
vector<vector<pair<int,int>>>adj;
vector<int>id,sz;
int res = 1e8;
vector<vector<int>>curr;
int root(int x){
    if(x==id[x])return x;
    return id[x] = root(id[x]);
}

bool merge(int u, int v){
    int x = u, y = v;
    u = root(u);
    v= root(v);
    if(u==v)return 0;
    if(sz[v] > sz[u])swap(v,u);
    id[v] = u;
    curr[x].pb(y);
    curr[y].pb(x);
    return 1;
}

void dfs(int u, int p,vector<int>&ans){
    ans.pb(u);
    for(int v : curr[u]){
        if(v==p)continue;
        dfs(v,u,ans);
    }
}
void solve()
{
    cin >> n >> m;
    adj = vector<vector<pair<int,int>>>(n+1);
    id = vector<int>(n+1);
    sz = vector<int>(n+1);

    res = 1e8;
    vector<vector<int>>weights;
    curr = vector<vector<int>>(n+1);
    for(int i = 1;i<=m;++i){
        int u,v,w;
        cin >> u >> v >> w;
        weights.pb({w,u,v});
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }
    for(int i = 1;i<=n;++i)id[i] = i, sz[i] = 1;
    sort(all(weights));
    reverse(all(weights));

    vector<int>ans;
    vector<int>xxx;
    for(auto x : weights){
        if(!merge(x[1],x[2])){
            xxx = x;
            res = x[0];
            
        }
    }
    dfs(xxx[1],-1,ans);
    cout << res << ' ' << ans.size() << endl;
    for(auto x : ans)cout << x << ' ';
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