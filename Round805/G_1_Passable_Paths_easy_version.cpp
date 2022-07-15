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

vector<int>dist;
vector<vector<int>>adj;

void dfs(int u, int p){
    for(int v : adj[u]){
        if(v == p)continue;
        dist[v] = dist[u]+1;
        dfs(v, u);
    }
}

void dfs2(int u, set<int>&r, int &got, vector<bool>&visited, bool &ok){
    visited[u] = 1;
    int y = got;
    if(r.count(u))y++;
    if(y==r.size()){
        ok = 1;
        return;
    }
    for(int v : adj[u]){
        if(visited[v])continue;
        dfs2(v, r, y, visited, ok);
    }
}

void solve()
{
    int n;
    cin >> n;
    adj = vector<vector<int>>(n+1);
    dist.resize(n+1);
    for(int i = 0;i<n-1;++i){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1, -1);
    int q;
    cin >> q;
    while(q--){
        int k;
        cin >> k;
        set<int>st;
        int max_depth = -1;
        int node = 1;
        for(int i = 0;i<k;++i){
            int v;
            cin >> v;
            st.insert(v);
            if(dist[v] >= max_depth){
                max_depth = dist[v];
                node = v;
            }
        }
        vector<bool>visited(n+1);
        int got = 0;
        bool ok = 0;
        dfs2(node, st, got, visited, ok);
        if(ok){
            cout << "YES" << endl;
        }else cout << "NO" << endl;
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
        // cout << "Case #" << i << ": ";
        solve();
    }
}