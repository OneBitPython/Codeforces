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
    vector<pair<int,int>>seg;
    void init(int n){
        while(sz < n)sz*=2;
        seg.resize(sz*2);
    }
 
    pair<int,int>merge(pair<int,int>a, pair<int,int>b){
        if(a.first > b.first)return a;
        else return b;
    }

    void clear(){
        seg.clear();
        seg.resize(sz*2);
    }

    void set(int x, int lx, int rx, int i, pair<int,int> v){
        if(rx-lx==1){
            seg[x] = v;
            return;
        }
        int m = (lx+rx)/2;
        if(i < m)set(2*x+1,lx,m,i,v);
        else set(2*x+2, m, rx, i, v);
        seg[x] = merge(seg[2*x+1], seg[2*x+2]);
    }

    void set(int i, pair<int,int> v){
        set(0,0,sz,i,v);
    }

    pair<int,int> sol(int x, int lx, int rx, int l, int r){
        if(rx <= l || lx >= r)return {-1e18,-1e18};
        if(lx >= l && rx <= r)return seg[x];
        int m = (lx+rx)/2;
        return merge(sol(2*x+1,lx,m,l,r),sol(2*x+2,m,rx,l,r));
    }

    pair<int,int> sol(int l, int r){
        return sol(0,0,sz,l,r);
    }
 
};
void solve()
{
    int n;
    cin >> n;
    vector<vector<int>>a;
    for(int i = 0;i<n;++i){
        int l,r,c;
        cin >> l >> r >> c;
        a.pb({l,r,c,i});
    }
    sort(all(a));
    vector<int>dist(n+1, 1e18),mx(n+1,-1e18);
    segtree st;
    st.init(n+2);
    for(int i = 0;i<=n;++i)st.set(i,{-1e18,i});
    for(int i = 1;i<n;++i){
        mx[a[i-1][2]] = max(mx[a[i-1][2]], a[i-1][1]);
        st.set(a[i-1][2],{mx[a[i-1][2]], a[i-1][2]});
        pair<int,int>res = st.sol(1,n+1);
        int best = res.first;
        if(res.second==a[i][2]){
            st.set(a[i][2], {-1e18,a[i][2]});
            res = st.sol(1,n+1);
            best = res.first;
            st.set(a[i][2], {mx[a[i][2]], a[i][2]});
        }
        dist[a[i][3]] = min(dist[a[i][3]], max(0ll,a[i][0]-best));
    }
    st.clear();
    mx = vector<int>(n+1,-1e18);
    for(int i = 0;i<=n;++i)st.set(i,{-1e18,i});
    for(int i = n-2;i>=0;--i){
        mx[a[i+1][2]] = max(mx[a[i+1][2]], -a[i+1][0]);
        st.set(a[i+1][2],{mx[a[i+1][2]], a[i+1][2]});
        pair<int,int>res = st.sol(0,n+1);
        int best = res.first;
        if(res.second==a[i][2]){
            st.set(a[i][2], {-1e18,a[i][2]});
            res = st.sol(0,n+1);
            best = res.first;
            st.set(a[i][2], {mx[a[i][2]], a[i][2]});
        }
        dist[a[i][3]] = min(dist[a[i][3]], max(0ll,abs(best)-a[i][1]));
    }
    for(int i = 0;i<n;++i)cout << dist[i] << ' ';
    cout << endl;
}   

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    

    int T=1;
    cin >> T;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}