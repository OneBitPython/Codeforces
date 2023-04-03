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
vector<int>a,par,dist,res;
map<int,int>cnt,conv,back;
map<pair<int,int>,int>pos;
struct segtree{
    vector<pair<int,int>>seg;
    int sz = 1;
    void init(int n){
        while(sz < n)sz*=2;
        seg = vector<pair<int,int>>(sz*2);
    }


    pair<int,int>merge(pair<int,int>a,pair<int,int>b){
        if(a.first > b.first)return a;
        if(a.second > b.second)return a;
        return b;
    }

    void set(int x, int lx, int rx, int i, pair<int,int>v){
        if(rx-lx==1){
            seg[x] = v;
            return;
        }
        int m = (lx+rx)/2;
        if(i < m)set(2*x+1,lx,m,i,v);
        else set(2*x+2,m,rx,i,v);
        seg[x] = merge(seg[2*x+1],seg[2*x+2]);
    }

    void set(int i, pair<int,int>v){
        set(0,0,sz,i,v);
    }

    pair<int,int>sol(int x, int lx, int rx, int l, int r){
        if(lx >= l && rx <= r)return seg[x];
        if(rx <= l || lx >= r)return {0,0};
        int m = (lx+rx)/2;
        return merge(sol(2*x+1,lx,m,l,r),sol(2*x+2, m, rx, l, r));
    }

    pair<int,int> sol(int l, int r){
        return sol(0,0,sz,l,r);
    }
};
void comp(int u, int p){
    for(int v : adj[u]){
        if(v==p)continue;
        dist[v] = dist[u]+1;
        par[v] = u;
        up[v][0] = u;
        for(int j = 1;j<=20;++j)up[v][j] = up[up[v][j-1]][j-1];
        comp(v,u);
    }
}
int lca(int u, int v){
    if(dist[v] > dist[u])swap(u,v);
    int k = dist[u]-dist[v];
    for(int j = 0;j<=20;++j){
        if(k&(1ll<<j))u = up[u][j];
    }
    if(u==v)return u;
    for(int j = 20;j>=0;--j){
        if(up[u][j] != up[v][j])u = up[u][j],v=up[v][j];
    }
    return up[v][0];
}

void add(int u, int p, vector<int>&visited, segtree &st,map<int,int>&run){
    visited[u] = 1;
    run[a[u]]++;
    if(run[a[u]]>=2)res[pos[{u,par[u]}]] = max(res[pos[{u,par[u]}]], a[u]);
    int left = cnt[a[u]]-run[a[u]];
    if(left>=2){
        st.set(conv[a[u]],make_pair(2,conv[a[u]]));
    }else{
        st.set(conv[a[u]],make_pair(0,conv[a[u]]));
    }
    for(int v : adj[u]){
        if(v==p || visited[v])continue;
        add(v,u,visited,st,run);
    }
}
void perf(int u, int p){
    segtree st;
    st.init(n+1);
    map<int,int>run;
    vector<int>visited(n+1);
    for(int i = 1;i<=n;++i){
        if(cnt[back[i]]>=2)st.set(i,make_pair(2,i));
        else st.set(i,make_pair(0,i));
    }

    while(u!=p){
        add(u,par[u],visited,st,run);
        pair<int,int>c = st.sol(0,n+1);
        int ans = back[c.second];
        if(c.first==0)ans = 0;
        res[pos[{u,par[u]}]] = max(ans,res[pos[{u,par[u]}]]);
        u = par[u];
    }
}
void solve()
{
    cin >> n;
    adj.resize(n+1);
    a.resize(n+1);
    up = vector<vector<int>>(n+1, vector<int>(21));
    par.resize(n+1);
    dist.resize(n+1);
    res.resize(n+1,-1);
    for(int i = 1;i<n;++i){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
        pos[{u,v}] = i;
        pos[{v,u}] = i;
    }
    for(int i = 1;i<=n;++i){
        cin >> a[i];
        cnt[a[i]]++;
    }
    int mx = 0,c=0;
    set<int>d;
    for(int i =1;i<=n;++i){
        d.insert(a[i]);
        if(cnt[a[i]]>=2){
            mx = max(mx,a[i]);
            c = cnt[a[i]];
        }
    }
    int g = 1;
    
    for(auto x : d){
        conv[x] = g;
        back[g] = x;
        g++;
    }
    if(c>=3 || mx==0){
        for(int i = 1;i<n;++i)cout << mx<< ' ';
        return;
    }
    // c== 2
    int u = 0, v = 0;
    for(int i =1;i<=n;++i){
        if(a[i]==mx && v!=0)u = i;
        else if(a[i]==mx)v = i;
    }
    comp(1,-1);
    perf(u,lca(u,v));
    perf(v,lca(u,v));
    for(int i = 1;i<n;++i){
        if(res[i]==-1)res[i]=mx;
        cout <<res[i] << endl;
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