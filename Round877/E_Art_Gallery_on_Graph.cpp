#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(v) v.begin(), v.end()
#define endl "\n"

void solve(){
    int n,m,k;
    cin >> n >> m >> k;
    vector<vector<int>>adj(n+1);
    vector<pair<int,int>>a(k+1);
    vector<int>dp(n+1);
    for(int i = 1;i<=m;++i){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for(int i = 1;i<=k;++i)cin >> a[i].first >> a[i].second;
    for(int i = 1;i<=k;++i)dp[a[i].first] = max(dp[a[i].first], a[i].second);
    
    
    priority_queue<pair<int,int>>pq;
    vector<int>vis(n+1);
    for(int i = 1;i<=n;++i){
        if(dp[i] > 0)pq.push({dp[i],i});
    }
    while(!pq.empty()){
        int u = pq.top().second, d = pq.top().first;
        pq.pop();
        if(vis[u])continue;
        vis[u] = 1;
        d--;
        for(int v : adj[u]){
            if(!vis[v] && d>=0){
                pq.push({d,v});
            }
        }
    }
    vector<int>res;
    for(int i = 1;i<=n;++i){
        if(vis[i])res.pb(i);
    }
    sort(all(res));
    cout << res.size() << endl;
    for(auto x : res)cout << x << ' ';
    cout << endl;
}

int32_t main(){
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}