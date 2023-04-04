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

struct node{
    int freq[41];
    int inv = 0;
    node(){
        for(int i = 0;i<=40;++i)freq[i]=0;
    }
};

struct segtree{
    int sz = 1;
    vector<node>seg;
    void init(int n){
        while( sz < n)sz*=2;
        seg.resize(sz*2);
    }

    node emp(){
        node n;
        return n;
    }

    node merge(node a, node b){
        node res;
        res.inv = a.inv + b.inv;
        for(int i = 0;i<=40;++i)res.freq[i] = a.freq[i]+b.freq[i];
        for(int i = 1;i<=40;++i){
            for(int j = 1;j<i;++j){
                res.inv += a.freq[i]*b.freq[j];
            }
        }
        return res;
    }

    void set(int x, int lx, int rx, int i, node v){
        if(rx-lx==1){
            seg[x] = v;
            return;
        }
        int m = (lx+rx)/2;
        if(i < m)set(2*x+1, lx, m, i, v);
        else set(2*x+2, m, rx, i, v);
        seg[x] = merge(seg[2*x+1], seg[2*x+2]);
    }

    void set(int i, int x){
        node v;
        v.freq[x]++;
        set(0,0,sz,i,v);
    }

    node sol(int x, int lx, int rx, int l, int r){
        if(lx >= l && rx <= r)return seg[x];
        if(rx <= l || lx >= r)return emp();
        int m = (lx+rx)/2;
        return merge(sol(2*x+1, lx, m, l, r), sol(2*x+2, m, rx, l,r ));
    }

    node sol(int l, int r){
        return sol(0,0,sz,l,r);
    }
};

void solve()
{
    int n,k;
    cin >> n >> k;
    vector<int>a(n+1);
    for(int i = 1;i<=n;++i)cin >> a[i];
    segtree st;
    st.init(n+1);
    for(int i = 1;i<=n;++i)st.set(i,a[i]);
    for(int i =1;i<=k;++i){
        int t;
        cin >> t;
        if(t==1){
            int x,y;
            cin >> x >> y;
            cout << st.sol(x,y+1).inv << endl;
        }else{
            int i,x;
            cin >> i >> x;
            st.set(i,x);
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