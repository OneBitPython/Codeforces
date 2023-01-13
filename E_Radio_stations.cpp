#include <bits/stdc++.h>
using namespace std;

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


struct mergesortree{
    vector<vector<int>>seg;
    int sz = 1;
    void init(int n){
        while(sz < n)sz*=2;
        seg.resize(sz*2);
    }

    void build(int x, int lx, int rx, vector<int>&a){
        if(rx-lx==1){
            if(lx < (int)(a.size()))seg[x].pb(a[lx]);
            return;
        }
        int m = (lx+rx)/2;
        build(2*x+1, lx, m, a);
        build(2*x+2, m, rx, a);
        merge(all(seg[2*x+1]), all(seg[2*x+2]), back_inserter(seg[x]));
    }

    void build(vector<int>&a){
        build(0,0,sz,a);
    }

    int sol(int x, int lx, int rx, int l, int r, int k){
        if(rx <= l || lx >= r)return 0ll;
        if(lx >= l && rx <= r)return upper_bound(all(seg[x]),k)-seg[x].begin();
        int m = (lx+rx)/2;
        return sol(2*x+1, lx, m, l, r, k) + sol(2*x+2, m, rx, l, r, k);
    }

    int sol(int l, int r, int x){
        return sol(0,0,sz,l,r,x);
    }
};
void solve()
{
    int n,k;
    cin >> n >> k;
    int mxn = 1e4+1;
    vector<mergesortree>st(mxn);
    vector<vector<int>>a;
    vector<int>xs;
    for(int i = 0;i<n;++i){
        int x,y,z;
        cin >> x >> y >> z;
        a.pb({x,y,z});
        xs.pb(x);
    }
    sort(all(a));
    sort(all(xs));
    vector<vector<int>>pos(mxn);
    for(auto x : a){
        pos[x[2]].pb(x[0]-x[1]);
    }
    for(int i = 1;i<mxn;++i){
        int sz = pos[i].size();
        st[i].init(sz);
        st[i].build(pos[i]);
    }
    for(int i = 0;i<n;++i){
        int x = a[i][0], r = a[i][1], f = a[i][2];
        int e = upper_bound(all(xs),x+r)-xs.begin()-1;
        for(int j = i;j<=i+k;++j){
            res+=st[j].sol(i+1,)
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