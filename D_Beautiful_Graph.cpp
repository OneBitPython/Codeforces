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

int mod = 998244353;
bool dfs(int u, vector<int>&color, int c, vector<vector<int>>&adj, int &c1, int &c2){
    color[u] = c;
    if(c==0)c1*=2,c1%=mod;
    else c2*=2,c2%=mod;
    for(int v : adj[u]){

        if(color[v]==-1){
            if(!dfs(v,color,1-c,adj,c1,c2))return 0;
        }else{
            if(color[u] == color[v])return 0;
        }
    }
    return 1;
}
void solve()
{
    int n,m;
    cin >> n >> m;
    vector<vector<int>>adj(n+1);
    for(int i =1;i<=m;++i){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector<int>color(n+1,-1);
    int res = 1;
    for(int i = 1;i<=n;++i){
        if(color[i] == -1){
            int c1 = 1, c2 = 1;
            if(!dfs(i,color,0,adj, c1, c2)){
                cout << 0 << endl;
                return;
            }
            res *= (c1+c2);
            res%=mod;
        }
    }
    cout << res << endl;
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