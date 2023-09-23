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


vector<int>visited;
void dfs(int u, vector<vector<int>>&adj, int &sz){
    sz++;
    visited[u] = 1;
    for(int v : adj[u]){
        if(visited[v])continue;
        dfs(v,adj,sz);
    }
}

void solve()
{
    int n,k;
    cin >> n >> k;
    visited = vector<int>(n+1);
    vector<int>a(n+1);
    for(int i = 1;i<=n;++i)cin >> a[i];
    if(k==1){
        for(int i = 1;i<=n;++i){
            if(a[i] != i){
                cout << "NO" << endl;return;
            }
        }
        cout << "YES" << endl;
        return;
    }
    for(int i =1 ;i<=n;++i){
        if(a[i]==i){
            cout << "NO" << endl;
            return;
        }
    }
    // all cycles must be of size exactly k
    vector<vector<int>>adj(n+1);
    vector<int>deg(n+1);

    for(int i = 1;i<=n;++i)adj[i].pb(a[i]),deg[a[i]]++;
    vector<int>cycle(n+1,1);
    queue<int>q;
    for(int i =1;i<=n;++i){
        if(deg[i]==0)q.push(i);
    }
    while(!q.empty()){
        int u = q.front();
        q.pop();
        cycle[u] = 0;
        if(deg[u]<0)continue;
        for(int v : adj[u]){ 
            deg[v]--;
            if(deg[v]==0)q.push(v);
        }
    }
    dbg(cycle);
    set<int>st;
    for(int i = 1;i<=n;++i){
        if(cycle[i] && !visited[i]){
            int sz = 0;
            dfs(i,adj,sz);
            st.insert(sz);
        }
    }

    cout << ((st.size()==1 && (*st.begin())==k)?"YES":"NO") << endl;
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