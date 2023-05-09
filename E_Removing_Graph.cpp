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

vector<vector<int>>adj;
vector<int>visited;
void dfs(int u, int &c){
    c++;
    visited[u] = 1;
    for(int v : adj[u]){
        if(visited[v])continue;
        dfs(v,c);
    }
}
void solve()
{
    int n,l,r;
    cin >> n >> l >> r;
    adj.resize(n+1);
    visited.resize(n+1);
    for(int i = 1;i<=n;++i){
        int u,v;
        cin >>u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector<int>b = {0};
    for(int i =1 ;i<=n;++i){
        if(!visited[i]){
            int c = 0;
            dfs(i,c);
            b.pb(c);
        }
    }
    n = b.size()-1;
    int res = 0;
    for(int i = 1;i<=n;++i){
        b[i]%=(l+r);
        res^=(b[i]/l);      
    }
    if(res)cout << "Alice" << endl;
    else cout << "Bob" << endl;
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