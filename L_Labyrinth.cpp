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


vector<vector<int>>adj,spa,back,up;
vector<int>par,visited,dist;
int n,m,s,node=-1,start=-1;

int lca(int u, int v){
    if(dist[v] > dist[u])swap(v,u);
    int k = dist[u]-dist[v];
    for(int j = 20;j>=0;--j){
        if(k&(1ll<<j))u = up[u][j];
    }
    if(u==v)return u;
    for(int j = 20;j>=0;--j){
        if(up[u][j] != up[v][j])u = up[u][j], v = up[v][j];
    }
    return up[v][0];
}

void dfs2(int u, int p){
    for(int v : back[u]){
        if(lca(v,u)==s && v!=s){
            node = u;
            start = v;
        }
    }   
    for(int v : spa[u]){
        if(v==p)continue;
        dfs2(v,u);
    }
}

void dfs(int u){
    visited[u] = 1;
    for(int v : adj[u]){
        if(visited[v]){
            back[u].pb(v);
            continue;
        }
        up[v][0] = u;
        for(int j = 1;j<=20;++j)up[v][j] = up[up[v][j-1]][j-1];
        dist[v] = dist[u]+1;
        par[v] = u;
        spa[u].pb(v);
        spa[v].pb(u);
        dfs(v);
    }
}



void solve()
{
    cin >> n >> m >> s;
    adj.resize(n+1);
    spa.resize(n+1);
    visited.resize(n+1);
    par.resize(n+1);
    back.resize(n+1);
    up = vector<vector<int>>(n+1, vector<int>(21));
    dist.resize(n+1);
    for(int i = 1;i<=m;++i){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
    }
    // create the dfs tree with s as the root
    // if there is a back edge from a node u to a node v and lca(u,v)==s then u is a valid ending point
    par[s] = -1;
    dfs(s);
    dfs2(s,-1);
    if(start==-1){
        cout << "Impossible" << endl;
        return;
    }

    vector<int>p1, p2;
    p2.pb(start);
    int curr = start;
    while(curr!=-1){
        p1.pb(curr);
        curr = par[curr];
    }
    curr = node;
    while(curr!=-1){
        p2.pb(curr);
        curr = par[curr];
    }
    reverse(all(p1));
    reverse(all(p2));
    cout << "Possible" << endl;
    cout << p1.size() << endl;
    for(auto x : p1)cout << x << ' ';
    cout << endl;
    cout << p2.size() << endl;
    for(auto x : p2)cout << x << ' ' ;
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