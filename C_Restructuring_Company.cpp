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
    vector<int>seg;
    void init(int n){
        while(sz < n)sz*=2;
        seg.resize(sz*2);
    }

    void set(int x, int lx, int rx, int i, int v){
        if(rx-lx==1){
            seg[x] = v;
            return;
        }
        int m = (lx+rx)/2;
        if(i < m)set(2*x+1, lx, m, i, v);
        else set(2*x+2, m, rx, i, v);
        seg[x] = min(seg[2*x+1], seg[2*x+2]);
    }

    void set(int i, int v){
        set(0,0,sz,i,v);
    }

    int sol(int x, int lx, int rx, int l, int r){
        // first value in the range l, r that is 0
        if(rx <= l || lx >= r || seg[x])return -1;
        if(rx-lx==1){
            if(seg[x]==0)return lx;
            return -1;
        }
        int m = (lx+rx)/2;
        int res = sol(2*x+1, lx, m,l,r);
        if(res==-1)res = sol(2*x+2, m, rx, l, r);
        return res;
    }

    int sol(int l, int r){
        if(seg[0]==1)return -1;
        return sol(0,0,sz,l,r);
    }
};
vector<int>id,sz;
int n,k;
segtree st;
int root(int x){
    if(id[x]==x)return x;
    return id[x] = root(id[x]);
}
int same(int u, int v){
    return root(u)==root(v);
}
void merge(int u, int v){
    u = root(u);
    v = root(v);
    if(u==v)return;
    if(sz[v] > sz[u])swap(u,v);
    id[v] = u;
    sz[u]+=sz[v];
}

void merge2(int l, int r){
    int u = l;
    int i = l+1;
    while(i <= r){
        int val = st.sol(i,r+1);
        if(val==-1)break;
        st.set(val,1);
        merge(u,val);
        i = val+1;
    }
}
void solve()
{
    cin>> n >> k;
    id.resize(n+1);
    sz.resize(n+1,1);
    iota(all(id),0ll);
    st.init(n+1);
    for(int i = 1;i<=k;++i){
        int t;
        cin >> t;
        int u,v;
        cin >>u >> v;
        if(t==1)merge(u,v);
        else if(t==2)merge2(u,v);
        else cout << (same(u,v)?"YES":"NO") << endl;
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