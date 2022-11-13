#include <bits/stdc++.h>
using namespace std;

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

const int N = 505, M = 505, B = 505;
int dp[2][B][M];
void solve()
{
    int n,m,b,mod;
    cin >> n >> m >> b >> mod;
    vector<int>a(n+1);
    for(int i = 1;i<=n;++i)cin >> a[i];

    // dp[i][j][k] number of sequences which have length i, j bugs and sum of length of codes = k
    // dp doesn't have to store all N positions but only latest 2 of them
    // two rows trick
    for(int j = 0;j<=b;++j){
        if(a[1] != 0 && j%a[1] == 0)dp[1][j][j/a[1]] += 1;
        for(int k = 0;k<=m;++k){
            if(a[1] == 0 && j == 0)dp[1][0][k] = 1;
            if(n > 1 && k >= 1){
                if(j >= a[2])dp[1][j][k] += dp[1][j-a[2]][k-1];
                dp[1][j][k] %= mod;
            }
        }
    }
    for(int i = 2;i<=n;++i){
        int c = i%2;
        for(int j = 0;j<=b;++j){
            dp[c][j][0] = dp[1^c][j][0]%mod;
            for(int k = 1;k<=m;++k){
                dp[c][j][k] = dp[1^c][j][k]%mod;
                if(i < n){
                    if(j >= a[i+1])dp[c][j][k] += dp[c][j-a[i+1]][k-1];
                }   
                dp[c][j][k] %= mod;
            }
        }

    }
    int res = 0;
    for(int j = 0;j<=b;++j){
        res += dp[n%2][j][m];
        res%=mod;
    }
    cout << res;
}   

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    

    int T=1;
    // cin >> T;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}