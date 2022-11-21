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


bool pos(int x, vector<int>&a, int d, int c){
    // choose the best x+ 1 values
    int res = 0;
    vector<int>b;
    int n = a.size();
    for(int i = 0;i<min(n,x+1);++i)b.pb(a[i]);
    while(b.size() <= x)b.pb(0);
    for(int i = 0;i<d;++i){
        int val = i%(x+1);
        res+=b[val];
    }
    return res>=c;
}
void solve()
{
    int n,c,d;
    cin >> n >> c >> d;
    vector<int>a(n);
    for(int &u : a)cin >> u;
    sort(all(a));
    reverse(all(a));
    int v = 0;
    for(int i = 0;i<min(d,n);++i)v+=a[i];
    if(v >= c){
        cout << "Infinity" << endl;
        return;
    }
    if(a[0] * d < c){
        cout << "Impossible" << endl;
        return;
    }
    int l = 0, r = d+5;
    while(l+1 < r){
        int m = (l+r)/2;
        if(pos(m, a, d,c))l = m;
        else r = m;
    }
    if(pos(l,a,d,c))cout << l << endl;
    else cout << "Impossible" << endl;
}   

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif

    int T=1;
    cin >> T;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}