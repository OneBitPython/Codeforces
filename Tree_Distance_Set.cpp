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
vector<vector<int>>adj,up;
vector<int>depth,deg;


void comp(int u, int p){
    for(int v : adj[u]){
        if(v==p)continue;
        up[v][0] = u;
        depth[v] = depth[u]+1;
        for(int j = 1;j<=11;++j)up[v][j] = up[up[v][j-1]][j-1];
        comp(v,u);
    }
}


int lca(int u, int v){
    if(depth[u] < depth[v])swap(v,u);
    int k = depth[u]-depth[v];
    for(int j = 11;j>=0;--j){
        if(k&(1ll<<j))u = up[u][j];
    }
    if(u==v)return u;
    for(int j = 11;j>=0;--j){
        if(up[u][j]!=up[v][j])u = up[u][j], v = up[v][j];
    }
    return up[u][0];
}

int d(int u, int v){
    return depth[u]+depth[v] - 2*depth[lca(u,v)];
}
vector<int>path(int u, int v){
    int l = lca(u,v);
    vector<int>p1,p2;
    int x = u;
    while(x!=l){
        p1.pb(x);
        x = up[x][0];
    }
    x = v;
    while(x!=l){
        p2.pb(x);
        x = up[x][0];
    }
    p1.pb(l);
    reverse(all(p2));
    for(auto x : p2)p1.pb(x);
    return p1;
}
void solve()
{
    cin >> n;
    adj = vector<vector<int>>(n+1);
    up = vector<vector<int>>(n+1, vector<int>(12));
    depth = vector<int>(n+1);
    deg = vector<int>(n+1);

    for(int i = 1;i<n;++i){
        int u,v;
        cin >> u >> v;
        deg[u]++;
        deg[v]++;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    comp(1,-1);
    int u = 0, v = 0;
    vector<int>leaves = {1};
    for(int i = 1;i<=n;++i){
        if(deg[i]==1)leaves.pb(i);
    }
    int res = 0;
    for(int i = 0;i<leaves.size();++i){
        for(int j = i+1;j<leaves.size();++j){
            int x = d(leaves[i],leaves[j]);
            if(x > res){
                res = x;
                u = leaves[i];
                v = leaves[j];
            }
        }

    }
    if(depth[u] < depth[v])swap(v,u);

    vector<int>colors(n+1,-1);
    int red = 0, blue = 0;
    vector<int>c = path(u,v);
    int color = 1;
    if(res%2 == 0){
        for(auto x : c){
            colors[x] = color;
            color = 1-color;

        }
        colors[v] = 1-colors[u];
    }else{
        colors[u] = color;
        c.erase(c.begin());
        for(auto x : c){
            colors[x] = color;
            color = 1-color;
        }
        colors[v] = 1-colors[u];
    }
    red = count(all(colors),1);
    blue = count(all(colors),0);
    for(int i = 1;i<=n;++i){
        if(colors[i]==-1){
            if(red < blue)colors[i] = 1,red++;
            else colors[i] = 0, blue++;
        }
        if(colors[i]==1)cout << "R";
        else cout << "B";
    }
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