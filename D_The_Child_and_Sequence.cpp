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
    vector<int>seg2;
    vector<pair<int,int>>seg;
    void init(int n){
        while(sz < n)sz*=2;
        seg.resize(sz*2,{-1e18,0});
        seg2.resize(sz*2);
    }

    pair<int,int> merge(pair<int,int>a, pair<int,int>b){
        if(a.first > b.first)return a;
        return b;
    }

    void set(int x, int lx, int rx, int i, int v){
        if(rx-lx==1){
            seg[x] = {v, i};
            seg2[x] = v;
            return;
        }
        int m = (lx+rx)/2;
        if(i < m)set(2*x+1, lx, m, i, v);
        else set(2*x+2, m, rx, i, v);
        seg[x] = merge(seg[2*x+1], seg[2*x+2]);
        seg2[x] = seg2[2*x+1] + seg2[2*x+2];
    }

    void set(int i, int v){
        set(0,0,sz,i,v);

    }

    pair<int,int> sol(int x, int lx,int rx, int l, int r){
        if(lx >= l && rx <= r){
            return seg[x];
        }
        if(lx >= r || rx <= l)return {-1e18,0};
        int m = (lx+rx)/2;
        return merge(sol(2*x+1, lx, m, l, r), sol(2*x+2, m, rx, l, r));
    }

    pair<int,int> sol(int l, int r){
        
        return sol(0,0,sz,l,r);
    }
    int sum(int x, int lx,int rx, int l, int r){
        if(lx >= l && rx <= r)return seg2[x];
        if(lx >= r || rx <= l)return 0ll;
        int m = (lx+rx)/2;
        return (sum(2*x+1, lx, m, l, r) + sum(2*x+2, m, rx, l, r));
    }
    int sum(int l, int r){
        return sum(0,0,sz,l,r);
    }
};

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int>a(n);
    for(int &u : a)cin >> u;
    segtree st;
    st.init(n);
    for(int i = 0;i<n;++i)st.set(i,a[i]);
    while(q--){
        int t;
        cin >> t;
        if(t==1){
            int l, r;
            cin >> l >> r;
            cout << st.sum(l-1, r) << endl;
        }else if(t==2){
            int l, r, x;
            cin >> l >> r >> x;
            while(1){
                pair<int,int> res = st.sol(l-1, r);
                if(res.first < x)break;
                st.set(res.second, res.first%x);
            }
        }else{
            int k,x;
            cin >> k >> x;
            st.set(k-1, x);
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