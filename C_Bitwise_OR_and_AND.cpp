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
    vector<int>seg,lazy;
    int sz = 1;
    void init(int n){
        while(sz < n)sz*=2;
        seg.resize(sz*2);
        lazy.resize(sz*2);
    }

    void rangeupdate(int x, int lx, int rx, int l, int r, int v){
        if(lazy[x]){
            seg[x] |= lazy[x];
            if(rx-lx > 1){
                lazy[2*x+1] |= lazy[x];
                lazy[2*x+2] |= lazy[x];
            }
            lazy[x] = 0;
        }
        if(rx <= l || lx >= r)return;
        if(lx >= l && rx <= r){
            seg[x] |= v;
            if(rx-lx > 1){
                lazy[2*x+1]|=v;
                lazy[2*x+2]|=v;
            }
            return;
        }
        int m = (lx+rx)/2;
        rangeupdate(2*x+1,lx,m,l,r,v);
        rangeupdate(2*x+2,m,rx,l,r,v);
        seg[x] = (seg[2*x+1]&seg[2*x+2]);
    }

    void rangeupdate(int l, int r, int v){
        rangeupdate(0,0,sz,l,r,v);
    }

    int sol(int x, int lx, int rx, int l,int r){
        if(lazy[x]){
            seg[x] |= lazy[x];
            if(rx-lx > 1){
                lazy[2*x+1] |= lazy[x];
                lazy[2*x+2] |= lazy[x];
            }
            lazy[x] = 0;
        }

        if(lx >= l && rx <= r)return seg[x];
        if(rx <= l || lx >= r)return -1;
        int m = (lx+rx)/2;
        int ri = sol(2*x+1,lx,m,l,r);
        int g = sol(2*x+2,m,rx,l,r);
        int res = 0;
        if(g!=-1)res=g;
        else if(r!=0)res=ri;
        if(g!=-1)res&=g;
        if(ri!=-1)res&=ri;
        return res;
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
    st.init(n);
    while(q--){
        int t;
        cin >> t;
        if(t==1){
            int l,r,v;
            cin>> l >> r >>v;
            st.rangeupdate(l,r,v);
        }else{
            int l,r;
            cin >> l >> r;
            cout << st.sol(l,r) << endl;
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