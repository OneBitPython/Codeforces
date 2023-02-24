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


unsigned long long square(unsigned long long a){
    return (unsigned long long)(a*a);
}
unsigned long long res = 9e18;
void best(vector<int>&a, vector<int>&b, vector<int>&c){
    int t = a.size()-1, r = b.size()-1, q = c.size()-1;
    for(int i = 1;i<=t;++i){
        int j = upper_bound(all(b),a[i])-b.begin()-1,k = upper_bound(all(b), a[i])-b.begin();
        int l = upper_bound(all(c),a[i])-c.begin()-1,m = upper_bound(all(c), a[i])-c.begin();
        vector<int>g,h;
        if(j <= r &&j>0)g.pb(b[j]);
        if(k <= r&&k>0)g.pb(b[k]);
        if(l <= q&&l>0)h.pb(c[l]);
        if(m <= q&&m>0)h.pb(c[m]);
        for(auto x : g){
            for(auto y : h){
                res = min(res, square(a[i]-x)+square(x-y)+square(y-a[i]));
            }
        }

    }

}
void solve()
{
    int n,m,k;
    cin >> n >> m >> k;
    vector<int>a(n+1), b(m+1), c(k+1);
    for(int i = 1;i<=n;++i)cin >> a[i];
    for(int i = 1;i<=m;++i)cin >> b[i];
    for(int i = 1;i<=k;++i)cin >> c[i];
    sort(all(a));
    sort(all(b));
    sort(all(c));
    res = 9e18;
    best(a,b,c);
    best(b,a,c);
    best(c,a,b);
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