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

vector<set<int>>adj;
vector<int>subtree;
vector<int>par;
void dfs(int u, int p){
    subtree[u] = 1;
    for(int v : adj[u]){
        if(v==p)continue;
        dfs(v,u);
        subtree[u] += subtree[v];
    }
}
int centroid(int u, int p , int n){
    for(int v : adj[u]){
        if(v==p)continue;
        if(subtree[v] > (n/2))return centroid(v, u,n);
    }
    return u;
}
int root;
void decompose(int u,int p){
    dfs(u,p);
    int cent = centroid(u,p, subtree[u]);
    par[cent] = p;  
    for(int v : adj[cent]){
        adj[v].erase(cent);
        decompose(v, cent);
    }
}
vector<char>res;
void dfs2(int u, int p, char x){
    res[u] = x;
    for(int v : adj[u]){
        if(v==p)continue;
        dfs2(v,u,x+1);
    }
}

void solve()
{
    int n;
    cin >> n;
    adj.resize(n+1);
    for(int i = 1;i<n;++i){
        int u,v;
        cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    subtree.resize(n+1);
    par.resize(n+1);
    decompose(1, -1);
    res.resize(n+1); 
    for(int i = 1;i<=n;++i){
        if(par[i]==-1)root = i;
    }
    adj.clear();
    adj.resize(n+1);
    for(int i = 1;i<=n;++i){
        if(par[i]!=-1)adj[par[i]].insert(i);
    }
    dfs2(root, -1, 'A');
    for(int i = 1;i<=n;++i)cout << res[i] << ' ';
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