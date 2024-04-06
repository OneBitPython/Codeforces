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
int ma(int a, int b){
    return ((a%mod)+(b%mod))%mod;
}
int mm(int a, int b){
    return ((a%mod)*(b%mod))%mod;
}
void solve()
{
    int n,m1,m2;
    cin >> n >> m1 >> m2;
    vector<int>a(m1+1), b(m2+1);
    for(int i = 1;i<=m1;++i)cin>> a[i];
    for(int i = 1;i<=m2;++i)cin >> b[i];
    vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(m1+1, vector<int>(m2+1)));
    dp[1][1][1] = 1;
    for(int i = 2;i<=n;++i){
        for(int j = 1;j<=m1;++j){
            for(int k = 1;k<=m2 && (j+k)-1 <= i;++k){
                int opt = max(0ll,b[k] - a[m1-j+1] - j-k+2);
                int left = max(0ll,opt - ((i-1)-(j+k-1)));
                dp[i][j][k] = ma(dp[i][j][k],mm(dp[i-1][j][k],left));
                if(j > 1){
                    dp[i][j][k] = ma(dp[i][j][k],dp[i-1][j-1][k]);
                }
                if(k>1){
                    dp[i][j][k] = ma(dp[i][j][k],dp[i-1][j][k-1]);
                }
            }
        }
    }
    for(int i = 1;i<=n;++i){
    for(int j = 1;j<=m1;++j){
        for(int k = 1;k<=m2;++k){
            dbg(i,j,k,dp[i][j][k]);
        }
    }
    }
    cout << dp[n][m1][m2] << endl;
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