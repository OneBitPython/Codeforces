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
    // range add range value
    vector<int>seg;
    int sz = 1;
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
        if(i < m)set(2*x+1,lx,m,i,v);
        else set(2*x+2,m,rx,i,v);
        seg[x] = seg[2*x+1] + seg[2*x+2];
    }

    void set(int i, int v){
        set(0,0,sz,i,v);
    }

    int sol(int x, int lx, int rx, int l, int r){
        if(lx >= l && rx <= r)return seg[x];
        if(rx <= l || lx >= r)return 0ll;
        int m= (lx+rx)/2;
        return (sol(2*x+1,lx,m,l,r) +  sol(2*x+2,m,rx,l,r));
    }

    int sol(int l, int r){
        return sol(0,0,sz,l,r);
    }
};
struct segtree1{
    // range add range value
    vector<int>lazy,seg;
    int sz = 1;
    void init(int n){
        while(sz < n)sz*=2;
        seg.resize(sz*2);
        lazy.resize(sz*2);
    }

    void upd(int x, int lx, int rx, int l, int r, int v){
        if(lazy[x]){
            seg[x] += lazy[x];
            if(rx-lx > 1){
                lazy[2*x+1] += lazy[x];
                lazy[2*x+2] += lazy[x];
            }
            lazy[x] = 0;
        }
        if(lx >= l && rx <= r){
            seg[x] += v;
            if(rx-lx > 1){
                lazy[2*x+1] += v;
                lazy[2*x+2] += v;
            }
            return;
        }
        if(rx <= l || lx >= r)return;
        int m = (lx+rx)/2;
        upd(2*x+1,lx,m,l,r,v);
        upd(2*x+2,m,rx,l,r,v);
        seg[x] = max(seg[2*x+1], seg[2*x+2]);
    }

    void upd(int l, int r, int v){
        upd(0,0,sz,l,r,v);
    }

    int sol(int x, int lx, int rx, int l, int r){
        if(lazy[x]){
            seg[x] += lazy[x];
            if(rx-lx > 1){
                lazy[2*x+1] += lazy[x];
                lazy[2*x+2] += lazy[x];
            }
            lazy[x] = 0;
        }
        if(lx >= l && rx <= r)return seg[x];
        if(rx <= l || lx >= r)return 0ll;
        int m= (lx+rx)/2;
        return max(sol(2*x+1,lx,m,l,r), sol(2*x+2,m,rx,l,r));
    }

    int sol(int l){
        return sol(0,0,sz,l,l+1);
    }
};
char f(int x){
    if(x<=(122))return x;
    return (x-123)%26 + 'a';
}
void solve()
{
    int n,q;
    cin >> n >> q;
    string s;
    cin >> s;
    s = "0"+s;
    segtree1 st;
    segtree st1,st2;
    st.init(n+1);
    st1.init(n+1);
    st2.init(n+1);
    for(int i = 1;i<=n;++i) st.upd(i,i+1,s[i]-'a'+97);
    for(int i = 1;i<n;++i){
        if(s[i]==s[i+1])st1.set(i,1);
        if((i+2) <= n && s[i] == s[i+2])st2.set(i,1);   
    }
    while(q--){
        int t;cin >> t;
        int l,r;
        cin >> l >> r;
        if(t==1){
            int x;
            cin >> x;
            st.upd(l,r+1,x);
            if(l>=2){
                if(f(st.sol(l-1)) == f(st.sol(l)))st1.set(l-1,1);
                else st1.set(l-1,0);
            }
            if(r <= (n-1)){
                if(f(st.sol(r)) == f(st.sol(r+1)))st1.set(r,1);
                else st1.set(r,0);
            }
            for(int i = max(1ll,l-5);i<=l;++i){
                if((i+2) <= n && f(st.sol(i))==f(st.sol(i+2)))st2.set(i,1);
                else st2.set(i,0);
            }
            for(int i =max(1ll,r-5);i<=r;++i){
                if((i+2) <= n && f(st.sol(i))==f(st.sol(i+2)))st2.set(i,1);
                else st2.set(i,0);
            }
        }else{
            int qq = 0;
            if(r-l+1 >= 2)qq+=st1.sol(l,r);
            if(r-l+1 >= 3)qq+=st2.sol(l,r-1);
            if(qq > 0)cout << "NO" << endl;
            else cout << "YES" << endl;
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
    cin >> T;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}