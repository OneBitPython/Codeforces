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
    int n,k;
    cin >> n >> k;
    vector<vector<int>>dp(2, vector<int>(n+1));
    // dp[i][j] number of sequences of size i that end with value j
    for(int i = 0;i<=n;i+=k){
        dp[1][i] = 1;
    }
    vector<int>res(n+1);
    res[0] = 1;
    int sum = 0;
    int m = 998244353;
    for(int i = 2;i<=n;++i){
        int c = i%2;
        if(sum > n)break;
        for(int j = 0;j<=n;++j){
            int val = k+i-2;
            dp[c][j] = 0;
            if(j >= val){
                dp[c][j] += dp[c^1][j-val];
                dp[c][j]%=m;
                res[j] += dp[c][j]%m;
            }
            val = k+i-1;
            if(j >= val)dp[c][j] += dp[c][j-val];
        }
        sum+=(k+i-2);
    }
    for(int i = 1;i<=n;++i)cout << res[i]%m << ' ';
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
    // cin >> T;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}