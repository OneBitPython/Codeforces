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
    int n,m,p;
    cin >> n >> m >> p;
    vector<int>a(n+1);
    for(int i = 1;i<=n;++i)cin >> a[i];
    vector<vector<pair<int,int>>>adj(n+1),trans(n+1);
    for(int i = 1;i<=m;++i){
        int u,v,c;
        cin >> u >> v >> c;
        adj[u].pb({v,c});
        trans[v].pb({u,c});

    }
    vector<int>distn(n+1,1e18),visited(n+1); // distn stores distance from n for each node
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,n});
    distn[n] = 0;
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        if(visited[u])continue;
        visited[u] = 1;
        for(auto &[v,c] : trans[u]){
            int curr_dist = distn[v], new_dist = distn[u]+c;
            if(new_dist < curr_dist){
                pq.push({new_dist,v});
                distn[v] = new_dist;
            }
        }
    }
    if(distn[1]==1e18){
        cout << -1 << endl;
        return;
    }
    vector<vector<pair<int,int>>>dp(n+1,vector<pair<int,int>>(n+1,{1e18,0})); // dp[i][j] stores{number of opertions to reach i from 1, coins left} if a[j] has max value in the path
    {
    
    int res = 1e18;
    vector<int>visited(n+1);
    priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq; // stores {number of operations to reach i, -coins left, node, nod withmax value of a[i]}
    pq.push({0,-p,1,1});
    dp[1][1] = {0,p};
    while(!pq.empty()){
        int ops = pq.top()[0], left = abs(pq.top()[1]);
        int mx = pq.top()[3];
        int u = pq.top()[2];
        pq.pop();
        if(visited[u])continue;
        visited[u] = 1;
        
        for(auto &[v,c] : adj[u]){
            
            pair<int,int>curr = dp[v][mx];
            int need = max(0ll,c-left);
            int extra = (need+a[mx]-1)/a[mx];
            int have = (extra*a[mx]+left)-c;
            pair<int,int>get = {extra+ops,have};
            if(get.first < curr.first || (get.first==curr.first && get.second > curr.second)){
                dp[v][mx] = get;
                int val = mx;
                if(a[v] > a[mx])val = v;
                pq.push({get.first,-get.second,v,val});
            }
        }
    }
    }
    int res = 1e18;
    for(auto x : dp[n])res = min(res,x.first);
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
    cin >> T;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}