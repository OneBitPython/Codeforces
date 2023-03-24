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

struct node{
    int val,idx,pos;
};
struct segtree{
    vector<node>seg;
    vector<int>lazy;
    int sz = 1;
    void init(int n){
        while(sz < n)sz*=2;
        seg.resize(sz*2);
        lazy.resize(sz*2);
    }

    node merge(node a, node b){
        if(a.val < b.val)return a;
        if(a.val==b.val){
            if(a.pos < b.pos)return a;
        }
        return b;
    }

    void set(int x, int lx, int rx, int i, node v){
        if(lazy[x]){
            seg[x].val -= lazy[x];
            if(rx-lx > 1){
                lazy[2*x+1] += lazy[x];
                lazy[2*x+2] += lazy[x];
            }
            lazy[x] = 0;
        }
        if(rx-lx==1){
            seg[x] = v;
            return;
        }
        int m = (lx+rx)/2;
        if(i < m)set(2*x+1, lx, m, i, v);
        else set(2*x+2, m, rx, i, v);
        seg[x] = merge(seg[2*x+1], seg[2*x+2]);
    }

    void set(int i, node v){
        set(0,0,sz,i,v);
    }

    void rangeupdate(int x, int lx, int rx, int l, int r, int v){
        if(lazy[x]){
            seg[x].val -= lazy[x];
            if(rx-lx > 1){
                lazy[2*x+1] += lazy[x];
                lazy[2*x+2] += lazy[x];
            }
            lazy[x] = 0;
        }
        if(lx >= r || rx <= l)return;
        if(lx >= l && rx <= r){
            seg[x].val-=v;
            if(rx-lx > 1){
                lazy[2*x+1] += v;
                lazy[2*x+2] += v;
            }
            return;
        }
        int m = (lx+rx)/2;
        rangeupdate(2*x+1, lx, m, l, r,v);
        rangeupdate(2*x+2, m, rx, l, r,v);
        seg[x] = merge(seg[2*x+1], seg[2*x+2]);
    }

    void rangeupdate(int l, int r, int v){
        rangeupdate(0,0,sz,l,r,v);
    }

    node sol(int x, int lx, int rx, int l, int r){
        if(lazy[x]){
            seg[x].val -= lazy[x];
            if(rx-lx > 1){
                lazy[2*x+1] += lazy[x];
                lazy[2*x+2] += lazy[x];
            }
            lazy[x] = 0;
        }
        if(lx >= l && rx <= r)return seg[x];
        if(lx >= r || rx <= l)return {1000000000,0,0};
        int m = (lx+rx)/2;
        return merge(sol(2*x+1, lx, m, l, r),sol(2*x+2, m, rx, l, r));
    }

    node sol(int l, int r){
        return sol(0,0,sz,l,r);
    }
};
void solve()
{
    int n;
    cin >>n;
    vector<int>b(n+1);
    for(int i = 1;i<=n;++i)cin >> b[i];
    /*
    (n/y) = x for all y between [n/(x+1)+1, n/x]
    */
    vector<vector<pair<int,int>>>a(n+1);
    set<int>rem;
    vector<int>res(n+1);
    for(int i = 1;i<=n;++i)rem.insert(i);
    for(int i = 1;i<=n;++i){
        int l = 0, r = 0;
        if(b[i]==0)l = i+1, r = n;
        else{
            l = i/(b[i]+1)+1;
            r = i/b[i];
        }
        a[l].pb({r-l+1, i});
    }
    segtree st;
    vector<int>cnt(n+1);
    for(int i = 1;i<=n;++i)cnt[i] = cnt[i-1]+(int)(a[i].size());
    st.init(n+2);
    int p = 1;
    for(int i = 1;i<=n;++i){
        for(auto x : a[i]){
            node c;
            c.val = x.first;
            c.idx = x.second;
            c.pos = p;
            st.set(p,c);
            p++;
        }
    }
    for(auto x : rem){
        node c= st.sol(1,cnt[x]+1);
        res[c.idx] = x;
        st.rangeupdate(c.pos,c.pos+1,-10000000000);
        st.rangeupdate(1,cnt[x]+1,1);
    }
    for(int i = 1;i<=n;++i)cout << res[i] << ' ';
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