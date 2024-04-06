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
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.left); cerr << ','; __print(x.second); cerr << '}';}
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
        if(i <m)set(2*x+1,lx,m,i,v);
        else set(2*x+2,m,rx,i,v);
        seg[x] = max(seg[2*x+1], seg[2*x+2]);
    }

    void set(int i, int v){
        set(0,0,sz,i,v);
    }


    int left(int x, int lx, int rx, int l, int r){
        if(rx <= l || lx >= r)return 0;
        if(seg[x]==0)return 0;
        if(rx-lx==1)return lx;

        int m = (lx+rx)/2;
        int res = left(2*x+2,m,rx,l,r);
        if(res==0)res = left(2*x+1,lx,m,l,r);
        return res;
    }
    int left(int l, int r){
        return left(0,0,sz,l,r);
    }
    int right(int x, int lx, int rx, int l, int r){
        if(rx <= l || lx >= r)return 0;
        if(seg[x]==0)return 0;
        if(rx-lx==1)return lx;
        int m = (lx+rx)/2;

        int res = right(2*x+1,lx,m,l,r);
        if(res==0)res = right(2*x+2,m,rx,l,r);
        return res;
    }
    int right(int l, int r){
        return right(0,0,sz,l,r);
    }
};
void solve()
{
    int n;
    cin >> n;
    vector<int>a(n+2), d(n+2);
    for(int i = 1;i<=n;++i)cin >> a[i];
    for(int i = 1;i<=n;++i)cin >> d[i];
    int c = 0;
    set<int>active;
    segtree st;
    st.init(n+2);
    for(int i = 1;i<=n;++i){
        if(a[i+1] + a[i-1] > d[i])c++;
        else active.insert(i),st.set(i,1);
    }
    cout << c << ' ';
    for(int z = 2;z<=n;++z){
        c = 0;
        vector<int>ac;
        set<int>acc;
        active.erase(0);
        for(int j : active){
            if(j==0)continue;
            if(a[st.left(1,j)] + a[st.right(j+1,n+1)] > d[j])ac.pb(j);
        }
        for(int j : ac)st.set(j,0);
        for(int j : ac){
            acc.insert(st.left(1,j));
            acc.insert(st.right(j+1,n+1));
        }
        active = acc;

        cout << ac.size()<< ' ';
    }
    cout << endl;
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