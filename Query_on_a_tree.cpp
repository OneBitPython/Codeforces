#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(c) c.begin(), c.end()
#define endl "\n"

const double PI=3.141592653589;




int n;
vector<vector<int>>up,adj;
vector<int>a,par,depth,sub,chainleader,chainpos,start;
 
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
        if(i < m)set(2*x+1,lx, m, i, v);
        else set(2*x+2, m, rx, i, v);
        seg[x] = max(seg[2*x+1],seg[2*x+2]);
    }
 
    void set(int i, int v){
        set(0,0,sz,i,v);
    }
 
    int sol(int x, int lx, int rx, int l, int r){
        if(rx <= l || lx >= r)return 0ll;
        if(lx >= l && rx <= r)return seg[x];
        int m = (lx+rx)/2;
        return max(sol(2*x+1, lx, m, l, r),sol(2*x+2, m, rx, l, r));
    }
 
    int sol(int l, int r){
        return sol(0,0,sz,l,r);
    }
};
void comp(int u, int p){
    sub[u] = 1;
    for(int v : adj[u]){
        if(v==p)continue;
        depth[v] = depth[u]+1;
        par[v] = u;
        up[v][0] = u;
        for(int j = 1;j<=20;++j)up[v][j] = up[up[v][j-1]][j-1];
        comp(v,u);
        sub[u] += sub[v];
    }
}

int lca(int u, int v){
    if(depth[v] > depth[u])swap(v,u);
    int k = depth[u]-depth[v];
    for(int j = 0;j<=20;++j){
        if(k&(1ll<<j))u = up[u][j];
    }
    if(u==v)return u;
    for(int j = 20;j>=0;--j){
        if(up[u][j] != up[v][j])u = up[u][j], v = up[v][j];
    }
    return up[v][0];
}

void dfs(int u, int p, int pos, int leader){
    chainleader[u] = leader;
    chainpos[u] = pos++;
    int heavy = -1;
    for(int v : adj[u]){
        if(v==p)continue;
        if(sub[v] >= ((sub[u]+1)/2))heavy = v;
    }
    if(heavy!=-1){
        dfs(heavy,u,pos,leader);
    }
    for(int v : adj[u]){
        if(v==p || v== heavy)continue;
        dfs(v,u,1,v);
    }
}
segtree st;
int solve(int u, int l){
    int res = 0;
    while(chainleader[u]!=chainleader[l]){
        res = max(res, st.sol(start[chainleader[u]],start[chainleader[u]]+chainpos[u]));
        u = up[chainleader[u]][0];
    }
    res = max(res, st.sol(start[chainleader[l]]+chainpos[l],start[chainleader[u]]+chainpos[u]));
    return res;
}

void solve()
{
    int n;
    cin >> n;
    adj = vector<vector<int>>(n+1);
    up = vector<vector<int>>(n+1, vector<int>(21));
    a = vector<int>(n+1);
    start = vector<int>(n+1);
    depth = vector<int>(n+1);
    par = vector<int>(n+1);
    sub = vector<int>(n+1);
    chainleader = vector<int>(n+1);
    chainpos = vector<int>(n+1);
    vector<vector<int>>edges;
    for(int i = 1;i<n;++i){
        int u,v,c;
        cin >> u >> v >> c;
        adj[u].pb(v);
        adj[v].pb(u);
        edges.pb({u,v,c});
    }
    comp(1,-1);
    for(auto x : edges){
        if(par[x[0]]==x[1])swap(x[0],x[1]);
        a[x[1]] = x[2];
    }
    dfs(1,-1,1,1);
    vector<int>sz(n+1);
    for(int i= 1;i<=n;++i)sz[chainleader[i]]++;
    int p = 1;
    for(int i = 1;i<=n;++i){
        if(!sz[i])continue;
        start[i] = p;
        p+=sz[i];
    }

    st.init(n+1);
    for(int i = 1;i<=n;++i)st.set(start[chainleader[i]]+chainpos[i]-1,a[i]);
    while(1){
        string s;
        cin >> s;
        if(s=="DONE")break;
        if(s=="CHANGE"){
            int i,c;
            cin >> i >> c;
            int u = edges[i-1][0], v= edges[i-1][1];
            if(par[u]==v)swap(v,u);
            a[v] = c;
            st.set(start[chainleader[v]]+chainpos[v]-1,c);
        }else{
            int u,v;
            cin >> u >> v;
            if(depth[v] > depth[u])swap(v,u);
            int l = lca(u,v);
            if(l==u)cout << solve(v,l) << endl;
            else cout << max(solve(v,l),solve(u,l)) << endl;
        }
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
    cin >> T;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}