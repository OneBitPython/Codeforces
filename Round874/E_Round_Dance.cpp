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

void dfs(int u, vector<int>&c){
    c.pb(u);
    visited[u] = 1;
    for(int v : adj[u]){
        if(visited[v])continue;
        dfs(v,c);
    }
}
void solve()
{
    int n;
    cin >> n;
    adj = vector<vector<int>>(n+1);
    vector<int>a(n+1),deg(n+1);
    visited = vector<int>(n+1);
    for(int i = 1;i<=n;++i){
        int v;
        cin >> v;
        adj[i].pb(v);
        adj[v].pb(i);
        deg[i]++;
        deg[v]++;
    }

    int conn = 0,full = 0;
    for(int i = 1;i<=n;++i){
        if(!visited[i]){
            conn++;
            vector<int>p;
            dfs(i,p);
            bool ok = 1;
            for(auto x : p){
                if(deg[x]!=2)ok = 0;
            }
            if(ok && p.size()>2)full++;
        }
    }
    cout << full+(full<conn) << ' ' << conn << endl;
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