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
    int sz =1;
    vector<int>seg, lazy;
    void init(int n){
        while(sz < n)sz*=2;
        seg.resize(sz*2);
        lazy.resize(sz*2);
    }
 
    void set(int x, int lx, int rx, int i, int v){
        if(rx - lx == 1){
            // leaf
            seg[x] = v;
            return;
        }
        int m = (lx+rx)/2;
        if(i < m)set(2*x+1, lx, m, i, v);
        else set(2*x+2, m, rx, i, v);
        seg[x] = max(seg[2*x+1], seg[2*x+2]);
    }
 
    void set(int i, int v){
        set(0, 0, sz, i, v);
    }
 
    void reset(){
        for(int i = 0;i<2*sz;++i)lazy[i] = 0, seg[i] = 0;
    }
    void rangeupdates(int x,int lx, int rx, int l, int r,int val){
 
        if(lazy[x]){
            seg[x]+=lazy[x];
            if(rx-lx > 1){
                lazy[2*x+1]+=lazy[x];
                lazy[2*x+2]+=lazy[x];
            }
            lazy[x] = 0;
 
        }
 
        if(rx <= l || lx>=r)return;
        if(lx >= l && rx<=r){
            seg[x]+=val;
            if(rx - lx > 1){
                lazy[2*x+1]+=val;
                lazy[2*x+2]+=val;
            }
            return;
        }
        int m = (lx+rx)/2;
        rangeupdates(2*x+1, lx, m, l, r, val);
        rangeupdates(2*x+2, m, rx, l, r, val);
        seg[x] = max(seg[2*x+1], seg[2*x+2]);
    }
 
    void rangeupdates(int l, int r, int val){
        rangeupdates(0, 0, sz, l, r, val);
    }
 
    int sol(int x, int lx, int rx, int l, int r){
        if(lazy[x]){
            // carry on the updates to children as well
            seg[x]+=lazy[x];
            if(rx - lx > 1){
                lazy[2*x+1]+=lazy[x];
                lazy[2*x+2]+=lazy[x];
            }
            lazy[x] = 0;
        }
 
        if(lx>=r || rx<=l)return 0ll;
        if(lx>=l && rx<= r)return seg[x];
        int m = (lx+rx)/2;
        return max(sol(2*x+1, lx, m, l, r), sol(2*x+2, m, rx, l, r));
    }
 
    int sol(int l, int r){
        return sol(0, 0, sz, l, r);
    }
};
 

void solve()
{
    int n,k,x;
    cin >> n >> k >> x;
    if(x < 0)k = n-k, x = abs(x);
    vector<int>a(n+1);
    for(int i = 1;i<=n;++i)cin >> a[i];
    /*
    let m be size of subarray

    subcost +min(m,k)x - (m-min(m,k))x
    
    assume k < m 
    cost = subcost + kx - x(m-k)
    cost = subcost + 2kx - mx

    if k >= m
    cost = subcost + mx
    
    solve seperately for both cases
    */
    segtree st;
    st.init(n+1);
    int res = 0;
    // solve for k >= m
    for(int i = 1;i<=n;++i){
        st.rangeupdates(1,i+1,a[i]);
        st.rangeupdates(1,i+1,x);
        res = max(res, st.sol(max(1ll,i-k+1),i+1));
    }
    st.reset();
    // solve for k < m
    
    for(int i = 1;i<=n;++i){
        st.rangeupdates(1,i+1,a[i]);

        st.rangeupdates(1,i+1,-x);
        st.rangeupdates(1,i+1,2*k*x);
        if(i-k >= 1)res = max(res, st.sol(1,i-k+1));
        st.rangeupdates(1,i+1,-2*k*x);

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