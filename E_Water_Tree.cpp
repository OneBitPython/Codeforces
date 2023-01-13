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

struct segtree{
    int sz = 1;
    vector<int>seg,lazy;
    void init(int n){
        while(sz < n)sz*=2;
        seg.resize(sz*2);
        lazy.resize(sz*2);
    }

    void rangeupdate(int x, int lx, int rx, int l, int r, int y){
        if(lazy[x]){
            seg[x] = lazy[x];
            if(rx-lx > 1){
                lazy[2*x+1] = lazy[x];
                lazy[2*x+2] = lazy[x];
            }
            lazy[x] = 0;
        }
        if(lx >= l && rx <= r){
            seg[x] = y;
            if(rx-lx > 1){
                lazy[2*x+1] = y;
                lazy[2*x+2] = y;
            }
            return;
        }
        if(rx <= l || lx >= r)return;
        int m = (lx+rx)/2;
        rangeupdate(2*x+1, lx, m, l, r,y);
        rangeupdate(2*x+2, m, rx, l, r, y);
        seg[x] = min(seg[2*x+1], seg[2*x+2]);
    }

    void rangeupdate(int l, int r, int y){
        rangeupdate(0,0,sz,l,r,y);
    }

    int sol(int x, int lx, int rx, int l, int r){
        if(lazy[x]){
            seg[x] = lazy[x];
            if(rx-lx > 1){
                lazy[2*x+1] = lazy[x];
                lazy[2*x+2] = lazy[x];
            }
            lazy[x] = 0;
        }
        if(rx <= l || lx >= r)return 2;
        if(rx <= r && lx >= l)return seg[x];
        int m = (lx+rx)/2;
        return min(sol(2*x+1, lx, m, l, r), sol(2*x+2, m, rx, l, r));
    }

    int sol(int l, int r){
        return sol(0,0,sz,l,r);
    }
};

vector<vector<int>>adj;
vector<int>in,out, flat;
vector<int>par;
int timer = 0;
void dfs(int u, int p){
    in[u] = timer;
    flat[timer] = u;
    timer++;
    for(int v : adj[u]){
        if(v==p)continue;
        par[v] = u;
        dfs(v,u);
    }
    out[u] = timer;
    flat[timer] = u;
    timer++;
}

void solve()
{
    int n;
    cin >> n;
    adj.resize(n+1);
    in.resize(n+1);
    out.resize(n+1);
    par.resize(n+1);
    flat.resize(2*n);
    for(int i= 1;i<n;++i){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1,-1);
    segtree st;
    st.init(2*n+1);
    int q;
    cin >> q;
    while(q--){
        int t, u;
        cin >> t >> u;
        if(t==1){
            // range update the segment to 1
            if(st.sol(in[u],out[u]+1)==0){
                // this subtree of this node gets water, but if there was another node that had no water then it passes the chain on
                st.rangeupdate(in[par[u]],in[par[u]]+1,0);
                st.rangeupdate(out[par[u]],out[par[u]]+1,0);

            }
            st.rangeupdate(in[u], out[u]+1, 1);
        }else if(t==2){
            // update this node to a 0
            
            st.rangeupdate(in[u], in[u]+1, 0);
            st.rangeupdate(out[u], out[u]+1, 0);
        }else{
            // if any node in subtree of this node has no water, then this node also has no water
            if(st.sol(in[u], out[u]+1)==0)cout << 0 << endl;
            else cout << 1 << endl;
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