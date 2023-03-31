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

int mod = 998244353;
int ma(int a, int b){
    return ((a%mod)+(b%mod))%mod;
}
int ms(int a, int b){
    return (((a%mod)-(b%mod)%mod)+mod)%mod;
}

void solve()
{
    /*
    the first position has to be a 0 or a 1

    if the last element of the subsequence is greater than the mex by 1 then you can't continue this sequence by adding a value other than x[k]
    0 2 (mex = 1) you can't add any element other than 2 now

    dp[i][0] number of sequences uptill i with a[i] as the last element and mex = a[i]-1
    dp[i][1] number of sequences uptill i with a[i] as the last element and mex = a[i]+1

    dp[i][0] = 1 for all i with a[i] = 1
    dp[i][1] = 1 for all i with a[i] = 0
    let pref[0][x] denote the sum of dp[i][0] when a[i] = x and pref[1][x] denote the sum of dp[i][1] when a[i] = x

    dp[i][0] += pref[0][a[i]]
    dp[i][0] += pref[1][a[i]-2] a[i]>=2

    dp[i][1] += pref[1][a[i]]
    dp[i][1] += pref[1][a[i]-1](a[i]>=1)
    dp[i][1] += pref[0][a[i]+2]

    then add dp[i][0] to pref[0][a[i]] and add dp[i][1] to pref[1][a[i]]

    answer is sum of dp[i][0] and dp[i][1] over all i
    
    */
    int n;
    cin >> n;
    vector<int>a(n+1);
    for(int i = 1;i<=n;++i)cin >> a[i];
    vector<vector<int>>dp(n+1, vector<int>(2));
    for(int i = 1;i<=n;++i){
        if(a[i]==1)dp[i][0] = 1;
        if(a[i]==0)dp[i][1] = 1;
    }
    vector<map<int,int>>pref(2);
    map<int,int>spec;
    int res = 0;
    for(int i = 1;i<=n;++i){
        if(a[i]>0)dp[i][0] = ma(dp[i][0],pref[0][a[i]]);
        if(a[i]>=2)dp[i][0] = ma(dp[i][0],pref[1][a[i]-2]);

        dp[i][1] = ma(dp[i][1],pref[1][a[i]]);
        spec[a[i]] = ma(spec[a[i]],spec[a[i]]);
        if(a[i]>=1)dp[i][1] = ma(dp[i][1],ms(pref[1][a[i]-1],spec[a[i]-1]));
        dp[i][1] = ma(dp[i][1],pref[0][a[i]+2]);
        spec[a[i]] = ma(spec[a[i]],pref[0][a[i]+2]);

        pref[0][a[i]] = ma(pref[0][a[i]],dp[i][0]);
        pref[1][a[i]] = ma(pref[1][a[i]],dp[i][1]);
        res = ma(res,dp[i][0]);
        res = ma(res,dp[i][1]);
    }
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