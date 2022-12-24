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

vector<vector<int>>adj;
vector<int>subtree,a,edges;
int mod = 1e9+7;
int n;
void dfs(int u, int p = -1){
    subtree[u] = 1;
    for(int v : adj[u]){
        if(v==p)continue;
        dfs(v,u);
        subtree[u]+=subtree[v];
        edges.pb(((n-subtree[v])*subtree[v])%mod);
    }
}

void dfs2(int u, int p=1){
    for(int v : adj[u]){
        if(v==p)continue;
        edges.pb(((n-subtree[v])*subtree[v])%mod);
        dfs2(v,u);
    }
}

void solve()
{
    cin >> n;
    adj = vector<vector<int>>(n+1);
    subtree= vector<int>(n+1);
    edges.clear();
    for(int i = 1;i<=n;++i)adj[i].clear();
    for(int i = 1;i<n;++i){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    int m;
    cin >> m;
    a = vector<int>(m);

    for(int i = 0;i<m;++i)cin >> a[i];
    
    sort(all(a));
    dfs(1);
    sort(all(edges));
    int res = 0;
    vector<int>b = a;
    while(b.size() > edges.size()){
        int x = b.back();
        b.pop_back();
        int y = b.back();
        b.pop_back();
        b.pb(((x%mod)*(y%mod))%mod);
    }

    for(int i = n - 2; i >= 0; --i){
		if (b.size() > 0){
            int val = ((b.back()%mod)*(edges[i]%mod))%mod;
			res = ((res%mod)+(val%mod))%mod;
			b.pop_back();
		}
		else{
			res += edges[i]%mod;
		}
	}
    cout << res%mod << endl;
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