#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define all(c) c.begin(), c.end()
#define endl "\n"

const double PI=3.14159265358979323846264338327950288419716939937510582097494459230;


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

typedef long long int ll;
ll l, r;
ll segtree[400001];
ll a[100001];
ll b[100001];
void build(ll node, ll b1, ll e)

{
    if (b1 == e)
    {
        segtree[node] = b[b1];
        // cout << b[b1] << "\n";
    }
    else
    {
        ll mid = (b1 + e) / 2;

        build(2 * node, b1, mid);
        build(2 * node + 1, mid + 1, e);

        l = segtree[2 * node];
        r = segtree[2 * node + 1];

        if (a[l] > a[r])
        {
            segtree[node] = l;
        }
        else if (a[l] < a[r])
        {

            segtree[node] = r;
        }
        else if (a[l] == a[r])
        {

            segtree[node] = l;
        }
        else
        {
        }
    }
}
ll sum1(ll node, ll b1, ll e, ll L, ll R)
{

    if (b1 > R || e < L)
    {
        return -1;
    }

    if (b1 >= L && e <= R)
    {
        return segtree[node];
    }

    ll mid = (b1 + e) / 2;

    ll left = sum1(2 * node, b1, mid, L, R);
    ll right = sum1(2 * node + 1, mid + 1, e, L, R);
    if (left == -1)
    {
        return right;
    }
    else if (right == -1)
    {
        return left;
    }
    else
    {

        if (a[left] < a[right])
        {
            return right;
        }
        else
        {
            return left;
        }
    }
}

struct sg{
    int sz = 1;
    vector<int>sums;
    void init(int n){
        while(sz < n)sz*=2;
        sums.resize(sz*2);
    }
 
    void set(int x, int lx, int rx, int i, int v){
        if(rx - lx == 1){
            sums[x] = v;
            return;
        }
        int m = (lx+rx)/2;
        if(i < m)set(2*x+1, lx, m, i, v);
        else set(2*x+2, m, rx, i, v);
        sums[x] = min(sums[2*x+1], sums[2*x+2]);
    }
 
    void set(int i, int v){
        set(0, 0, sz, i, v);
    }
 
    int mx(int x, int lx, int rx, int l, int r){
        if(lx>=r || rx<=l)return 0ll;
        if(lx>=l && rx<=r)return sums[x];
        int m = (lx+rx)/2;
        return min(mx(2*x+1, lx, m, l, r),mx(2*x+2, m, rx, l, r));
    }
 
    int mx(int l, int r){
        return mx(0, 0, sz, l, r);
    }
};

void solve()
{
    int n,k;
    cin >> n >> k;
    vector<int>c(n+1);
    for(int i = 1;i<=n;++i)cin >> c[i];
    for(int  i = 0;i<n;++i)b[i] = i;
    for(int i = 1;i<n;++i)a[i] = min(c[i], c[i+1]);
    for(int i = 0;i<n;++i)cout << a[i] << ' ';
    cout << endl;
    build(1,1,n);
    cout << sum1(1, 1, n, 1,2) << endl;
    // a[4] = 1e9;
    // build(1,1,n);
    // cout << sum1(1, 1, n, 1, 5);
}   

int32_t main()  
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    

    int T=1;
    cin >> T;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}