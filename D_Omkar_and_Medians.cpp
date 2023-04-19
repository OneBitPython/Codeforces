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

int off(int x){
    return x + (int)(1e9)+1;
}

struct segtree{
    int sz = 1;
    vector<int>seg,right,left;
    int node = 0;
    void init(int n){
        while(sz < n)sz*=2;
        seg.pb(0);
        right.pb(-1);
        left.pb(-1);
    }

    int get(){
        node++;
        seg.pb(0);
        left.pb(-1);
        right.pb(-1);
        return node;
    }

    void set(int x, int lx, int rx, int i, int v){
        if(rx-lx==1){
            seg[x] += v;
            return;
        }
        int m = (lx+rx)/2;
        if(left[x]==-1)left[x] = get();
        if(right[x]==-1)right[x] = get();
        if(i < m)set(left[x],lx,m,i,v);
        else set(right[x],m,rx,i,v);
        seg[x] = seg[left[x]]+seg[right[x]];
    }

    void set(int i, int v){
        set(0,0,sz,i,v);
    }

    int sol(int x, int lx, int rx, int l, int r){
        if(lx >= l && rx <= r)return seg[x];
        if(rx <= l || lx >= r)return 0ll;
        if(left[x]==-1)left[x] = get();
        if(right[x]==-1)right[x] = get();

        int m = (lx+rx)/2;
        return sol(left[x],lx,m,l,r)+sol(right[x],m,rx,l,r);
    }

    int sol(int l, int r){
        return sol(0,0,sz,l,r);
    }
};
void solve()
{
    int n;
    cin >> n;
    vector<int>a(n+1);
    for(int i = 1;i<=n;++i)cin >> a[i];
    segtree st;
    st.init(3e9);
    for(int i = 2;i<=n;++i){
        int x = off(a[i]),y=off(a[i-1]);
        if(x > y)swap(x,y);
        if(st.sol(x+1,y)){
            cout << "NO" << endl;
            return;
        }
        st.set(x,1);
        st.set(y,1);
    }
    cout<< "YES" << endl;
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
    cin >> T ;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}