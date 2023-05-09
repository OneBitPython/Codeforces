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


vector<vector<int>>adj,up;
vector<int>id,visited,depth;

int root(int x){
    if(id[x]==x)return id[x];
    return id[x] = root(id[x]);
}

void merge(int u, int v){
    u = root(u);
    v = root(v);
    if(u==v)return;
    id[u] = v;
}

void add(int u, int v, int c){
    u = root(u);
    v = root(v);
    if(u==v)return;
    adj[c].pb(u);
    adj[c].pb(v);
    merge(u,c);
    merge(v,c);
}

void dfs(int u, int p){
    visited[u] = 1;
    for(int v : adj[u]){
        if(visited[v])continue;
        depth[v] = depth[u]+1;
        up[v][0] = u;
        for(int j = 1;j<=20;++j)up[v][j] = up[up[v][j-1]][j-1];
        dfs(v,u);
    }
}

int lca(int u, int v){
    if(u==0)return v;
    if(v==0)return u;
    if(depth[v] > depth[u])swap(u,v);
    int k = depth[u] - depth[v];
    for(int i = 0;i<=20;++i){
        if(k&(1ll<<i))u = up[u][i];
    }
    if(u==v)return u;
    for(int i = 0;i<=20;++i){
        if(up[u][i] != up[v][i])u = up[u][i], v = up[v][i];
    }
    return up[v][0];
}

struct segtree{
    int sz = 1;
    vector<int>seg;
    void init(int n){
        while(sz < n)sz*=2;
        seg.resize(sz*2);
    }
    void set(int x, int lx, int rx, int i, int v){
        if(rx-lx==1){
            seg[x] = v;
            return;
        }
        int m = (lx+rx)/2;
        if(i < m)set(2*x+1, lx, m, i, v);
        else set(2*x+2, m,rx, i, v);
        seg[x] = lca(seg[2*x+1], seg[2*x+2]);
    }
    void set(int i, int v){
        set(0,0,sz,i,v);
    }

    int sol(int x, int lx, int rx, int l, int r){
        if(lx >= l && rx <= r)return seg[x];
        if(rx <= l || lx >= r)return 0ll;
        int m = (lx+rx)/2;
        return lca(sol(2*x+1,lx,m,l,r),sol(2*x+2,m,rx,l,r));
    }

    int sol(int l, int r){
        return sol(0,0,sz,l,r);
    }
};

void solve()
{
    int n,m,q;
    cin >> n >> m >> q;
    adj = vector<vector<int>>(n+m+1);
    up = vector<vector<int>>(n+m+1, vector<int>(21));
    vector<vector<int>>edges;
    visited = vector<int>(n+m+1);
    depth = vector<int>(n+m+1);    
    id = vector<int>(n+m+1);

    for(int i = 1;i<=m;++i){
        int u,v;
        cin >> u >> v;
        edges.pb({u,v,i});
    }
    for(int i = 1;i<=n+m;++i)id[i] = i;
    for(auto x : edges){
        add(x[0],x[1],x[2]+n);
    }
    for(int i= 1;i<=n+m;++i){
        if(!visited[root(i)]){
            dfs(root(i),-1);
        }
    }
    segtree st;
    st.init(n+m+1);
    for(int i = 1;i<=n+m;++i)st.set(i,i);
    while(q--){
        int l,r;
        cin >> l >> r;
        if(l == r){
            cout << 0 << ' ';
            continue;      
        }
        cout << st.sol(l,r+1)-n << ' ';
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