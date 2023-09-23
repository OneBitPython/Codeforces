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

struct segtree{
    int sz = 1;
    vector<int>seg;
    void init(int n){
        while(sz < n)sz*=2;
        seg.resize(sz*2);
    }

    void set(int x, int lx, int rx, int i, int v){
        if(rx-lx==1){
            seg[x] += v;
            return;
        }
        int m = (lx+rx)/2;
        if(i < m)set(2*x+1,lx,m,i,v);
        else set(2*x+2,m,rx,i,v);
        seg[x] = min(seg[2*x+1],seg[2*x+2]);
    }

    void set(int i, int v){
        set(0,0,sz,i,v);
    }

    int sol(int x, int lx, int rx, int l, int v){
        if(rx <= l || seg[x] >= v)return -1;
        if(rx-lx == 1){
            if(seg[x] < v)return lx;
            return -1;
        }
        int m = (lx+rx)/2;
        int res = sol(2*x+1,lx,m,l,v);
        if(res==-1)res = sol(2*x+2,m,rx,l,v);
        return res;
    }

    int sol(int l, int v){
        // first value >= l that has value < v
        int x = sol(0,0,sz,l,v);
        if(x==-1)x = n+1;
        return x;
    }
};
int give(vector<vector<int>>&up){
    int x = 1;
    int res = 0;
    for(int j = 20;j>=0;--j){
        if(up[x][j] <= n){
            x = up[x][j],res+=(1ll<<j);
        }
    }
    return res+1;
}
int bef(vector<vector<int>>&up, int bound){
    int x = 1;
    int res = 0;
    for(int j = 20;j>=0;--j){
        if(up[x][j] < bound){
            x = up[x][j],res+=(1ll<<j);
        }
    }
    return x;
}
void upd(vector<vector<int>>&up, int i, int v){
    if(v==-1)v = n+1;
    up[i][0] = v;
    for(int j = 1;j<=20;++j)up[i][j] = up[up[i][j-1]][j-1];
}
void solve()
{
    int q;cin >> n >> q;

    vector<int>a(n+1);
    segtree st;st.init(n+1);
    for(int i= 1;i<=n;++i)cin >> a[i],st.set(i,a[i]);
    set<int>c;
    int x = 1;
    while(x<= n){
        c.insert(x);
        x = st.sol(x,a[x]);
    }
    while(q--){
        int k,d;
        cin >> k >> d;
        // a[k]-=d;
        // st.set(k,-d);
        int v = *(--c.upper_bound(k));
        if(a[k]-d < a[v])c.insert(k);
        int x = v;
        while(st.sol(x,a[x]) <= n){
            int y = st.sol(x,a[x]);
            if(a[y] < (a[k]-d))break;
            c.erase(y);
            x=y;
        }
        cout << c.size() << ' ';
        a[k]-=d;
        st.set(k,-d);
    }cout << endl;
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