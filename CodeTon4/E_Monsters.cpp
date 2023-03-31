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


void dfs(int u, vector<vector<int>>&adj, vector<int>&visited){
    visited[u] = 1;
    for(int v : adj[u]){
        if(visited[v])continue;
        dfs(v,adj,visited);
    }
}
void solve()
{
    int n,m;
    cin >> n >> m;
    vector<int>a(n+1);
    for(int i = 1;i<=n;++i)cin >> a[i];
    vector<vector<int>>adj(n+1);
    for(int i=1 ;i<=m;++i){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    int conn = 0;
    vector<int>visited(n+1);
    for(int i= 1;i<=n;++i){
        if(!visited[i]){
            dfs(i,adj,visited);
            conn++;
        }
    }
    if(conn>1 || *min_element(all(a))!=0){
        cout << "NO" << endl;
        return;
    }
    vector<int>useless(n+1);
    visited = vector<int>(n+1);
    queue<int>q;
    for(int i = 1;i<=n;++i){
        if(useless[i])continue;
        if(a[i]>0)continue;
        int taken = 0;
        q.push(i);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>st;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            if(visited[u])continue;
            st.pb(u);
            visited[u] = 1;
            taken++;
            useless[u] = 1;
            for(int v : adj[u]){
                if(visited[v])continue;
                pq.push({a[v],v});
            }
            while(!pq.empty()){
                int i = pq.top().second;
                if(taken>=a[i]){
                    pq.pop();
                    q.push(i);
                }else{
                    break;
                }
                
            }
            
        }
        for(auto x : st)visited[x] = 0;
        if(taken==n){
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
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