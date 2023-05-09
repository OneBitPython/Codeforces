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

set<vector<int>>st;
vector<vector<int>>dp,dist,adj; // dp[i][j] stores the number of nodes with distance of j from i that are not taken yet
// dist[i][j] stores distance from i to j
vector<int>taken;
void dfs(int u, int p ,vector<int>&d){
    for(int v : adj[u]){
        if(v==p)continue;
        d[v] = d[u]+1;
        dfs(v,u,d);
    }
}

void solve()
{
    int n;
    cin >> n;
    dp = vector<vector<int>>(n+1,vector<int>(n+1));
    dist = vector<vector<int>>(n+1,vector<int>(n+1));
    adj = vector<vector<int>>(n+1);
    taken = vector<int>(n+1);
    for(int i = 1;i<n;++i){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    st.clear();
    for(int i = 1;i<=n;++i){
        vector<int>d(n+1);
        dfs(i,-1,d);
        dist[i] = d;
        for(int j = 1;j<=n;++j)dp[i][dist[i][j]]++;
        for(int j = 0;j<=n;++j)st.insert({-dp[i][j], i, j});
    }
    set<vector<int>>rem;
    set<pair<int,int>>res;
    for(int z = 1;z<=n;++z){
        int u = (*st.begin())[1], r = (*st.begin())[2];
        if((*st.begin())[0] == 0)break;
        rem.insert({(*st.begin())[0],u,r});
        st.erase(st.begin());
        
        res.insert({u, r});
        for(int i =1 ;i<=n;++i){
            if(taken[i] && dist[u][i]==r)taken[i]++;
            if(!taken[i] && dist[u][i]==r){
                taken[i]++;
                for(int j = 1;j<=n;++j){
                    int x = dist[j][i];
                    if(dp[j][x]!=0){
                        st.erase({-dp[j][x],j,x});
                        dp[j][x]--;
                        st.insert({-dp[j][x], j, x});
                    }
                }
            }   
        }
    }
    for(auto x : rem){
        int u = x[1], r = x[2];
        bool ok = 1;
        for(int i = 1;i<=n;++i){
            if(dist[u][i] == r && (taken[i]<=1))ok = 0;
        }
        if(ok){
            res.erase({u, r});
            for(int i = 1;i<=n;++i){
                if(dist[u][i] == r)taken[i]--;
            }
        }
    }
    cout << res.size() << endl;
    for(auto x : res)cout << x.first << ' ' << x.second << endl;
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