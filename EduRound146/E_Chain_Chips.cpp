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
    vector<pair<pair<int,int>,pair<int,int>>>seg;
    void init(int n){
        while(sz < n)sz*=2;
        seg = vector<pair<pair<int,int>,pair<int,int>>>(2*sz);
    }

    pair<pair<int,int>,pair<int,int>>def(){
        pair<pair<int,int>,pair<int,int>> c = {{0,0},{0,0}};
        return c;
    }


    pair<pair<int,int>,pair<int,int>>merge(pair<pair<int,int>,pair<int,int>>l, pair<pair<int,int>,pair<int,int>>r){
        pair<pair<int,int>,pair<int,int>>ans = def();
        ans.second.second = max({l.first.second+r.first.second, l.second.first+max(r.first.second, r.second.second), l.second.second+r.first.second});
        ans.second.first = max({l.first.second+r.first.first,l.second.first+r.second.first,l.second.second+r.first.first,l.first.first+r.second.first});
        ans.first.second = max({l.first.second+r. first.second,l.first.first+max({r.second.second,r.second.first,r.first.second})});
        ans.first.first = max({l.first.second+r.first.first,l.first.first+r.second.first});
        return ans;
    }

    void set(int x, int lx, int rx, int i, int v){
        if(rx-lx==1){
            seg[x].second.second = v;
            return;
        }
        int m = (lx+rx)/2;
        if(i < m)set(2*x+1, lx, m, i, v);
        else set(2*x+2, m, rx, i, v);
        seg[x] = merge(seg[2*x+1], seg[2*x+2]);
    }

    void set(int i, int v){
        set(0,0,sz,i,v);
    }


    pair<pair<int,int>,pair<int,int>> sol(int x, int lx, int rx, int l, int r){
        if(lx >= l && rx <= r)return seg[x];
        if(lx >= r || rx <= l)return def();
        int m = (lx+rx)/2;
        return merge(sol(2*x+1, lx, m, l, r), sol(2*x+2, m, rx, l, r));
    }

    int sol(int l, int r){
        return max({seg[0].first.first,seg[0].first.second,seg[0].second.second,seg[0].second.first});
        // vector<vector<int>>r = sol(0,0,sz,l,r);
        // return sol(0,0,sz, l, r);
    }
};
void solve()
{
    int n;
    cin >> n;
    vector<int>a(n);
    for(int i = 1;i<n;++i)cin >> a[i],a[i]*=2;
    int q;
    cin >> q;
    segtree st;
    st.init(n);
    int res = 0;
    res+=a[1];
    if(n-1!=1)res+=a[n-1];
    for(int i = 2;i<n-1;++i)st.set(i,a[i]),res+=a[i];
    while(q--){
        // you can skip vertexes with gap of atleast 2
        int i,x;
        cin >> i >> x;
        res-=(a[i]);
        if(i!=1 && i!=(n-1))st.set(i,x*2);
        res+=x*2;
        a[i] = x*2;
        
        cout << res-st.sol(1,n-1) << endl;
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