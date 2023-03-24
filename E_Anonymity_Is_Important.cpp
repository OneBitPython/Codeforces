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
        seg[x] = (seg[2*x+1] + seg[2*x+2]);
    }
 
    void set(int i, int v){
        set(0, 0, sz, i, v);
    }
 
    void rangeupdates(int x,int lx, int rx, int l, int r,int val){
 
        if(lazy[x]){
            seg[x]=(rx-lx)*lazy[x];
            if(rx-lx > 1){
                lazy[2*x+1]=lazy[x];
                lazy[2*x+2]=lazy[x];
            }
            lazy[x] = 0;
 
        }
 
        if(rx <= l || lx>=r)return;
        if(lx >= l && rx<=r){
            seg[x]=(rx-lx)*val;
            if(rx - lx > 1){
                lazy[2*x+1]=val;
                lazy[2*x+2]=val;
            }
            return;
        }
        int m = (lx+rx)/2;
        rangeupdates(2*x+1, lx, m, l, r, val);
        rangeupdates(2*x+2, m, rx, l, r, val);
        seg[x] = (seg[2*x+1]+ seg[2*x+2]);
    }
 
    void rangeupdates(int l, int r, int val){
        rangeupdates(0, 0, sz, l, r, val);
    }
 
    int sol(int x, int lx, int rx, int l, int r){
        if(lazy[x]){
            seg[x]=(rx-lx)*lazy[x];
            if(rx-lx > 1){
                lazy[2*x+1]=lazy[x];
                lazy[2*x+2]=lazy[x];
            }
            lazy[x] = 0;
 
        }
 
        if(lx>=r || rx<=l)return 0ll;
        if(lx>=l && rx<= r)return seg[x];
        int m = (lx+rx)/2;
        return (sol(2*x+1, lx, m, l, r) + sol(2*x+2, m, rx, l, r));
    }
 
    int sol(int l, int r){
        return sol(0, 0, sz, l, r);
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
void solve()
{
    int n,q;
    cin >> n >> q;
    segtree st; // range sum range update
    segtree2 st2; // point set range min
    st2.init(n+1);
    st.init(n+1);
    for(int i = 0;i<=n;++i)st2.set(i,n+1);
    for(int i = 1;i<=q;++i){
        int t;
        cin >> t;
        if(t==0){
            int l,r,x;
            cin >> l >> r >> x;
            if(x==0){
                st.rangeupdates(l,r+1,1);
            }else{
                int val = st2.sol(l,l+1);
                val = min(val,r);
                st2.set(l,val);
            }
        }else{
            int x;
            cin >> x;
            if(st.sol(x,x+1)==1){
                cout << "NO" << endl;
                continue;
            }
            // find min l such that all in [l,x] are healthy
            int l = 1, r = x;
            int L = x;
            while(l <= r){
                int m = (l+r)/2;
                if(st.sol(m,x)==(x-m))L = m, r = m-1;
                else l = m+1;
            }
            int R = x;
            l = x;
            r = n;
            while(l <= r){
                int m = (l+r)/2;
                if(st.sol(x+1,m+1)==(m-x))R = m, l = m+1;
                else r = m-1;
            }
            int val = st2.sol(L,x+1);
            if(val <= R)cout << "YES" << endl;
            else cout << "N/A" << endl;
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