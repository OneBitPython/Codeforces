#include <bits/stdc++.h>
using namespace std;


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
vector<vector<pair<int,int>>>adj;
vector<vector<int>>adj2,trans2;
vector<int>order,vis,deg,group;
void dfs(int u){
    vis[u] = 1;
    for(int v : adj2[u]){
        if(vis[v])continue;
        dfs(v);
    }
    order.pb(u);
}

void dfs(int u,vector<int>&scc){
    vis[u] = 1;
    for(int v : trans2[u]){
        if(vis[v])continue;
        dfs(v,scc);
    }
    scc.pb(u);
}

bool pos(int x){
    order.clear();
    for(int i = 1;i<=n;++i)adj2[i].clear(),trans2[i].clear();

    for(int i = 1;i<=n;++i){
        vis[i] = 0;
        deg[i] = 0;
        group[i] = 0;
        for(auto &[v,c] : adj[i]){
            adj2[i].pb(v);
            trans2[v].pb(i);

            if(c <= x){
                adj2[v].pb(i);
                trans2[i].pb(v);
            }
        }
    }

    for(int i = 1;i<=n;++i){
        if(!vis[i])dfs(i);
    }
    for(int i = 1;i<=n;++i)vis[i] = 0;

    int g = 1;

    for(int i = order.size()-1;i>=0;--i){
        if(!vis[order[i]]){
            vector<int>scc;
            dfs(order[i],scc);
            for(auto x :scc)group[x] = g;
            g++;
        }
    }
    vector<int>took(n+1);
    set<pair<int,int>>edges;
    for(int i = 1;i<=n;++i){
        for(int v : adj2[i]){
            if(group[i]!=group[v]){
                edges.insert({group[i],group[v]});
            }
        }
    }
    for(auto [x,y] : edges)deg[y]++;

    took = vector<int>(n+1);
    int c= 0;
    for(int i = 1;i<=n;++i){
        if(took[group[i]])continue;
        took[group[i]] = 1;
        if(deg[group[i]] == 0)c++;
    }

    if(c==1)return 1;
    return 0;
}

void solve()
{
    cin >> n >> m;
    adj = vector<vector<pair<int,int>>>(n+1);
    group = vector<int>(n+1);
    vis = vector<int>(n+1);
    deg = vector<int>(n+1);
    trans2 = vector<vector<int>>(n+1);
    adj2 = vector<vector<int>>(n+1);

    for(int i = 1;i<=m;++i){
        int u,v,c;
        cin >> u >> v>> c;
        adj[u].pb({v,c});

    }

    int l = 0, r = 1e9+5;
    int res = -1;
    while(l <= r){
        int m = (l+r)/2;
        if(pos(m))r = m-1, res = m;
        else l = m+1;
    }
    cout << res << endl;
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