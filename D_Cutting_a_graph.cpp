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

vector<int>id,sz;
int root(int x){
    if(id[x]==x)return x;
    return id[x] = root(id[x]);
}
void merge(int u, int v){
    u = root(u);
    v = root(v);
    if(u==v)return;
    if(sz[v] > sz[u])swap(u,v);
    id[v] = u;
    sz[u]+=sz[v];
}

int same(int u, int v){
    return root(u)==root(v);
}
void solve()
{
    int n,m,k;
    cin>> n >> m >> k;
    id.resize(n+1);
    sz.resize(n+1,1);
    iota(all(id),0ll);

    set<pair<int,int>>edges;
    for(int i = 1;i<=m;++i){
        int u,v;
        cin >> u >> v;
        edges.insert({v, u});
        edges.insert({u, v});
    }
    vector<vector<int>>queries;
    for(int i = 1;i<=k;++i){
        string s;
        int u,v;
        cin >> s >>u >> v;
        if(s=="ask")queries.pb({1, u, v});
        else{
            edges.erase({u,v});
            edges.erase({v, u});
            queries.pb({2,u,v});
        }
    }
    for(auto x : edges)merge(x.first,x.second);
    vector<int>res;
    for(int i = k-1;i>=0;--i){
        int u = queries[i][1], v = queries[i][2];
        if(queries[i][0] == 1){
            res.pb(same(u,v));
        }else merge(u,v);
    }
    reverse(all(res));
    for(auto x : res)cout << (x?"YES":"NO") << endl;
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