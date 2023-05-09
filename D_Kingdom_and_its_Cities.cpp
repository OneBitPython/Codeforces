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
vector<vector<int>>adj,up,vadj;
vector<int>in,depth,out,imp,have,took,par;
int t = 1;

bool upper(int u, int v){
    // is u above v?
    return in[u]<in[v] && out[u] > out[v];
}
void comp(int u, int p){
    in[u] = t;
    t++;
    for(int v : adj[u]){
        if(v==p)continue;
        depth[v] = depth[u]+1;
        up[v][0] = u;
        for(int j =1;j<=20;++j)up[v][j] = up[up[v][j-1]][j-1];
        comp(v,u);
    }
    out[u] = t;
    t++;
}

int lca(int u, int v){
    if(depth[v] > depth[u])swap(v,u);
    int k = depth[u] - depth[v];
    for(int i = 0;i<=20;++i){
        if(k&(1ll<<i)) u = up[u][i];
    }
    if(u==v)return u;
    for(int i = 20;i>=0;--i){
        if(up[u][i] != up[v][i])u = up[u][i],v = up[v][i];
    }
    return up[u][0];
}

bool cmp(int u, int v){
    return in[u] < in[v];
}

int dist(int u, int v){
    return depth[u]+depth[v]-2*depth[lca(u,v)];
}

int res = 0;
bool ok = 1;
void dfs(int u, int p){
    have[u] = imp[u];
    for(int v : vadj[u]){
        if(v==p)continue;
        if(imp[u] && imp[v] && dist(u,v)==1)ok = 0;
        dfs(v,u);
        have[u]+=have[v];
        took[u]+=took[v];
    }
    int val = have[u]-took[u];
    if(imp[par[u]])val++;
    if(val>=2){
        took[u] = have[u];
        res++;
    }
}

void solve(vector<int>&ver){
    int k = ver.size();
    sort(all(ver), cmp);
    for(int i = 0;i<k-1;++i)ver.pb(lca(ver[i],ver[i+1]));
    sort(all(ver),cmp);
    ver.erase(unique(all(ver)),ver.end());
    deque<int>st;
    st.push_back(ver[0]);

    vector<int>edges;
    for(int i = 1;i<ver.size();++i){
        while(st.size()>=2 && !upper(st.back(),ver[i])){
            par[st.back()] = st[st.size()-2];
            vadj[st[st.size()-2]].pb(st.back());
            edges.pb(st[st.size()-2]);
            st.pop_back();
        }
        st.push_back(ver[i]);
    }
    while(st.size()>=2){
        par[st.back()] = st[st.size()-2];
        vadj[st[st.size()-2]].pb(st.back());
        edges.pb(st[st.size()-2]);
        st.pop_back();
    }
    dbg(vadj);
    dfs(ver[0],-1);

    for(auto x: edges)vadj[x].clear();
    for(int i = 0;i<ver.size();++i)have[ver[i]] = took[ver[i]] = 0,par[i] = 0,imp[ver[i]] = 0;

}

void solve()
{
    cin >> n;
    adj.resize(n+1);
    up = vector<vector<int>>(n+1, vector<int>(21));
    in.resize(n+1);
    imp.resize(n+1);
    depth.resize(n+1);
    have.resize(n+1);
    took.resize(n+1);
    par.resize(n+1);
    out.resize(n+1);
    vadj.resize(n+1);
    for(int i = 1;i<n;++i){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    comp(1,-1);
    int q;
    cin >> q;
    while(q--){
        int k;
        cin >> k;
        vector<int>ver;
        dbg(ok);
        for(int i = 0;i<k;++i){
            int v;
            cin >> v;
            ver.pb(v);
            imp[v] = 1;
        }
        solve(ver);
        if(!ok)res = -1;
        cout << res << endl;
        
        res = 0;
        ok = 1;
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