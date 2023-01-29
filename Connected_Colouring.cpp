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


const int N = 100001, K = 3;
int dp[N][K][2][2];
void solve()
{
    int n,k;
    cin >>n;
    k = 2;
    for(int i = 0;i<=n;++i){
        for(int j = 0;j<K;++j){
            for(int l = 0;l<=1;++l){
                for(int m = 0;m<=1;++m)dp[i][j][l][m] = 0;
            }
        }
    }
    dp[1][1][0][0] = 1;
    dp[1][2][0][1] = 1;
    dp[1][2][1][0] = 1;
    dp[1][1][1][1] = 1;
    int mod = 1e9+7;

    for(int i = 2;i<=n;++i){
        for(int j = 1;j<=k;++j){
            dp[i][j][0][0] += (dp[i-1][j][0][0]+dp[i-1][j][1][0] + dp[i-1][j][0][1]+dp[i-1][j-1][1][1]);
            dp[i][j][0][0]%=mod;
            dp[i][j][0][1] += (dp[i-1][j][0][1]+dp[i-1][j-1][1][1]+dp[i-1][j-1][0][0]);
            if(j >= 2)dp[i][j][0][1] += dp[i-1][j-2][1][0];
            dp[i][j][0][1] %= mod;
            dp[i][j][1][0] += (dp[i-1][j][1][0]+dp[i-1][j-1][1][1]+dp[i-1][j-1][0][0]);
            if(j >= 2)dp[i][j][1][0] += dp[i-1][j-2][0][1];
            dp[i][j][1][0]%=mod;
            dp[i][j][1][1] += (dp[i-1][j][1][1]+dp[i-1][j][1][0]+dp[i-1][j][0][1]+dp[i-1][j-1][0][0]);
            dp[i][j][1][1]%=mod;
        }
    }
    int res = 0;
    for(int i = 0;i<=1;++i){
        for(int j = 0;j<=1;++j){
            res += (dp[n][k][i][j]);
            res%=mod;
        }
    }
    cout << res << endl;
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