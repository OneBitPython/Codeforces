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
    vector<int>seg;
    void init(int n){
        while(sz < n)sz*=2;
        seg.resize(sz*2);
    }
    
    void set(int x, int lx, int rx, int i, int v){
        if(rx-lx==1){
            seg[x]+=v;
            return;
        }
        int m = (lx+rx)/2;
        if(i < m)set(2*x+1,lx,m,i,v);
        else set(2*x+2,m,rx,i,v);
        seg[x] = seg[2*x+1]+seg[2*x+2];
    }

    void set(int i, int v){
        set(0,0,sz,i,v);
    }

    int sol(int x, int lx, int rx, int l, int r){
        if(lx >= r || rx <= l)return 0ll;
        if(lx >= l && rx <= r)return seg[x];
        int m = (lx+rx)/2;
        return sol(2*x+1, lx, m, l, r) +sol(2*x+2, m, rx, l, r);
    }

    int sol(int l,int r){
        return sol(0,0,sz,l,r);
    }
};
void solve()
{
    int n,m,k;
    cin >> n>> m >> k;
    vector<int>a(n);
    for(int &u : a)cin >> u;
    sort(all(a));
    int tot = 0;
    int mx = 1e6+1;
    segtree st;
    st.init(mx);
    int res = 0;
    for(auto x : a)st.set(x,1);
    for(int i = n-1;i>=0;--i){
        int l = a[i], r = a[i]+m;
        int cnt = st.sol(l,r);
        if(cnt >= k){
            int remove = cnt-k+1;
            for(int j = i;j<n;++j){
                if(remove == 0)break;
                remove--;
                st.set(a[j],-1);
                res++;
            }
        }
    }
    cout << res;
}   

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    

    int T=1;
    // cin >> T;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}