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
    vector<int>seg;
    void init(int n){
        while(sz < n)sz*=2;
        seg.resize(sz*2);
    }

    void set(int x, int lx, int rx, int i, int v){
        if(rx-lx==1){
            seg[x] += v;
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
        int m = (lx+rx)/2;
        return sol(2*x+1,lx,m,l,r) + sol(2*x+2,m,rx,l,r);
    }

    int sol(int l, int r){
        return sol(0,0,sz,l,r);
    }
};
struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> const &a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            set(i, a[i]);
    }

    int sol(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sol(int l, int r) {
        return sol(r) - sol(l - 1);
    }

    void set(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

const int mxn = 1e6+5;
int a[mxn],pos[mxn];
void solve()
{
    int n,q;
    cin >> n >> q;

    for(int i = 1;i<=n;++i)cin >> a[i],pos[a[i]] = i;


    FenwickTree st(n+1);


    for(int i= 1;i<=n;++i)st.set(i,1);
    for(int i = 1;i<=n;++i){
        int x = st.sol(i,i);
        for(int j = a[i]*2;j<=n;j+=a[i]){
            if(pos[j] < i)continue;
            st.set(pos[j],x);
        }
    }

    vector<vector<pair<int,int>>>queries(n+1);
    for(int i = 1;i<=q;++i){
        int l,r;
        cin >> l >> r;
        queries[l].pb({r,i});
    }

    int till = 1;

    vector<int>res(q+1),cut(n+1);
    for(int i = 1;i<=n;++i){
        while(till < i){
            cut[till] = 1;
            for(int j= a[till];j<=n;j+=a[till]){
                if(pos[j] < till)continue;
                for(int k = j*2;k<=n;k+=j){
                    if(pos[k] >= till && pos[k] >=pos[j]){
                        cut[pos[k]] += cut[pos[j]];
                    }
                }
                st.set(pos[j],-cut[pos[j]]);
            }
            for(int j = a[till];j<=n;j+=a[till])cut[pos[j]] = 0;
            till++;
        }
        for(auto &[r,k] : queries[i]){
            res[k] = st.sol(i,r);
        }
    }
    for(int i = 1;i<=q;++i)cout << res[i] << ' ';
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