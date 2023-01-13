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

int n,m;
vector<vector<int>>edges;
int root(int x, vector<int>&id){
    if(x==id[x]) return x;
    return id[x] = root(id[x]);
}
 
bool merge(int u, int v, vector<int>&id, vector<int>&sz){
    u = root(u,id);
    v = root(v,id);
    if(u==v)return 0;
    if(sz[v] > sz[u])swap(u,v);
    id[v] = u;
    sz[u]+=sz[v];
    return 1;
}

void dfs(int u, vector<bool>&visited, vector<vector<int>>&adj, vector<int>&order){
    visited[u] =1 ;
    for(int v : adj[u]){
        if(visited[v])continue;
        dfs(v,visited,adj,order);
    }
    order.pb(u);
}

void dfs2(int u, vector<bool>&visited, vector<vector<int>>&trans, vector<int>&SCC){
    visited[u] =1 ;
    for(int v : trans[u]){
        if(visited[v])continue;
        dfs2(v,visited,trans,SCC);
    }
    SCC.pb(u);
} 

bool pos(int x, vector<int>&ans){
    vector<vector<int>>adj(n+1),trans(n+1);
    for(auto e : edges){
        if(e[0]>x){
            adj[e[1]].pb(e[2]),trans[e[2]].pb(e[1]);

        }
        x   
    }
    // check if a cycle still exists using kosaraju
    vector<int>id(n+1);
    vector<int>sz(n+1, 1);
    iota(all(id),0ll);
    vector<int>order;
    vector<bool>visited(n+1);
    for(int i =1;i<=n;++i){
        if(!visited[i]){
            dfs(i,visited,adj,order);
        }
    }
    reverse(all(order));
    visited = vector<bool>(n+1);
    for(int i = 0;i<n;++i){
        int z = order[i];
        if(!visited[z]){
            vector<int>SCC;
            dfs2(z,visited,trans,SCC);
            if(SCC.size() >= 2)return 0;
        }
    }
    ans.clear();
    for(auto e : edges){
        if(e[0] <= x)ans.pb(e.back()+1);
        else break;
    }
    return 1;
}
void solve()
{
    cin >> n >> m;
    for(int i = 0;i<m;++i){
        int u,v;
        int c;
        cin >> u >> v >> c;
        edges.pb({c, u, v, i});
    }
    sort(all(edges));
    vector<int>ans;
    int l = 0, r = 1e9+1;
    while(l + 1 < r){   
        int m = (l+r)/2;
        if(pos(m,ans))r = m;
        else l = m;
    }
    sort(all(ans));
    cout << r << ' ' << ans.size() << endl;
    for(auto x : ans)cout << x << ' ' ;
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