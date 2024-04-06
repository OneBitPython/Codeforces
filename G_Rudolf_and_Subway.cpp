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



void solve()
{
    int n,m;
    cin >> n >> m;
    vector<vector<int>>edges; 
    set<int>kk;

    for(int i = 1;i<=m;++i){
        int u,v;
        cin >> u >> v;
        int c;cin >> c;
        edges.pb({u,v,c});
        kk.insert(c);
    }
    map<int,int>idx;
    int cnt = 1;
    for(auto x : kk)idx[x] = cnt++;
    vector<vector<int>>adj(n+m+1);
    vector<int>vis(n+m+1),dist(n+m+1,1e18);
    for(auto x : edges){
        int u = x[0], v = x[1], c = x[2];
        c = idx[c];
        adj[u].pb(c+n);
        adj[v].pb(c+n);
        adj[c+n].pb(u);
        adj[c+n].pb(v);
    }

    int b,e;
    cin >> b >> e;
    queue<int>q;
    q.push(b);
    dist[b] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        if(vis[u])continue;
        vis[u] = 1;
        for(int v : adj[u]){
            if(dist[u]+1 < dist[v])q.push(v);
            dist[v] = min(dist[v], dist[u]+1);
        }
    }
    cout << dist[e]/2 << endl;
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