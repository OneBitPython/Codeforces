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



void solve()
{
    int n;
    cin >> n;
    vector<vector<int>>adj(n+1);
    queue<int>q;
    vector<int>in(n+1), dp(n+1);
    for(int i = 1;i<=n;++i){
        int k;
        cin >> k;
        for(int j = 1;j<=k;++j){
            int v;
            cin >> v;
            adj[v].pb(i);
            in[i]++;
        }
    }
    vector<int>visited(n+1);
    for(int i = 1;i<=n;++i){
        if(in[i]==0){
            q.push(i);
            dp[i] = 1;
        }
    }
    vector<int>topo;
    while(!q.empty()){
        int u =q.front();
        q.pop();
        if(visited[u])continue;
        visited[u] = 1;
        topo.pb(u);
        for(int v : adj[u]){
            in[v]--;
            int res = dp[u];
            if(u > v)res++;
            dp[v] = max(dp[v],res);
            if(in[v]==0)q.push(v);
        }
    }
    if(topo.size()!=n){
        cout << -1 << endl;
        return;
    }
    cout << *max_element(all(dp)) << endl;
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