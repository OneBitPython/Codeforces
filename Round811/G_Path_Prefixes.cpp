#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(c) c.begin(), c.end()
#define endl "\n"

const double PI=3.14159265358979323846264338327950288419716939937510582097494459230;


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


vector<vector<vector<int>>>adj;
vector<int>dist;
vector<int>costa, costb;
void dfs(int u, int p){
    for(auto t : adj[u]){
        int v = t[0];
        int a = t[1], b = t[2];
        if(v == p)continue;
        dist[v] = dist[u]+1;
        costa[v] = costa[u]+a;
        costb[v] = costb[u]+b;
        dfs(v, u);
    }
}

set<pair<int,int>>st; // stores b weights 
vector<int>res;
void dfs2(int u, int p){
    st.insert({costb[u], dist[u]});
    for(auto t : adj[u]){
        if(t[0] == p)continue;
        dfs2(t[0], u);        
    }
    int least = st.begin()->first;

    if(least >=  costa[u]){
    }else{
        auto val = st.lower_bound({costa[u], 1e18});
        --val;
        res[u] = val->second;
    }

    st.erase({costb[u], dist[u]});
}

void solve()
{
    int n;
    cin >> n;
    adj.resize(n+1);
    for(int i = 1;i<=n;++i)adj[i].clear();
    st.clear();
    dist.resize(n+1);
    costa.resize(n+1);
    costb.resize(n+1);
    res.resize(n+1);
    // dbg(adj, dist, costa, costb, res);
    for(int i = 2;i<=n;++i){
        int u,a,b;
        cin >> u >> a >> b;
        adj[u].pb({i, a, b});
    }
    dfs(1, -1);
    dfs2(1, -1);
    for(int i = 2;i<=n;++i)cout << res[i] << ' ';
    cout << endl;
}   

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    

    int T=1;
    cin >> T;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}