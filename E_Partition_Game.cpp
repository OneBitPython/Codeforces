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
        while( sz < n)sz*=2;
        seg.resize(sz*2);
    }

    void set(int x, int lx, int rx, int i, int v){
        if(rx-lx==1){
            seg[x] = v;
            return;
        }
        int m = (lx+rx)/2;
        if(i < m)set(2*x+1, lx, m, i, v);
        else set(2*x+2, m, rx, i, v);
        seg[x] = seg[2*x+1]+seg[2*x+2];
    }

    void set(int i, int v){
        set(0,0,sz,i,v);
    }

    int sol(int x, int lx, int rx, int l, int r){
        if(lx >= l && rx <= r)return seg[x];
        if(rx <= l || lx >= r)return 0ll;
        int m = (lx+rx)/2;
        return sol(2*x+1, lx, m, l, r)+sol(2*x+2, m, rx, l,r );
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
            add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};
const int N = 35001,K = 101;
int dp[N][K];
vector<int>nxt;
FenwickTree st(N+1);

void dnc(int j, int l, int r, int optl, int optr){
    if(l > r)return;
    int m = (l+r)/2;
    pair<int,int>best = {1e18,0};
    for(int i = optl;i<min(optr+1,m);++i){
        if(nxt[i]!=-1)st.add(nxt[i],i-nxt[i]);
        best = min(best, {dp[i][j-1]+st.sum(i+1,m),i});
    }
    for(int i = optl;i<min(optr+1,m);++i){
        if(nxt[i]!=-1)st.add(nxt[i],nxt[i]-i);
    }
    dp[m][j] = best.first;
    int opt = best.second;
    dnc(j,l,m-1,optl,opt);
    for(int i = optl;i<opt;++i){
        if(nxt[i]!=-1)st.add(nxt[i],i-nxt[i]);
    }
    dnc(j,m+1,r,opt,optr);
    for(int i = optl;i<opt;++i){
        if(nxt[i]!=-1)st.add(nxt[i],nxt[i]-i);
    }
}

void solve()
{
    int n,k;
    cin >> n >> k;
    nxt.resize(n+1,-1);
    vector<int>a(n+1);
    vector<vector<int>>pos(n+1);
    for(int i = 1;i<=n;++i)cin >> a[i],pos[a[i]].pb(i);
    for(int i = 0;i<=n;++i){
        for(int j = 0;j<=k;++j)dp[i][j] = 1e18;
    }
    for(int i = 1;i<=n;++i){
        for(int j = 0;j<(int)(pos[i].size())-1;++j)nxt[pos[i][j]] = pos[i][j+1];
    }
    for(int i= 1;i<=n;++i){
        if(nxt[i]!=-1)st.add(nxt[i],nxt[i]-i);
    }
    dp[0][0] = 0;
    for(int j = 1;j<=k;++j)dnc(j,1,n,0,n-1);
    cout << dp[n][k] << endl;
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