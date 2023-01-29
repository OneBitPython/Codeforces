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


void dfs(int u, vector<vector<int>>&adj, vector<int>&visited, set<int>&p){
    p.insert(u);
    visited[u] = 1;
    for(int v : adj[u]){
        if(visited[v])continue;
        dfs(v,adj,visited,p);
    }
}
void solve()
{
    int n;
    cin >> n;
    vector<int>a(n+1);
    for(int i =1 ;i<=n;++i)cin >> a[i];
    vector<vector<int>>adj(n+2), trans(n+2);
    vector<int>deg(n+2);
    for(int i =1 ;i<=n;++i){
        int v = i+a[i];
        if(v < 0)v = 0;
        if(v > n+1)v = n+1;
        adj[i].pb(v);
        trans[v].pb(i);
        deg[v]++;
    }
    // figure out all the nodes in the cc of node 1
    // consider cases for whether 1 is in the same cc as n+1 or 0
    // if it's not then node 1 has to beconnected to that cc
    // first calculate all nodes in the same cc as node n and 0
    set<int>ncc, zerocc;
    vector<int>visited(n+2);
    dfs(0,trans,visited,zerocc);
    visited = vector<int>(n+2);
    dfs(n+1,trans,visited,ncc);
    queue<int>q;
    visited = vector<int>(n+2);
    vector<int>in(n+2);
    for(int i = 1;i<=n;++i){
        if(deg[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int u = q.front();
        q.pop();
        if(visited[u])continue;
        visited[u] = 1;
        for(int v : adj[u]){
            in[v]+=in[u]+1;
            deg[v]--;
            if(deg[v]==0)q.push(v);
        }
    }
    set<int>main_path;
    q.push(1);
    visited = vector<int>(n+2);
    while(!q.empty()){
        int u = q.front();
        main_path.insert(u);
        q.pop();
        if(visited[u])continue;
        visited[u] = 1;
        for(int v : adj[u]){
            q.push(v);
        }
    }
    int res = 0;
    if(ncc.count(1)){
        // now one only needs to be connected to nodes in it's own cc all others are useless
        vector<int>useful(n+2);
        for(auto x : main_path)useful[x] = 1;
        for(int i =1;i<=n;++i){
            if(useful[i]){
                res+=(int)(ncc.size())-in[i]-1;
                int mn = n+2, mx = i+n;
                res+=(mx-mn+1);
                mx = -1;
                mn = i-n;
                res+=(mx-mn+1);

            }else{
                // can assume any value
                res+=(2*n+1);
            }
        }
        // one can also connect to all nodes in the cc of zero
        res+=(int)(main_path.size()-1)*(int)(zerocc.size());
    }else if(zerocc.count(1)){
        vector<int>useful(n+2);
        for(auto x : main_path)useful[x] = 1;
        for(int i =1;i<=n;++i){
            if(useful[i]){
                res+=(int)(zerocc.size())-in[i]-1;
                int mn = n+2, mx = i+n;
                res+=(mx-mn+1);
                mx = -1;
                mn = i-n;
                res+=(mx-mn+1);

            }else{
                // can assume any value
                res+=(2*n+1);
            }
        }
        res+=(int)(main_path.size()-1)*(int)(ncc.size());
    }else{
        vector<int>useful(n+2);
        for(auto x : main_path)useful[x] = 1;
        for(int i =1;i<=n;++i){
            if(useful[i]){
                int mn = n+2, mx = i+n;
                res+=(mx-mn+1);
                mx = -1;
                mn = i-n;
                res+=(mx-mn+1);
                dbg(res);
            }else{
                // can assume any value

            }
        }
        res+=(int)(main_path.size())*(zerocc.size());
        res+=(int)(main_path.size())*(ncc.size());
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