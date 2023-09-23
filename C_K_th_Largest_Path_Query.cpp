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

int sz,g,n;
vector<vector<int>>adj,up;
vector<int>in,out,flat,depth,cnt,dp,a,sqr;
int t = 1;
void dfs(int u, int p){
    in[u] = t;
    flat[t] = u;
    t++;
    for(int v : adj[u]){
        if(v==p)continue;
        up[v][0] = u;
        depth[v] = depth[u]+1;
        for(int j = 1;j<=20;++j)up[v][j] = up[up[v][j-1]][j-1];
        dfs(v,u);
    }
    out[u] = t;
    flat[t] = u;
    t++;
}

int lca(int u, int v){
    if(depth[v] > depth[u])swap(v,u);
    int k = depth[u]-depth[v];
    for(int j = 0;j<=20;++j){
        if(k&(1ll<<j))u = up[u][j];
    }
    if(v==u)return u;
    for(int j = 20;j>=0;--j){
        if(up[u][j] != up[v][j])u = up[u][j], v = up[v][j];
    }
    return up[v][0];
}

void add(int u){
    cnt[flat[u]]++;
    if(cnt[flat[u]]==1){
        dp[a[flat[u]]]++;
        sqr[a[flat[u]]/sz]++;
    }else if(cnt[flat[u]]==2){
        dp[a[flat[u]]]--;
        sqr[a[flat[u]]/sz]--;
    }
}
void remove(int u){
    cnt[flat[u]]--;
    if(cnt[flat[u]]==1){
        dp[a[flat[u]]]++;
        sqr[a[flat[u]]/sz]++;
    }else if(cnt[flat[u]]==0){
        dp[a[flat[u]]]--;
        sqr[a[flat[u]]/sz]--;
    }
}

int f(int x){
    // xth largest value
    int curr = 0;
    for(int i = g;i>=0;--i){
        if((curr+sqr[i]) < x)curr+=sqr[i];
        else{
            for(int j = min(n,(sz*(i+1))-1);j>=(sz*i);--j){
                curr+=dp[j];
                if(curr>=x)return j;
            }
        }
    }
    return n;
}

void solve()
{
    cin >> n;
    sz = sqrtl(n);
    g = n/sz + 2;
    adj = vector<vector<int>>(n+1);
    out.resize(n+1);
    a.resize(n+1);
    sqr.resize(g+1);
    dp.resize(n+1);
    in.resize(n+1);
    cnt.resize(n+1);
    flat.resize(2*n+1);
    up = vector<vector<int>>(n+1, vector<int>(21));
    depth.resize(n+1);

    for(int i = 1;i<=n;++i)cin >> a[i];
    for(int i =2 ;i<=n;++i){
        int v;cin >> v;
        adj[i].pb(v);
        adj[v].pb(i);
    }
    dfs(1,-1);
    vector<vector<int>>queries;int q;
    cin >> q;

    for(int i = 1;i<=q;++i){
        int u,v,k;cin >> u >> v >> k;
        if(in[v] < in[u])swap(v,u);
        if(lca(u,v)==u)queries.pb({in[u],in[v],0,k,i});
        else queries.pb({out[u],in[v],in[lca(u,v)],k,i});
    }


    sort(all(queries), [&](auto one, auto two){
        if(one==two)return false;
        int g1 = one[0]/sz, g2 = two[0]/sz;
        if(g1==g2)return one[1] < two[1];
        return g1 < g2;
    });
    int l = 1, r = 0;
    vector<int>res(q+1);

    for(auto x : queries){
        while(r < x[1]){
            r++;
            add(r);
        }
        while(r > x[1]){
            remove(r);
            r--;
        }
        while(l < x[0]){
            remove(l);
            l++;
        }
        while(l > x[0]){
            l--;
            add(l);
        }
        if(x[2]!=0){
            int u =x[2];
            dp[a[flat[u]]]++;
            sqr[a[flat[u]]/sz]++;
        }
        res[x.back()] = f(x[3]);

        if(x[2]!=0){
            int u =x[2];
            dp[a[flat[u]]]--;
            sqr[a[flat[u]]/sz]--;
        }
    }
    for(int i = 1;i<=q;++i)cout << res[i] << endl;
    
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