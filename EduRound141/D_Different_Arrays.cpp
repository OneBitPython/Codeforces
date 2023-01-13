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

int mod = 998244353 ;
int ma(int a, int b){
    return ((a%mod)*(b%mod))%mod;
}
int ms(int a, int b){
    return ((((a%mod)-(b%mod))%mod) + mod )% mod;
}
long long p(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a,res%=mod;
        a = a * a;
        a%=mod;
        b >>= 1;
    }
    return res%mod;
}

int mxn = 300;
int adj(int x){
    return x+mxn*mxn;
}
void solve()
{
    int n;
    cin >> n;
    vector<int>a(n+1);
    for(int i =1;i<=n;++i)cin >> a[i];
    vector<vector<int>>dp(2, vector<int>(5e5));
    dp[0][adj(a[2])] = 1;
    dbg("ok");
    for(int i = 3;i<=n;++i){
        int prev = (i-1)%2;
        int curr = i%2;

        for(int j = -(mxn*mxn);j<=mxn*mxn;++j){
            dp[curr][adj(j)] = 0;
        }
        for(int j = -(mxn*mxn);j<=mxn*mxn;++j){
            if(!dp[prev][adj(j)])continue;
            dp[curr][adj(a[i]-j)]+=dp[prev][adj(j)];
            dp[curr][adj(a[i]-j)]%=mod;
            if(j!=0){
                dp[curr][adj(a[i]+j)]+=dp[prev][adj(j)];
                dp[curr][adj(a[i]+j)]%=mod;
            }
        }
    }
    int res = 0;
    for(auto x : dp[n%2])res+=x,res%=mod;
    cout << res;
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