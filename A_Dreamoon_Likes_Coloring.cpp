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

    void rangeupdate(int x, int lx, int rx, int l, int r){
        if(lazy[x]){
            seg[x]=(rx-lx);
            if(rx-lx > 1){
                lazy[2*x+1] = 1;
                lazy[2*x+2] = 1;
            }
            lazy[x] = 0;
        }
        if(rx <= l || lx >= r)return;
        if(lx >= l && rx <= r){
            seg[x]=(rx-lx);
            if(rx-lx > 1){
                lazy[2*x+1] = 1;
                lazy[2*x+2] = 1;
            }
            return;
        }
        int m = (lx+rx)/2;
        rangeupdate(2*x+1,lx,m,l,r);
        rangeupdate(2*x+2, m, rx, l,r );
        seg[x] = seg[2*x+1]+seg[2*x+2];
    }

    void rangeupdate(int l, int r){
        rangeupdate(0,0,sz,l,r);
    }

    int sol(int x, int lx, int rx, int l, int r){
        if(lazy[x]){
            seg[x]=(rx-lx);
            if(rx-lx > 1){
                lazy[2*x+1] = 1;
                lazy[2*x+2] = 1;
            }
            lazy[x] = 0;
        }
        if(lx >= l && rx <= r)return seg[x];
        if(rx <= l || lx >= r)return 0ll;
        int m = (lx+rx)/2;
        return sol(2*x+1, lx, m, l, r) + sol(2*x+2, m, rx, l, r);
    }

    int sol(int l, int r){
        return sol(0,0,sz,l,r);
    }
};
void solve()
{
    int n,m;
    cin >> n >> m;
    int sum = 0;
    vector<int>a(m);
    for(int &u : a){
        cin >> u;
        sum+=u;
    }
    if(sum < n){
        cout << -1 << endl;
        return;
    }
    int overlaps = sum-n;
    // if(overlaps >= n){
    //     cout << -1 << endl;
    //     return;
    // }
    segtree st;
    st.init(n+1);
    vector<int>res(m);
    int l = 1;
    for(int i = 0;i<m;++i){
        while(l <= n){
            int e = l+a[i]-1;
            if(e>n){
                cout << -1 << endl;
                return;
            }
            int o = st.sol(l,e+1);
            if(overlaps >= o){
                st.rangeupdate(l,e+1);
                overlaps -= o;
                break;
            }
            l++;
        }
        res[i] = l;
        l++;
    }
    
    for(auto x : res)cout << x << ' ';
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