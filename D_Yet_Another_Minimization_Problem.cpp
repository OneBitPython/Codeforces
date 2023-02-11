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


int mod = 1e9+7;
int ma(int a,  int b){
    return ((a%mod)+(b%mod))%mod;
}
int mm(int a,  int b){
    return ((a%mod)*(b%mod))%mod;
}
void solve()
{
    int n;
    cin>> n;
    vector<int>a(n+1), b(n+1);
    int res = 0;
    for(int i = 1;i<=n;++i)cin >> a[i],res = ma(res,mm(n-1,mm(a[i],a[i])));
    for(int i = 1;i<=n;++i)cin >> b[i],res=ma(res,mm(n-1,mm(b[i],b[i])));
    int tot = accumulate(all(a),0ll)+accumulate(all(b),0ll);
    vector<vector<int>>dp1(n+1, vector<int>(tot+1)), dp(n+1, vector<int>(tot+1,1e18));
    // (a+b)^2 = a^2 + b^2 + 2ab
    // sum of squares of all values is included
    // all we have to reduce is sum of xy for all pairs
    // dp1[i][j] possible to achieve sum i uptil j
    // dp[i][j] min cost of sum of pair of products if sum of array a is j
    vector<int>pref(n+1);
    for(int i = 1;i<=n;++i)pref[i] = pref[i-1]+a[i]+b[i];
    for(auto x : {a[1],b[1]}){
        dp1[1][x] = 1;
        dp[1][x] = 0;
    }
    for(int i = 2;i<=n;++i){
        for(int j = 1;j<=tot;++j){
            if(j >= a[i]){
                if(dp1[i-1][j-a[i]]){
                    dp1[i][j] = 1;
                    int add1 = mm(a[i],j-a[i]), add2 = mm(b[i],pref[i-1]-j+a[i]),add3 = dp[i-1][j-a[i]];
                    dp[i][j] = min(dp[i][j], ma(ma(add1,add2),add3));
                }
            }
            if(j >= b[i]){
                if(dp1[i-1][j-b[i]]){
                    dp1[i][j] = 1;
                    int add1 = mm(b[i],j-b[i]), add2 = mm(a[i],pref[i-1]-j+b[i]),add3 = dp[i-1][j-b[i]];
                    dp[i][j] = min(dp[i][j], ma(ma(add1,add2),add3));
                }
            }
        }
    }
    
    cout << ma(res, mm(2,(*min_element(all(dp[n]))))) << endl;
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