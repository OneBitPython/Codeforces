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


vector<vector<int>>adj,up;
vector<int>dist,res;
void dfs(int u, int p){
    for(int v : adj[u]){
        if(v==p)continue;
        up[v][0] = u;
        for(int j = 1;j<=20;++j)up[v][j] = up[up[v][j-1]][j-1];
        dist[v] = dist[u]+1;
        dfs(v,u);
    }
}
int lca(int u, int v){
    if(dist[v] > dist[u])swap(u,v);
    int k = dist[u]-dist[v];
    for(int i = 0;i<=20;++i){
        if(k&(1ll<<i))u = up[u][i];
    }
    if(u==v)return u;
    for(int i = 20;i>=0;--i){
        if(up[v][i] != up[u][i])u = up[u][i], v = up[v][i];
    }
    return up[v][0];
}
int d(int u,int v){
    return dist[u]+dist[v]-(2*dist[lca(u,v)]);
}

vector<int>pending,color;
int q2(int u){
    int ans = res[u];
    for(auto x : pending){
        ans = min(ans, d(u,x));
    }
    res[u] = ans;
    return res[u];
}
int n,q;
void done(){
    queue<int>q;
    vector<int>visited(n+1);
    for(int i = 1;i<=n;++i){
        if(color[i])q.push(i),res[i]=0;
    }
    while(!q.empty()){
        int u = q.front();
        q.pop();
        if(visited[u])continue;
        visited[u] = 1;
        for(int v : adj[u]){
            res[v] = min(res[v], res[u]+1);
            q.push(v);
        }
    }
}
void solve()
{
    cin >> n >> q;
    adj.resize(n+1);
    up = vector<vector<int>>(n+1, vector<int>(21));
    dist.resize(n+1);
    res.resize(n+1, 1e18);
    color.resize(n+1);
    for(int i = 1;i<n;++i){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1,-1);
    int sz = 500;
    int cnt = 0;
    color[1] = 1;
    pending.pb(1);
    for(int i = 0;i<q;++i){
        int t;
        cin >> t;
        if(cnt==sz){    
            done();
            pending.clear();
            cnt = 0;
        }
        int u;
        cin >> u;
        if(t==1){
            
            color[u] = 1;
            pending.pb(u);
        }else{
            cout << q2(u) << endl;
        }
        cnt++;
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