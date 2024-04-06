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
vector<int>flat,in,out;

struct segtree{
    int sz = 1;
    vector<int>lazy, seg;
    void init(int n){
        while(sz < n)sz*=2;
        seg.resize(sz*2);lazy.resize(sz*2);

    }

    void upd(int x, int lx, int rx, int l, int r, int v){
        if(lazy[x]!=0){
            seg[x] += (rx-lx)*lazy[x];
            if(rx-lx > 1){
                lazy[2*x+1] += lazy[x];
                lazy[2*x+2] += lazy[x];
            }
            lazy[x] = 0;
        }
        if(lx >= l && rx <= r){
            seg[x] += (rx-lx)*v;
            if(rx-lx > 1){
                lazy[2*x+1] += v;
                lazy[2*x+2] += v;
            }
            return;
        }
        if(rx <= l || lx>= r)return;
        int m = (lx+rx)/2;
        upd(2*x+1,lx,m,l,r,v);
        upd(2*x+2,m,rx,l,r,v);
        seg[x] = seg[2*x+1] + seg[2*x+2];
    }

    void upd(int l, int r, int v){
        // add v to all in the range [l,r)
        upd(0,0,sz,l,r,v);
    }

    int sol(int x, int lx, int rx, int l, int r){
        if(lazy[x]!=0){
            seg[x] += (rx-lx)*lazy[x];
            if(rx-lx > 1){
                lazy[2*x+1] += lazy[x];
                lazy[2*x+2] += lazy[x];
            }
            lazy[x] = 0;
        }
        if(lx >= l && rx <= r)return seg[x];
        if(rx <= l || lx >= r)return 0ll;
        int m = (lx+rx)/2;
        return sol(2*x+1,lx,m,l,r) + sol(2*x+2,m,rx,l,r);
    }

    int sol(int l, int r){
        return sol(0,0,sz,l,r);
    }
};

int n;
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


void solve()
{
    int q;
    cin >> q;
    adj = vector<vector<int>>(q+2);
    int curr = 2;
    t = 1;
    vector<vector<int>>queries(q+2);
    vector<int>added(q+1);
    for(int i = 1;i<=q;++i){
        int t;
        cin >> t;
        if(t==1){
            int v;
            cin >> v;
            queries[i] = {t,v};
            added[i] = curr;
            adj[v].pb(curr);
            adj[curr].pb(v);
            curr++;
        }else{
            int v,x;cin >> v >> x;
            queries[i] = {t,v,x};
        }
    }
    n = curr-1;
    in = vector<int>(n+1);
    flat = vector<int>(2*n+1);
    out = vector<int>(n+1);
    
    dfs(1,-1);
    segtree st;st.init(2*n+1);
    for(int i = 1;i<=q;++i){
        int t = queries[i][0];
        if(t==1){
            int v = added[i];
            int x = st.sol(in[v],in[v]+1);
            st.upd(in[v],in[v]+1,-x);
            st.upd(out[v],out[v]+1,-x);
        }else{
            int v = queries[i][1], x = queries[i][2];
            st.upd(in[v],out[v]+1,x);
        }
    }
    for(int i = 1;i<=n;++i)cout << st.sol(in[i],in[i]+1) << ' ';
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
    cin >> T;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}