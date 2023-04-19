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



int check(vector<int>a, int x){
    return (accumulate(all(a),0ll))>=(x*(int)(a.size()));
}
struct segtree{
    vector<int>seg,lazy;
    int sz = 1;
    void init(int n){
        while(sz < n)sz*=2;
        seg.resize(sz*2,1e18);
        lazy.resize(sz*2,1e18);
    }
 
    void rangeupdate(int x, int lx, int rx, int l, int r, int v){
        if(lazy[x]!=1e18){
            seg[x] = min(seg[x],lazy[x]);
            if(rx-lx > 1){
                lazy[2*x+1] = min(lazy[2*x+1],lazy[x]);
                lazy[2*x+2] = min(lazy[2*x+2],lazy[x]);
            }
            lazy[x] = 1e18;
        }
        if(rx <= l || lx >= r)return;
        if(lx >= l && rx <= r){
            seg[x] = min(seg[x], v);
            if(rx-lx > 1){
                lazy[2*x+1] = min(lazy[2*x+1], v);
                lazy[2*x+2] = min(lazy[2*x+2],v);
            }
            return;
        }
        int m = (lx+rx)/2;
        rangeupdate(2*x+1,lx,m,l,r,v);
        rangeupdate(2*x+2,m,rx,l,r,v);
        seg[x] = min(seg[2*x+1],seg[2*x+2]);
    }
 
    void rangeupdate(int l, int r, int v){
        rangeupdate(0,0,sz,l,r,v);
    }
 
    int sol(int x, int lx, int rx, int l,int r){
        if(lazy[x]!=1e18){
            seg[x] = min(seg[x],lazy[x]);
            if(rx-lx > 1){
                lazy[2*x+1] = min(lazy[2*x+1],lazy[x]);
                lazy[2*x+2] = min(lazy[2*x+2],lazy[x]);
            }
            lazy[x] = 1e18;
        }
 
        if(lx >= l && rx <= r)return seg[x];
        if(rx <= l || lx >= r)return 1e18;
        int m = (lx+rx)/2;
        return min(sol(2*x+1, lx, m, l, r),sol(2*x+2,m,rx,l,r));
    }
 
    int sol(int l, int r){
        return sol(0,0,sz,l,r);
    }
};
void solve()
{
    int n;
    cin >> n;
    vector<int>a(n+1);
    for(int i = 1;i<=n;++i)cin>>a[i];
    int x;
    cin >> x;
    vector<int>e(n+1);
    int p = 1;
    for(int i = 2;i<=n;++i){
        if((i-p+1)>=2 && !check({a[i],a[i-1]},x)){
            for(int j = p;j<i;++j)e[j] = max(e[j],i-1);
            p = i;

        }else if(((i-p+1)>=3 && !check({a[i],a[i-1],a[i-2]}, x))){
            for(int j = p;j<i;++j)e[j] = max(e[j],i-1);
            p = i-1;
            i--;
        }
    }
    for(int j = p;j<=n;++j)e[j] = n;
    segtree st;
    st.init(n+1);
    st.rangeupdate(0,1,0);
    
    vector<int>dp(n+1);
    for(int i = 1;i<=n;++i){
        if(i==1)st.rangeupdate(i,e[i]+1,0);
        else st.rangeupdate(i,e[i]+1,dp[i-2]+1);

        dp[i] = st.sol(i,i+1);
        dp[i] = min(dp[i],dp[i-1]+1);
    }
    cout << n-dp.back() << endl;
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