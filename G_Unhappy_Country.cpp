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
    int n,m,q;
    cin >> n >> m >> q;
    vector<vector<pair<int,int>>>adj(n+1);
    vector<vector<int>>edges = {{0,0}};
    for(int i = 1;i<=m;++i){
        int u,v;
        cin >> u >> v;
        edges.pb({u,v});
    }
    vector<int>weight(m+1);
    for(int i = 1;i<=q;++i){
        int k;cin>>k;
        weight[k] = q-i+1;
    }
    for(int i =  1;i<=m;++i){
        int u = edges[i][0],v = edges[i][1],w = weight[i];
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }
    // do dijkstra from 1
    // first try to minimize distance, then try to minimize themaximum of edge weights
    priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
    pq.push({0,0,1});
    vector<pair<int,int>>dist(n+1,{1e9,1e9}); // stores {number of edges to node, maximum edge weight}
    dist[1] = {0,0};
    while(!pq.empty()){
        int u = pq.top()[2];
        int e = pq.top()[0], c = pq.top()[1];
        pq.pop();
        if(dist[u] != make_pair(e,c))continue;
        for(auto &[v,c] : adj[u]){
            int curr_dist = dist[v].first, new_dist = dist[u].first + 1;
            if(new_dist < curr_dist){
                dist[v] = {new_dist, max(c,dist[u].second)};
                pq.push({dist[v].first,dist[v].second, v});
            }else if(new_dist==curr_dist){
                curr_dist = dist[v].second, new_dist = max(c,dist[u].second);
                if(new_dist < curr_dist){
                    dist[v].second = new_dist;
                    pq.push({dist[v].first,dist[v].second,v});
                }
            }
        }
    }
    vector<int>res(q+5);
    for(int i= 1;i<=n;++i)res[q-dist[i].second+1]++;
    int ans = 0;
    for(int i = 1;i<=q;++i){
        ans+=res[i];
        cout << ans << endl;
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