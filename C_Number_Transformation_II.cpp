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
    vector<int>seg;
    int sz = 1;
    void init(int n){
        while(sz < n)sz*=2;
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
        seg[x] = min(seg[2*x+1], seg[2*x+2]);
    }

    void set(int i, int v){
        set(0,0,sz,i,v);
    }

    int sol(int x, int lx, int rx, int l, int r){
        if(rx <= l || lx >= r)return 1e18;
        if(lx >= l && rx <= r)return seg[x];
        int m = (lx+rx)/2;
        return min(sol(2*x+1, lx, m, l, r), sol(2*x+2, m, rx, l, r));
    }

    int sol(int l, int r){
        return sol(0,0,sz,l,r);
    }
};  
const int mxn = 1e6+1;
int mx[mxn];
void solve()
{
    int n;
    cin >> n;
    vector<int>c(n);
    for(int &u : c)cin >> u;
    int a,b;
    cin >> a >> b;
    vector<int>mx(a-b+5,2);
    sort(all(c));
    for(auto x : c){
        int start = b-(b%x);
        for(int i = start;i<=a;i+=x){
            if(i>=b & i <= a)mx[i-b] = x;
        }
    }
    a-=b;
    b=0;
    segtree st;
    st.init(a+1);
    for(int i = a-1;i>=0;--i){
        int end = min(a,i+mx[i]-1);
        int x = st.sol(i+1,end+1)+1;
        st.set(i,x);
    }
    cout << st.sol(0,1);
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