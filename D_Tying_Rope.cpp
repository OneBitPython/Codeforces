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
vector<int>visited;
vector<int>path;
void dfs(int u){
    visited[u] = 1;
    path.pb(u);
    for(int v : adj[u]){
        if(visited[v])continue;
        dfs(v);
    }
}
void solve()
{
    int n,k;
    cin >> n >> k;
    adj.resize(2*n+1);
    visited.resize(2*n+1);
    for(int i = 1;i<=k;++i){
        int a,b;
        char x,y;
        cin >> a >>  x >> b >> y;
        if(x=='B')a+=n;
        if(y=='B')b+=n;
        adj[a].insert(b);
        adj[b].insert(a);
    }
    for(int i = 1;i<=n;++i)adj[i].insert(i+n),adj[i+n].insert(i);
    int c = 0, d = 0;
    for(int i = 1;i<=2*n;++i){
        if(visited[i])continue;
        dfs(i);
        int cnt = 0;
        for(auto x : path){
            if(x <= n)cnt++;
        }
        if(adj[path.back()].count(path.front()) && cnt > 1)d++;
        else c++;
        path.clear();
    }
    cout << d << ' ' << c << endl;
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