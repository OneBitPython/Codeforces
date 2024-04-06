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


int n;
const int inf = 1e18;
vector<int>a,pref;
struct segtree{
    int sz = 1;
    vector<int>seg;
    void init(int n){
        while(sz < n)sz*=2;
        seg.resize(sz*2,inf);
    }

    void set(int x, int lx, int rx, int i, int v){
        if(rx-lx==1){
            seg[x] = min(seg[x],v);
            return;
        }
        int m = (lx+rx)/2;
        if(i < m)set(2*x+1,lx,m,i,v);
        else set(2*x+2,m,rx,i,v);
        seg[x] = min(seg[2*x+1], seg[2*x+2]);
    }

    void set(int i, int v){
        set(0,0,sz,i,v);
    }

    int sol(int x, int lx, int rx, int l, int r){
        if(lx>= l && rx <= r)return seg[x];
        if(rx <= l || lx >= r)return inf;
        int m= (lx+rx)/2;
        return min(sol(2*x+1,lx,m,l,r),sol(2*x+2,m,rx,l,r));
    }

    int sol(int l, int r){
        return sol(0,0,sz,l,r);
    }
};

bool pos(int x){
    vector<int>stops = {0};
    int sum = 0;
    int other = 0;

    for(int i = 1;i<=n;++i){
        if(a[i] > x)return 0;

        if(sum + a[i] <= x)sum+=a[i];
        else{
            stops.pb(i);
            other+=a[i];
            sum = 0;
        }
    }
    if(other <= x)return 1;
    int m = (int)stops.size() - 1;
    segtree st;
    st.init(n+3);   
    st.set(n+1,0);
    st.set(n,a[n]);
    for(int i = (n-1);i>=0;--i){
        // pref[j] < = pref[i] + x
        int k = upper_bound(all(pref),pref[i]+x) - pref.begin() - 1;
        st.set(i,st.sol(i+1,k+2)+a[i]);
    }

    for(int i = stops[1];i>=0;--i){
        if(st.sol(i,i+1) <= x)return 1;
    }
    return 0;
}

void solve()
{
    cin >> n;
    a = vector<int>(n+1);
    pref = vector<int>(n+1);
    for(int i = 1;i<=n;++i)cin >> a[i],pref[i] = a[i] + pref[i-1];

    int l = 1, r = inf, res = inf;
    while(l <= r){
        int m = (l+r)/2;
        if(pos(m)) res= m, r = m-1;
        else l = m+1;
    }
    cout << res << endl;
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