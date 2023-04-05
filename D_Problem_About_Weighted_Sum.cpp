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
    vector<int>seg,sum,lazy;
    void init(int n){
        while(sz < n)sz*=2;
        seg.resize(sz*2);
        sum.resize(sz*2);
        lazy.resize(sz*2);
    }

    void set(int x, int lx, int rx, int i,int v){
        if(rx-lx==1){
            seg[x] = v;
            sum[x] = v;
            return;
        }
        int m = (lx+rx)/2;
        if(i < m)set(2*x+1,lx,m,i,v);
        else set(2*x+2,m,rx,i,v);
        sum[x] = sum[2*x+1]+sum[2*x+2];
        seg[x] = seg[2*x+1]+seg[2*x+2]+(((rx-lx)/2)*sum[2*x+2]);
    }

    void set(int i, int v){
        set(0,0,sz,i,v);
    }

    void update(int x, int lx, int rx, int l, int r, int v){
        if(lazy[x]!=0){
            sum[x]+=(rx-lx)*lazy[x];
            seg[x]+=(((rx-lx)*(rx-lx+1))/2) * lazy[x];
            if(rx-lx > 1){
                lazy[2*x+1] += lazy[x];
                lazy[2*x+2]+=lazy[x];
            }
            lazy[x] = 0;
        }
        if(lx >= l && rx <= r){
            sum[x]+=(rx-lx)*v;
            seg[x]+=(((rx-lx)*(rx-lx+1))/2) * v;
            if(rx-lx > 1){
                lazy[2*x+1] += v;
                lazy[2*x+2]+=v;
            }
            return;
        }
        if(rx <= l || lx >= r)return;
        int m = (lx+rx)/2;
        update(2*x+1,lx,m,l,r,v);
        update(2*x+2,m,rx,l,r,v);
        sum[x] = sum[2*x+1]+sum[2*x+2];
        seg[x] = seg[2*x+1]+seg[2*x+2]+(((rx-lx)/2)*sum[2*x+2]);

    }

    void update(int l, int r, int v){
        update(0,0,sz,l,r,v);
    }

    int sol(int x, int lx, int rx, int l, int r){
        if(lazy[x]!=0){
            sum[x]+=(rx-lx)*lazy[x];
            seg[x]+=(((rx-lx)*(rx-lx+1))/2) * lazy[x];
            if(rx-lx > 1){
                lazy[2*x+1] += lazy[x];
                lazy[2*x+2]+=lazy[x];
            }
            lazy[x] = 0;
        }
        if(lx >= l&& rx <= r){
            int curr = seg[x];
            int add = sum[x]*(lx-l);
            return curr+add;
        }
        if(rx <= l || lx >= r)return 0;
        int m = (lx+rx)/2;
        return sol(2*x+1,lx,m,l,r)+sol(2*x+2,m,rx,l,r);
    }

    int sol(int l, int r){
        return sol(0,0,sz,l,r);
    }
};
void solve()
{
    int n,q;
    cin >> n >> q;
    segtree st;
    st.init(n+1);
    for(int i = 1;i<=n;++i){
        int v;
        cin >> v;
        st.set(i,v);
    }
    while(q--){
        int t;
        cin >> t;
        if(t==1){
            int l,r,v;
            cin >> l >> r >> v;
            st.update(l,r+1,v);
        }else{
            int l,r;
            cin>> l >> r;
            cout << st.sol(l,r+1) << endl;
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