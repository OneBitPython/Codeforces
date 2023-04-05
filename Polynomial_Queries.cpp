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

struct ap{
    int a=0,d=0;
    void init(int x, int y){
        a = x;
        d = y;
    }

    int sum(int n){
        return (n*((2*a)+(n-1)*d))/2;
    }

    int term(int n){
        return a+(n-1)*d;
    }

    void add(ap b){
        a+=b.a;
        d+=b.d;
    }
    void reset(){
        a = 0;
        d = 0;
    }
};

int s(int a, int d, int n){
    return (n*((2*a)+(n-1)*d))/2;
}

struct segtree{
    vector<int>seg;
    vector<ap>lazy;
    int sz = 1;
    void init(int n){
        while(sz < n)sz*=2;
        seg.resize(sz*2);
        lazy.resize(sz*2);
    }

    void set(int x, int lx, int rx, int i, int v){
        if(rx-lx==1){
            seg[x] = v;
            return;
        }
        int m = (lx+rx)/2;
        if(i < m)set(2*x+1,lx,m,i,v);
        else set(2*x+2,m,rx,i,v);
        seg[x] = seg[2*x+1]+seg[2*x+2];
    }

    void set(int i, int v){
        set(0,0,sz,i,v);
    }

    void update(int x, int lx, int rx, int l, int r, ap add){
        if(lazy[x].a || lazy[x].d){
            seg[x] += lazy[x].sum(rx-lx);
            if(rx-lx > 1){
                lazy[2*x+1].add(lazy[x]);
                lazy[2*x+2].add({lazy[x].a+((rx-lx)/2)*lazy[x].d,lazy[x].d});
            }
            lazy[x].reset();
        }

        if(lx >= l && rx <= r){
            int fi = add.term(lx-l+1);
            seg[x] += s(fi,add.d,rx-lx);
            if(rx-lx > 1){
                lazy[2*x+1].add({fi,add.d});
                lazy[2*x+2].add({fi+((rx-lx)/2)*add.d,add.d});
            }
            return;
        }
        if(rx <= l || lx >= r)return;
        int m = (lx+rx)/2;
        update(2*x+1,lx,m,l,r,add);
        update(2*x+2,m,rx,l,r,add);
        seg[x] = seg[2*x+1]+seg[2*x+2];
    }

    void update(int l, int r, int a, int d){
        update(0,0,sz,l,r,{a,d});
    }

    int sol(int x, int lx, int rx, int l, int r){
        if(lazy[x].a || lazy[x].d){
            seg[x] += lazy[x].sum(rx-lx);
            if(rx-lx > 1){
                lazy[2*x+1].add(lazy[x]);
                lazy[2*x+2].add({lazy[x].a+((rx-lx)/2)*lazy[x].d,lazy[x].d});
            }
            lazy[x].reset();
        }
        if(lx >= l && rx <= r)return seg[x];
        if(rx <= l || lx >= r)return 0ll;
        int m = (lx+rx)/2;
        return sol(2*x+1, lx, m, l, r)+sol(2*x+2,m,rx,l,r);
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
            int l,r,a,d;
            cin >> l >> r;
            st.update(l,r+1,1,1);
        }else{
            int l,r;
            cin >> l >> r;
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