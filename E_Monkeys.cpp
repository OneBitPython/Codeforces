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

vector<int>res,conn;
vector<int>id,sz;
vector<set<int>>dp;
int root(int x){
    if(id[x]==x)return x;
    return id[x] = root(id[x]);
}
void merge(int u, int v, int c){
    u = root(u);
    v = root(v);
    if(u==v)return;
    if(conn[u] && conn[v])return;
    if(sz[v] > sz[u])swap(u,v);
    if(conn[u]){
        for(int x : dp[v]){
            res[x] = c;
            conn[x] = 1;
            dp[u].insert(x);
        }
        dp[v].clear();
        id[v] = u;
        sz[u]+=sz[v];
    }else if(conn[v]){
        for(int x : dp[u]){
            res[x] = c;
            conn[x] = 1;
            dp[v].insert(x);
        }
        dp[u].clear();
        id[u] = v;
        sz[v]+=sz[u];
    }else{
        for(int x : dp[v]){
            dp[u].insert(x);
        }
        id[v] = u;
        sz[u]+=sz[v];
    }
}


void solve()
{
    int n,m;
    cin >> n >> m;
    set<vector<int>>edges;
    res.resize(n+1,-1);
    id.resize(n+1);
    dp.resize(n+1);
    sz.resize(n+1);
    conn.resize(n+1); // shows whether this group contains node 1
    vector<vector<int>>a(n+1,vector<int>(3));
    conn[1] = 1;
    for(int i = 1;i<=n;++i){
        id[i] = i;
        sz[i] = 1;
        dp[i].insert(i);
        int l,r;
        cin >> l >> r;
        a[i][1] = l;
        a[i][2] = r;
        if(l!=-1)edges.insert({1, i, l});
        if(r!=-1)edges.insert({2, i, r});
    }
    vector<pair<int,int>>queries;
    for(int i = 1;i<=m;++i){
        int u,v;
        cin >>u >> v;
        edges.erase({v,u,a[u][v]});
        queries.pb({u,a[u][v]});
    }
    for(auto x : edges){
        merge(x[1],x[2],-1);
    }
    for(int i = m-1;i>=0;--i){
        merge(queries[i].first,queries[i].second,i);
    }
    for(int i = 1;i<=n;++i)cout << res[i] << endl;
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