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
vector<int>in,out,flat;
int t = 1;
void dfs(int u, int p){
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

struct segtree{
    int sz = 1;
    vector<int>seg,lazy;
    void init(int n){
        while(sz < n)sz*=2;
        seg.resize(sz*2);
        lazy.resize(sz*2);
    }

    void rangeupdate(int x, int lx, int rx, int l, int r, int k){
        if(lazy[x]){
            seg[x] = lazy[x];
            if(rx-lx>1){
                lazy[2*x+1] = lazy[x];
                lazy[2*x+2] = lazy[x];
            }
            lazy[x] = 0;
        }
        if(lx >= l && rx <= r){
            seg[x] = k;
            if(rx-lx > 1){
                lazy[2*x+1] = k;
                lazy[2*x+2] = k;
            }
            return;
        }
        if(rx <= l || lx >= r)return;
        int m = (lx+rx)/2;
        rangeupdate(2*x+1,lx,m,l,r,k);
        rangeupdate(2*x+2, m, rx, l, r, k);
        seg[x]= (seg[2*x+1]|seg[2*x+2]);
    }

    void rangeupdate(int l, int r, int k){
        rangeupdate(0,0,sz,l,r,k);
    }

    int sol(int x, int lx, int rx, int l, int r){
        if(lazy[x]){
            seg[x] = lazy[x];
            if(rx-lx>1){
                lazy[2*x+1] = lazy[x];
                lazy[2*x+2] = lazy[x];
            }
            lazy[x] = 0;
        }
        if(lx >= l && rx <= r)return seg[x];
        if(rx <= l || lx >= r)return 0ll;
        int m = (lx+rx)/2;
        return sol(2*x+1,lx, m, l,r)|sol(2*x+2, m, rx, l,r );
    }

    int sol(int l, int r){
        return sol(0,0,sz,l,r);
    }
};

void solve()
{
    int n,q;
    cin >> n >> q;
    vector<int>a(n+1);
    adj.resize(n+1);
    in.resize(n+1);
    out.resize(n+1);
    flat.resize(2*n+1);

    for(int i = 1;i<=n;++i)cin >> a[i];
    for(int i = 1;i<n;++i){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1,-1);
    segtree st;
    st.init(2*n+3);
    for(int i = 1;i<2*n+1;++i)st.rangeupdate(i,i+1,(1ll<<a[flat[i]]));
    while(q--){
        int t;
        cin >> t;
        if(t==1){
            int u,k;
            cin >> u >> k;
            st.rangeupdate(in[u],out[u]+1,1ll<<k);
        }else{
            int u;
            cin >> u;
            int x = st.sol(in[u],out[u]+1);
            cout << __builtin_popcountll(x) << endl;
        }
    }
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