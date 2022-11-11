#include <bits/stdc++.h>
using namespace std;

#define int unsigned int
#define pb push_back
#define all(c) c.begin(), c.end()
#define endl "\n"

const double PI=3.141592653589;





bool visited[5005];
pair<int,int> dp[5005][5005];
vector<pair<int,int>> adj[5005];
int n,m,t;
void dfs(int u){
    visited[u] = 1;
    for(auto [v,c] : adj[u]){
        if(!visited[v])dfs(v);
        for(int j = 2;j<=n;++j){
            if(dp[v][j-1].first+c < dp[u][j].first){
                dp[u][j].first = dp[v][j-1].first+c;
                dp[u][j].second = v;
            }
        }
    }
}
void solve()
{
    cin >> n >> m >> t;
    for(int i = 0;i<m;++i){
        int u,v,c;
        cin >> u >> v >> c;
        adj[u].pb({v,c});
    }
    //dp[i][j][0] min cost of path of length j ending at node i
    // dp[i][j][1] par of node i in the min cost path of length j
    for(int i = 1;i<=n;++i){
        for(int j = 1;j<=n;++j)dp[i][j].first = 2e9;
    }
    dp[n][1].first = 0;

    dfs(1);

    int k = 1;
    for(int j = 2;j<=n;++j){
        if(dp[1][j].first <= t)k = j;
    }
    cout << k << endl;
    vector<int>res;
    int start = 1;
    
    while(k){
        cout << start << ' ';
        start = dp[start][k].second;
        k--;
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