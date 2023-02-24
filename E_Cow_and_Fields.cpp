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
    int n,m,k;
    cin >> n >> m >> k;
    vector<int>spec(n+1);
    vector<vector<int>>adj(n+1);
    for(int i = 1;i<=k;++i){
        int v;
        cin >> v;
        spec[v] = 1;
    }
    for(int i = 1;i<=m;++i){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector<bool>visited(n+1);
    vector<int>dist1(n+1, 1e18);
    dist1[1] = 0;
    queue<int>q;
    q.push(1);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        visited[u] = 1;
        for(int v : adj[u]){
            dist1[v] = min(dist1[v], dist1[u]+1);
            if(!visited[v])q.push(v);
        }
    }
    vector<int>dist2(n+1, 1e18);
    dist2[n] = 0;
    visited = vector<bool>(n+1);
    q.push(n);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        if(visited[u])continue;
        visited[u] = 1;
        for(int v : adj[u]){
            dist2[v] = min(dist2[v], dist2[u]+1);
            q.push(v);
        }
    }
    vector<pair<int,int>>distances;
    for(int i = 1;i<=n;++i){
        if(spec[i]){
            distances.pb({dist1[i], i});
        }
    }
    int res = 0;
    sort(all(distances));
    for(int i = 0;i<k-1;++i){
        // connect special node i and i+1
        // connect 1 -> i -> i+1 -> n
        int i1 = min(dist1[distances[i].second], dist1[distances[i+1].second]+1);
        res = max(res, min(dist1[n],i1+1+dist2[distances[i+1].second]));
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
    // cin >> T;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}