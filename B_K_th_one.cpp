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
            seg[x]= v;
            return;
        }
        int m = (lx+rx)/2;
        if(i < m)set(2*x+1, lx, m, i,v );
        else set(2*x+2, m, rx, i, v);
        seg[x] = seg[2*x+1]+seg[2*x+2];
    }

    void set(int i, int v){
        set(0,0,sz,i,v);
    }

    int sol(int x, int lx, int rx, int k){
        if(rx-lx==1)return lx;
        int m = (lx+rx)/2;
        if(seg[2*x+1]>=k)return sol(2*x+1, lx, m, k);
        else return sol(2*x+2,m,rx,k-seg[2*x+1]);
        return x;
    }

    int sol(int k){
        return sol(0,0,sz,k);
    }
};

void solve()
{
    int n,k;
    cin >> n >>  k;
    vector<int>a(n+1);
    segtree st;
    st.init(n+1);
    for(int i = 1;i<=n;++i){
        cin >> a[i];
        st.set(i,a[i]);
    }
    while(k--){
        int t;
        cin >> t;
        if(t==1){
            int i;
            cin >> i;
            i++;
            a[i] = 1-a[i];
            st.set(i,a[i]);
        }else{
            int k;
            cin >> k;
            k++;
            cout << st.sol(k)-1 << endl;
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