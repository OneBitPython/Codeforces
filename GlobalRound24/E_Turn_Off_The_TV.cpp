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
    vector<int>seg,lazy;
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
        if(i < m)set(2*x+1, lx, m, i, v);
        else set(2*x+2, m, rx, i, v);
        seg[x] = min(seg[2*x+1], seg[2*x+2]);
    }

    void set(int i, int v){
        set(0,0,sz,i,v);
    }

    void rangeupdate(int x, int lx, int rx, int l, int r, int y){

        if(lazy[x]){
            seg[x] += lazy[x];
            if(rx - lx > 1){
                lazy[2*x+1]+=lazy[x];
                lazy[2*x+2]+=lazy[x];
            }
            lazy[x] = 0;
        }

        if(lx >= r || rx <= l)return;
        if(lx >= l && rx <= r){
            seg[x]+=y;
            if(rx-lx > 1){
                // not leaf
                lazy[2*x+1] += y;
                lazy[2*x+2] += y;
            }
            return;
        }
        int m = (lx+rx)/2;
        rangeupdate(2*x+1, lx, m, l, r, y);
        rangeupdate(2*x+2, m, rx, l, r, y);
        seg[x] = min(seg[2*x+1], seg[2*x+2]);
    }

    void rangeupdate(int l, int r, int x){
        rangeupdate(0,0,sz,l,r,x);
    }

    int sol(int x, int lx, int rx, int l, int r){
        if(lazy[x]){
            seg[x] += lazy[x];
            if(rx - lx > 1){
                lazy[2*x+1]+=lazy[x];
                lazy[2*x+2]+=lazy[x];
            }
            lazy[x] = 0;
        }

        if(lx >= r || rx <= l)return 1e18;
        if(lx >= l && rx <= r)return seg[x];
        int m = (lx+rx)/2;
        return min(sol(2*x+1, lx, m, l, r), sol(2*x+2, m, rx, l, r));
    }

    int sol(int l, int r){
        return sol(0,0,sz,l,r);
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<pair<int,int>>a;
    set<int>s;
    for(int i = 0;i<n;++i){
        int u,v;
        cin >> u >> v;
        a.pb({u,v});
        s.insert(u);
        s.insert(v);
    }
    map<int,int>coord;
    // compres ranges
    int g = 0;
    int prev = 0;
    for(auto x : s){
        if(x-prev > 1)g+=2;
        else g++;
        coord[x] = g;
        prev = x;
    }
    vector<pair<int,int>>b;
    int mx = 0;
    for(auto x : a){
        b.pb({coord[x.first], coord[x.second]});
        mx = max({mx, b.back().first, b.back().second});
    }
    segtree st;
    st.init(mx+1);
    // range update l,r updates [l,r-1] (inclusive)
    for(auto x : b){
        st.rangeupdate(x.first, x.second+1, 1);
    }
    int i = 1;
    for(auto x : b){
        int mn = st.sol(x.first, x.second+1);
        if(mn > 1){
            cout << i << endl;
            return;
        }
        i++;
    }
    cout << -1 << endl;
}   

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif

    int T=1;
    // cin >> T;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}