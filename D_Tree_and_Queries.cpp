#include <bits/stdc++.h>
using namespace std;

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
const int MXN = 1e5+1;
const int sz = 600;
int n;
int in[MXN],out[MXN], flat[2*MXN+1], c[MXN], f[MXN], times[MXN], cnt[MXN], ff[sz+1],fff[MXN];
int t = 1;
void dfs(int u, int p = -1){
    in[u] = t;
    flat[t] = u;
    t++;
    for(int v : adj[u]){
        if(v==p)continue;
        dfs(v,u);
    }
    out[u] = t;
    flat[t] = u;
    t++;
}
int group(int x){
    return x/sz;
}
void add(int x){

    times[x]++;     
    if(times[x] == 2){
        x = c[x];
        ff[group(f[x])]--;
        fff[f[x]]--;
        f[x]++;
        fff[f[x]]++;
        ff[group(f[x])]++;
    }
}
void remove(int x){
    times[x]--;
    if(times[x]==1){
        x = c[x];
        ff[group(f[x])]--;
        fff[f[x]]--;
        f[x]--;
        fff[f[x]]++;
        ff[group(f[x])]++;
    }
}
int ans(int k){
    int g1 = group(k), g2 = group(n);
    int res = 0;
    if(g1==g2){
        for(int i = k;i<=n;++i)res+=fff[i];
    }else{
        for(int i = g1+1;i<g2;++i)res+=ff[i];
        for(int i = k;i<((g1+1)*sz);++i)res+=fff[i];
        for(int i = g2*sz;i<=n;++i)res+=fff[i];
    }
    return res;
}
void solve()
{
    int q;
    cin >> n >> q;
    adj.resize(n+1);
    for(int i = 1;i<=n;++i)cin >> c[i];
    for(int i = 1;i<n;++i){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector<vector<int>>queries;
    vector<int>res(q);
    dfs(1,-1);
    for(int i = 0;i<q;++i){
        int u,k;
        cin >> u >> k;
        queries.pb({in[u], out[u], k, i});
    }
    sort(all(queries), [&](auto one, auto two){
        int g1 = one[0]/sz, g2 = two[0]/sz;
        if(g1 == g2)return one[1] < two[1];
        return g1 < g2;
    });
    int l = 0, r = -1;
    for(auto x : queries){
        while(l > x[0]){
            l--;
            add(flat[l]);
        }
        while(r < x[1]){
            r++;
            add(flat[r]);
        }
        while(r > x[1]){
            remove(flat[r]);
            r--;
        }
        while(l < x[0]){
            remove(flat[l]);
            l++;
        }
        res[x[3]] = ans(x[2]);
    }
    for(auto x : res)cout << x << endl;
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