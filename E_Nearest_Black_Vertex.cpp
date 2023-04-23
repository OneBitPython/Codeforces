#include <bits/stdc++.h>
using namespace std;

// #define int long long
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

const int N = 2001;
int dist[N+1],visited[N+1];
void solve()
{
    int n,m;
    cin >> n >> m;
    vector<vector<int>>adj(n+1);
    for(int i = 1;i<=m;++i){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector<int>color(n+1,1);
    int k;
    cin >> k;
    vector<pair<int,int>>queries;
    for(int i = 1;i<=n;++i)dist[i] = 1e9, visited[i] = 0;
    for(int i = 1;i<=k;++i){
        int p,d;
        cin >> p >> d;
        queries.pb({p, d});
        queue<int>q;
        q.push(p);
        dist[p] = 0;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            if(visited[u])continue;
            visited[u] = 1;
            for(int v : adj[u]){
                dist[v] = min(dist[v], dist[u]+1);
                q.push(v);
            }
        }
        for(int j = 1;j<=n;++j){
            if(color[j] && dist[j]<d){  
                color[j] = 0;
            }
            dist[j] = 1e9;
            visited[j] = 0;
        }

    }
    for(auto x : queries){
        int p = x.first, d = x.second;
        queue<int>q;
        q.push(p);
        dist[p] = 0;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            if(visited[u])continue;
            visited[u] = 1;
            for(int v : adj[u]){
                dist[v] = min(dist[v], dist[u]+1);
                q.push(v);
            }
        }
        bool got = 0;
        for(int j = 1;j<=n;++j){
            if(color[j] && dist[j]==d)got = 1;
            if(color[j] && dist[j] < d){
                cout << "No" << endl;
                return;
            }
            dist[j] = 1e9;
            visited[j] = 0;
        }   
        if(!got){
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
    for(int i= 1;i<=n;++i)cout << color[i];
    cout << endl;
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