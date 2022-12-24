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



int n;
vector<vector<int>>adj;
vector<int>visited,id,sz;

void dfs(int u, vector<int>&p){
    visited[u] = 1;
    p.pb(u);
    for(int v : adj[u]){
        if(visited[v])continue;
        dfs(v,p);
    }
}

int root(int x){
    if(x==id[x])return x;
    return id[x] = root(id[x]);
}

bool merge(int u, int v){
    u = root(u);
    v = root(v);
    dbg(u,v);
    if(u==v)return 0;
    if(sz[v] > sz[u])swap(u,v);
    id[v] = u;
    sz[u]+=sz[v];
    return 1;
}
void solve()
{
    cin >> n;
    adj.resize(n+1);
    visited.resize(n+1);
    id.resize(n+1);
    sz.resize(n+1,1);
    iota(all(id),0ll);
    dbg(id);
    for(int i = 1;i<n;++i){
        int u,v;
        cin >> u>> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector<int>group;
    for(int i = 1;i<=n;++i){
        if(!visited[i]){
            vector<int>p;
            dfs(i,p);
            group.pb(p[0]);
        }
    }
    vector<pair<int,int>>rem;
    for(int i = 1;i<=n;++i){
        dbg(i,root(i));
    }
    set<pair<int,int>>taken;
    for(int i = 1;i<=n;++i){
        for(int v : adj[i]){
            if(merge(i,v)){
                taken.insert({i,v});
                taken.insert({v,i});
                continue;
            }
            if(taken.count({v,i}) || taken.count({i,v}))continue;
            rem.pb({i,v});
            taken.insert({i,v});
            taken.insert({v,i});

        }
    }
    cout << rem.size() << endl;
    for(int i = 0;i<(int)(group.size())-1;++i){
        cout << rem[i].first << ' ' << rem[i].second << ' ' << group[i] << ' ' << group[i+1] << endl;
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