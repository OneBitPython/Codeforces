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
 
 
struct segtree{
    int sz = 1;
    vector<int>seg;
    vector<queue<pair<int,int>>>lazy;
    // lazy[x].first stores order of operations
    // lazy[x].second stores the value to add/ change in this type of operation
    // operation 0 is increase the segment by x
    // operation 1 is set the segment to x
    void init(int n){
        while(sz < n)sz*=2;
        seg.resize(sz*2);
        lazy.resize(sz*2);
    }


    void prop(int x, int lx, int rx){
        while(!lazy[x].empty()){
            int y = lazy[x].front().first;
            int z = lazy[x].front().second;
            if(y==0)seg[x]+=(rx-lx)*z;
            else seg[x] = (rx-lx)*z;
            if(rx-lx > 1){
                lazy[2*x+1].push({y, z});
                lazy[2*x+2].push({y, z});
 
            }
            lazy[x].pop();
        }
    }
 
    void upd1(int x, int lx, int rx, int l, int r, int y){
        prop(x,lx,rx);
        if(lx >= l && rx <= r){
            seg[x] += (rx-lx)*y;
            if(rx-lx > 1){
                lazy[2*x+1].push({0, y});
                lazy[2*x+2].push({0,y});
            }
            return;
        }
        if(rx <= l || lx >= r)return;
        int m = (lx+rx)/2;
        upd1(2*x+1, lx, m, l, r,y);
        upd1(2*x+2, m, rx, l, r, y);
        
        seg[x] = (seg[2*x+1] + seg[2*x+2]);
    }
 
    void upd1(int l, int r, int y){
        upd1(0,0,sz,l,r,y);
    }
 
    void upd2(int x, int lx, int rx, int l, int r, int y){
        prop(x,lx,rx);
        if(lx >= l && rx <= r){
            seg[x] = (rx-lx)*y;
            if(rx-lx > 1){
                lazy[2*x+1].push({1, y});
                lazy[2*x+2].push({1, y});
            }
            return;
        }
        if(rx <= l || lx >= r)return;
        int m = (lx+rx)/2;
        upd2(2*x+1, lx, m, l, r,y);
        upd2(2*x+2, m, rx, l, r, y);
        seg[x] = (seg[2*x+1] + seg[2*x+2]);
    }
 
    void upd2(int l, int r, int y){
        upd2(0,0,sz,l,r,y);
    }
 
    int sol(int x, int lx, int rx, int l, int r){
        prop(x,lx,rx);
        if(rx <= l || lx >= r)return 0ll;
        if(rx <= r && lx >= l)return seg[x];
        int m = (lx+rx)/2;
        return sol(2*x+1, lx, m, l, r) + sol(2*x+2, m, rx, l, r);
    }
 
    int sol(int l, int r){
        return sol(0,0,sz,l,r);
    }
 
    void build(int x, int lx, int rx, vector<int>&a){
        if(rx-lx==1){
            if(lx < (int)(a.size()))seg[x] = a[lx];
            return;
        }
        int m = (lx+rx)/2;
        build(2*x+1,lx, m, a);
        build(2*x+2,  m, rx, a);
        seg[x] = seg[2*x+1]+seg[2*x+2];
    }
 
    void build(vector<int>&a){
        build(0,0,sz,a);
    }
};
void solve()
{
    int n,q;
    cin >> n >> q;
    segtree st;
    vector<int>a(n);
    for(int &u : a)cin >> u;
    st.init(n);
    st.build(a);
    while(q--){
        int t;
        cin >> t;
        if(t==1){
            int l,r,x;
            cin >> l >> r >> x;
            st.upd1(l-1,r,x);
        }else if(t==2){
            int l, r, x;
            cin >> l >> r >> x;
            st.upd2(l-1, r, x);
        }else{
            int l,r;
            cin >> l >> r;
            cout << st.sol(l-1, r) << endl;
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
