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

vector<int>id,sz,mx,mn;
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
        if(i < m)set(2*x+1,lx, m, i, v);
        else set(2*x+2, m, rx, i, v);
        seg[x] = min(seg[2*x+1],seg[2*x+2]);
    }
 
    void set(int i, int v){
        set(0,0,sz,i,v);
    }
 
    int sol(int x, int lx, int rx, int l, int r){
        if(rx <= l || lx >= r)return 1e18;
        if(lx >= l && rx <= r)return seg[x];
        int m = (lx+rx)/2;
        return min(sol(2*x+1, lx, m, l, r),sol(2*x+2, m, rx, l, r));
    }
 
    int sol(int l, int r){
        return sol(0,0,sz,l,r);
    }
};
struct segtree2{
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
        if(i < m)set(2*x+1,lx, m, i, v);
        else set(2*x+2, m, rx, i, v);
        seg[x] = __gcd(seg[2*x+1],seg[2*x+2]);
    }
 
    void set(int i, int v){
        set(0,0,sz,i,v);
    }
 
    int sol(int x, int lx, int rx, int l, int r){
        if(rx <= l || lx >= r)return 0ll;
        if(lx >= l && rx <= r)return seg[x];
        int m = (lx+rx)/2;
        return __gcd(sol(2*x+1, lx, m, l, r),sol(2*x+2, m, rx, l, r));
    }
 
    int sol(int l, int r){
        return sol(0,0,sz,l,r);
    }
};
int root(int x){
    if(id[x]==x)return x;
    return id[x]=root(id[x]);
}
bool merge(int u, int v){
    u = root(u);
    v = root(v);
    if(u==v)return 0;
    if(sz[v]> sz[u])swap(u,v);
    id[v] = u;
    sz[u]+=sz[v];
    mn[u] = min(mn[u], mn[v]);
    mx[u] = max(mx[v], mx[u]);
    return 1;
}
void solve()
{
    int n,p;
    cin >> n >> p;
    id = vector<int>(n+1);
    sz = vector<int>(n+1);
    mn = vector<int>(n+1);
    mx = vector<int>(n+1);
    vector<int>a(n+1);
    segtree mini;
    segtree2 gcd;
    mini.init(n+1);
    gcd.init(n+1);
    for(int i = 1;i<=n;++i)cin >> a[i],id[i]=i,sz[i]=1,mn[i]=i,mx[i]=i;
    for(int i = 1;i<=n;++i)mini.set(i,a[i]),gcd.set(i,a[i]);
    vector<pair<int,int>>b;
    for(int i = 1;i<=n;++i)b.pb({a[i],i});
    sort(all(b));
    int res = 0;
    for(int i = 0;i<n;++i){
        int idx = b[i].second;
        if(b[i].first>p)break;
        int j = mx[root(idx)]+1;
        while(j <= n){
            if(mini.sol(idx,j+1)==b[i].first && gcd.sol(idx,j+1)==b[i].first)merge(idx,j),res+=b[i].first;
            else break;
            j = mx[root(j)]+1;
        }
        j = mn[root(idx)]-1;
        while(j >=1){
            if(mini.sol(j,idx+1)==b[i].first && gcd.sol(j,idx+1)==b[i].first)merge(idx,j),res+=b[i].first;
            else break;
            j = mn[root(j)]-1;
        }
    }
    for(int i = 1;i<n;++i){
        if(merge(i,i+1))res+=p;
    }
    cout << res << endl;
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