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


void dfs(int u, int p, vector<int>&dist,vector<vector<int>>&adj){
    for(int v : adj[u]){
        if(v==p)continue;
        dist[v] = dist[u]+1;
        dfs(v,u,dist,adj);
    }
}

void solve()
{
    int n,k;
    cin >> n >> k;
    vector<vector<int>>adj(n+1);
    vector<int>indegree(n+1);
    vector<int>x(k);
    for(int &u : x)cin >> u;
    for(int i = 0;i<n-1;++i){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
        indegree[u]++;
        indegree[v]++;
    }
    vector<int>leaves;
    for(int i = 1;i<=n;++i){
        if(indegree[i] == 1 && i!=1)leaves.pb(i);
    }
    vector<int>dist(n+1); // dist from 1
    dfs(1,0,dist,adj);

    vector<int>dist2(n+1,1e18);
    queue<int>q;
    for(auto u : x){
        q.push(u);
        dist2[u] = 0;
    }
    vector<bool>visited(n+1);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        if(visited[u])continue;
        visited[u] = 1;
        for(int v : adj[u]){
            dist2[v] = min(dist2[v], dist2[u]+1);
            if(!visited[v])q.push(v);
        }
    }
    for(auto x: leaves){
        if(dist[x] < dist2[x]){
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
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