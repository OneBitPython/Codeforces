#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
  
#define ordered_set tree<pair<int, int>, null_type,less<pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update>

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
    // range add along with range maximum and index of maximum
    int sz = 1;
    vector<pair<int,int>>seg;
    void init(int n){
        while(sz < n )sz*=2;
        seg.resize(sz*2);
    }



    pair<int,int> merge(pair<int,int>a, pair<int,int>b){
        if(a.first < b.first)return a;
        return b;
    }

    void set(int x, int lx, int rx, int i, pair<int,int> v){
        if(rx-lx == 1){
            seg[x] = v;
            return;
        }
        int m = (lx+rx)/2;

        if(i < m)set(2*x+1, lx, m, i, v);
        else set(2*x+2, m, rx, i, v);
        seg[x] = merge(seg[2*x+1], seg[2*x+2]);
    }

    void set(int i, pair<int,int> v){
        set(0,0,sz,i,v);
    }

    pair<int,int> sol(int x, int lx, int rx, int l, int r){
        if(lx >= l && rx <= r)return seg[x];
        if(lx >= r || rx <= l)return {1e18,0};
        int m = (lx+rx)/2;
        return merge(sol(2*x+1, lx, m, l, r), sol(2*x+2, m, rx, l, r));
    }

    pair<int,int> sol(int l, int r){
        return sol(0,0,sz,l,r);
    }

};  

void solve()
{
    int n,k;
    cin >> n >> k;
    segtree st;
    st.init(n+1);
    vector<pair<int,int>>a(n+1);
    for(int i = 0;i<=n;++i)a[i] = {1e10,i},st.set(i,a[i]);

    while(k--){
        int t;
        cin >> t;
        if(t==1){
            int i,h;
            cin >> i >> h;
            i++;
            st.set(i,{h,i});
            a[i] = {h,i};
        }else{
            int l,r,p;
            cin >> l >> r >> p;
            l++;
            r++;
            int res = 0;
            while(1){
                pair<int,int>v = st.sol(l,r);
                if(v.first > p)break;
                res++;
                st.set(v.second,{1e10,v.second});
            }
            cout << res << endl;
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