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
    // compute the distance of each node with a[k]  as source
    // also compute number of paths with min cost
    vector<vector<int>>adj(n+1),trans(n+1);
    for(int i= 1;i<=m;++i){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        trans[v].pb(u);
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    int k;
    cin >> k;
    vector<int>a(k+1);
    for(int i = 1;i<=k;++i)cin >> a[i];
    pq.push({0, a.back()});
    vector<int>dist(n+1,1e18),cnt(n+1),visited(n+1);
    dist[a.back()] = 0;
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        if(visited[u])continue;
        visited[u] = 1;
        for(int v : trans[u]){
            int curr_dist = dist[v], new_dist = dist[u]+1;
            if(new_dist < curr_dist){
                pq.push({new_dist, v});
                dist[v] = new_dist;
            }
        }
    }
    int mn = 0, mx = 0;
    for(int i = 1;i<k;++i){
        int left = k-i;
        if(dist[a[i+1]]>dist[a[i]]-1)mn++;
        for(int v : adj[a[i]]){
            if(v==a[i+1])continue;
            if(dist[v]+1 == dist[a[i]]){
                mx++;
                break;
            }
        }
    }
    cout << mn << ' ' << mx << endl;
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