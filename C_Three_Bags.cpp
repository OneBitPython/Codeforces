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

int n,m,k;
vector<int>a,b,c;
int f(vector<int>&a, vector<int>&b, vector<int>&c){
    // you can have sum(b)+sum(c)-sum(a)
    int res = accumulate(all(b),0ll)+accumulate(all(c),0ll)-accumulate(all(a),0ll);
    return res;
}
int g(vector<int>&a, vector<int>&b, vector<int>&c){
    // you can have sum(a,b,c)-2*(min(a)+min(b))
    int res = accumulate(all(b),0ll)+accumulate(all(a),0ll)+accumulate(all(c),0ll);
    res-=2*(*min_element(a.begin()+1, a.end())+*min_element(b.begin()+1, b.end()));

    return res;
}
void solve()
{
    cin >> n >> m >> k;
    a.resize(n+1);
    b.resize(m+1);
    c.resize(k+1);
    for(int i = 1;i<=n;++i)cin >> a[i];
    for(int i = 1;i<=m;++i)cin >> b[i];
    for(int i = 1;i<=k;++i)cin >> c[i];
    int res = max({f(a,b,c),f(b,a,c),f(c,b,a)});
    res = max({res,g(a,b,c),g(a,c,b),g(c,b,a)});
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
    // cin >> T;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}