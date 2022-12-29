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


vector<vector<int>>adj,dp;
vector<int>in,par;
vector<int>visited;
int root;
void dfs(int u, int p){
    for(int v : adj[u]){
        if(v==p)continue;
        par[v] = u;
        dfs(v,u);
    }
}



void solve()
{
    int n;
    cin >> n;
    adj.resize(n+1);
    in.resize(n+1);
    par.resize(n+1);
    visited.resize(n+1);
    dp = vector<vector<int>>(n+1, vector<int>(2));

    for(int i = 1;i<n;++i){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
        in[u]++;
        in[v]++;
    }
    for(int i = 1;i<=n;++i){
        if(in[i]>1){
            root = i;
            break;
        }
    }
    dfs(root,-1);

    // to find min required, check if there are two leaf nodes with odd distance, if existant then you need atleast 3 else you can set everything to 1
    // to find max required set ans to n-1 then if a node u (non -leaf) has x leaf nodes adjacent to it then subtract x-1 from ans
    queue<int>q;
    for(int i = 1;i<=n;++i){
        if(in[i]==1)q.push(i);
    }
    vector<int>og = in;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        if(visited[u])continue;
        visited[u] = 1;
        for(int v : adj[u]){
            if(visited[v])continue;
            in[v]--;
            if(og[u]==1){
                dp[v][1]++;
            }else{
                dp[v][0]+=dp[u][1];
                dp[v][1]+=dp[u][0];
            }
            if(in[v]==1)q.push(v);
        }
    }
    int res1 = 1;
    for(int i = 1;i<=n;++i){
        if(dp[i][0] && dp[i][1])res1 = 3;
    }
    // now try to ans max query
    cout << res1 << ' ';
    int res = n-1;
    for(int i =1;i<=n;++i){
        int x = 0;
        for(int v : adj[i]){
            if(og[v]==1)x++;
        }
        if(x > 1)res-=(x-1);
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
    // cin >> T;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}