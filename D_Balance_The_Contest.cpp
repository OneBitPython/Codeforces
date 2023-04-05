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




void solve()
{
    int n,x;
    cin >> n >> x;
    vector<int>a(n+1);
    for(int i = 1;i<=n;++i)cin >> a[i];
    int l = 0, r = 1e18;
    int res = 0;
    vector<int>ans;
    while(l <= r){
        int m = (l+r)/2;
        // try setting first value to a[i]+m, second to a[i]+m+x, third to a[i]+m+2x and so on
        int s = a[1]+m;
        bool ok = 1;
        vector<int>b = {0,a[1]+m};
        for(int i = 2;i<=n;++i){
            s+=x;
            if(a[i] < s){
                int add = min(s-a[i],m);
                b.pb(a[i]+add);
            }else{
                int sub = min(a[i]-s,m);
                b.pb(a[i]-sub);
            }
            s = b.back();
            if(b[i]-b[i-1]>x)ok =0;
        }
        if(ok){
            res = m;
            ans = b;
            r = m-1;
        }else{
            l = m+1;
        }
    }
    cout << res << endl;
    for(int i =1;i<=n;++i)cout << ans[i] << ' ';
    cout<< endl;
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