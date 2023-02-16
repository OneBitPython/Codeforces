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

// vector<vector<int>>adj;
// vector<vector<pair<int,int>>>back;
// vector<int>in,out;
// int t = 1;
// int n,m;
// void comp(int u, int p){
//     in[u] = t;
//     t++;
//     for(int v : adj[u]){
//         if(v==p)continue;
//         comp(v,u);
//     }
//     out[u] = t;
//     t++;
// }

// int sub(int u, int v){
//     // is v in u's subtree
//     return in[v] > in[u] && out[u]>out[v];
// }

// void dfs(int u, int p, int x, vector<int>&dp){
//     for(auto &[w, v] : back[u]){
//         if(w < x)continue;
//         if(!sub(u,v))dp[u]++;
//         else dp[u]--;
//     }
//     for(int v : adj[u]){
//         if(v==p)continue;
//         dfs(v,u,x,dp);
//         dp[u]+=dp[v];
//     }
// }

// bool pos(int x){
//     vector<int>dp(n+1);
//     dfs(1,-1,x,dp);
//     for(int i = 2;i<=n;++i){
//         if(dp[i]==0)return 0;
//     }
//     return 1;
// }

// void solve()
// {
//     cin >> n >> m;
//     in.resize(n+1);
//     out.resize(n+1);
//     adj.resize(n+1);
//     back.resize(n+1);
    
//     for(int i = 1;i<n;++i){
//         int u,v;
//         cin >> u >> v;
//         adj[u].pb(v);
//         adj[v].pb(u);
//     }
//     for(int i = 1;i<=(m-(n-1));++i){
//         int u,v,w;
//         cin >> u >> v >> w;
//         back[u].pb({w, v});
//         back[v].pb({w, u});
//     }
//     comp(1,-1);
//     int l = 0, r = 1e9;
//     int res= 1e18;
//     while(l <= r){
//         int m = (l+(r-l)/2);
//         if(pos(m))res = m, l = m+1;
//         else r = m-1;
//     }
//     cout << (res==1e18?-1:res) << endl;
// }   

// int32_t main()
// {

//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);

//     // #ifndef ONLINE_JUDGE
//     // freopen("input.txt", "r", stdin);
//     // freopen("output.txt", "w", stdout);
//     // freopen("error.txt", "w", stderr);
//     // #endif

//     int T=1;
//     // cin >> T;
//     for(int i = 1;i<=T;++i)
//     {
//         // cout << "Case #" << i << ": ";
//         solve();
//     }
// }


//onebit1024

// #include <bits/stdc++.h>
// using namespace std;

// #define int long long
// #define pb push_back
// #define all(v) v.begin(),v.end()
// #define endl "\n"

// void __print(int x){cerr << x;}
// void __print(long double x){cerr << x;}
// void __print(double x){cerr << x;}
// void __print(const string &x){cerr << x;}
// void __print(char x){cerr << x;}
// void __print(bool x){cerr << x;}


// template<typename T, typename V>
// void __print(const pair<T,V>&x){cerr << "{";__print(x.first);cerr<<",";__print(x.second);cerr<<"}";}
// template<typename T>
// void __print(const T &x){int f = 0;cerr<<"{";for(auto &i : x)cerr<<(f++?",":""),__print(i);cerr<<"}";}

// void _print(){cerr << "]\n";}
// template<typename T, typename...V>
// void _print(T t, V...v){__print(t);if(sizeof...(v))cerr<<",";_print(v...);}

// #ifndef ONLINE_JUDGE
// #define dbg(x...)cerr << "LINE(" << __LINE__ << ") -> [" << #x << "] = [";_print(x)
// #else
// #define dbg(x...)
// #endif

vector<vector<int>>adj,up;
vector<vector<pair<int,int>>>extra;
vector<int>in,out,flat,dist,par;
int t = 1;
void compute(int u, int p){
	in[u] = t;
	flat[t] = u;
	t++;
	for(int v : adj[u]){
		if(v==p)continue;
		up[v][0] = u;
		dist[v] = dist[u]+1;
		par[v] = u;
		for(int j = 1;j<=20;++j)up[v][j] = up[up[v][j-1]][j-1];
		compute(v,u);
	}
	out[u] = t;
	flat[t] = u;
	t++;
}
int lca(int u, int v){
	if(dist[v] > dist[u])swap(u,v);
	int k = dist[u] - dist[v];
	for(int j = 0;j<=20;++j){
		if(k&(1ll<<j))u = up[u][j];
	}
	if(u==v)return u;
	for(int j = 20;j>=0;--j){
		if(up[u][j] != up[v][j])u = up[u][j], v= up[v][j];
	}
	return up[v][0];
}
int sub(int v, int u){
	// check if v is in us subtree
	return (in[u]<=in[v] && out[u]>=out[v]);
}
int n,m;
void upd(int v, int u, vector<int>&dp){
	while(u!=v){
		dp[u]++;
		u = par[u];
	}
}
bool pos(int x){
	// check if it's possible with water level x
	vector<int>dp(n+1);
	for(int i = 1;i<=n;++i){
		int kc = extra[i].size();
		for(int w = 0;w<kc;++w){
			int v = extra[i][w].first, c = extra[i][w].second;
			int u = i;
			if(c<x)continue;
			if(in[u]<in[v])swap(u,v);
			// in[u] > in[v]
			if(lca(u,v)==v)upd(v,u,dp);
			else upd(lca(u,v),u,dp),upd(lca(u,v),v,dp);
		}
	}
	for(int i = 2;i<=n;++i){
		if(dp[i]==0)return 0;
	}
	return 1;
}

void solve(){
	cin>> n >> m;
	adj.resize(n+1);
	extra.resize(n+1);
	in.resize(n+1);
	out.resize(n+1);
	dist.resize(n+1);
	flat.resize(2*n+1);
	par.resize(n+1);
	up = vector<vector<int>>(n+1, vector<int>(21));
	for(int i = 1;i<n;++i){
		int u,v;
		cin>> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	int rem = m-(n-1);
	for(int i = 1;i<=rem;++i){
		int u,v,w;
		cin >> u >> v >> w;
		extra[u].pb({v, w});
		extra[v].pb({u, w});
	}
	compute(1,-1);
	int l = 0, r = 1e9;
    int res = 1e18;
	while(l <= r){
		int m = (l+r)/2;
		if(pos(m))res = m, l = m+1;
		else r = m-1;
	}
	cout << (res==1e18?-1:res) << endl;
}

int32_t main(){
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
	while(T--){
		solve();
	}
}