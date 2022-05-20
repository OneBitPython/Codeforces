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

void print(){cerr << endl;};
template <typename T, typename... Args>
void print(T one, Args... rest){
    cerr << one << " ";
    print(rest...);
}


int sum() { return 0; }
template<typename... Args>
int sum(int a, Args... args) { return a + sum(args...); }

string bin(long n){
    long i;
    string val = "0";
    for (i = 1 << 30; i > 0; i = i / 2)
    {
      if((n & i) != 0)
      {
        val+="1";
      }
      else
      {
        val+="0";
      }
    }
    while(val.front()=='0'){
        val.erase(0,1);
    }
    return val;
}


void dfs(int u, vector<int>&depth, vector<vector<int>>&up, vector<int>&parent, vector<vector<int>>&adj, int p){
    for(int v : adj[u]){
        if(v==p)continue;
        parent[v] = u;
        up[v][0] = parent[v];
        depth[v] = depth[u]+1;
        for(int j = 1;j<31;++j){
            up[v][j] = up[up[v][j-1]][j-1];
        }
        dfs(v, depth, up, parent, adj, u);
    }
}

void solve()
{
    int n;
    cin >> n;
    vector<int>parent(n);
    vector<vector<int>>adj(n);
    parent[0] = 0;
    for(int i = 0;i<n;++i){
        int m;
        cin >> m;
        for(int j = 0;j<m;++j){
            int v;
            cin >> v;
            adj[i].pb(v);
            adj[v].pb(i);
        }
    }
    vector<vector<int>>up(n,vector<int>(31));
    vector<int>depth(n);
    dfs(0ll, depth, up, parent, adj,-1);
    int t;
    cin >> t;
    while(t--){
        int u,v;
        cin >> u >> v;
        if(depth[v] > depth[u])swap(u,v);
        // depth[u] > depth[v]
        int k = depth[u] - depth[v];
        for(int i = 0;i<31;++i){
            if(k&(1ll<<i)){
                u = up[u][i];
            }
        }
        // u and v are at the samelevel
        if(u == v){
            cout << u << endl;
            continue;
        }
        // try bringing them as close to the LCA as possible
        for(int i = 30;i>=0;--i){
            if(up[u][i]!=up[v][i]){
                u = up[u][i];
                v = up[v][i];
            }
        }
        cout << up[u][0] << endl;
    }
}   

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    

    int T=1;
    // cin >> T;
    for(int i = 1;i<=T;++i)
    {
        solve();
    }
}