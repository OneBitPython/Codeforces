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

const int N = 4005, M = 2005, K = 2;
int dp[N][M][K];
void solve()
{
    int n;
    cin >> n;
    int m = n;
    n *= 2;
    vector<int>a(n+1);
    for(int i = 1;i<=n;++i)cin >> a[i];
    /*
    dp[i][j][k] possible to put j values in the first group and j-i in the second group if the ith value is added to the kth array (0<=k<=1)
    if a[i] is not the max value in prefix then they have to be in the same group as prev element
    dp[i][j][0] = dp[i-1][j-1][0] (a[i-1] is added to the first array (same as  a[i]))
    dp[i][j][1] = dp[i-1][j][1] (a[i-1] is added to the second arry(same as a[i]))

    if a[i] is the max valuein prefix then they can be either be in the same group as a[i-1] or not
    dp[i][j][0] = dp[i-1][j-1][0] || dp[i-1][j-1][1]
    dp[i][j][1] = dp[i-1][j][0] || dp[i-1][j][1]
    */
    dp[1][0][1] = 1;
    dp[1][1][0] = 1;
    int mx = a[1];
    for(int i = 2;i<=n;++i){
        for(int j = 0;j<=min(i,m);++j){
            mx = max(mx, a[i]);
            dp[i][j][0] = dp[i][j][1] = 0;
            if(a[i] >= mx){
                if(j > 0)dp[i][j][0] = dp[i-1][j-1][0]|dp[i-1][j-1][1];
                dp[i][j][1] = dp[i-1][j][0]|dp[i-1][j][1];
            }else{
                if(j > 0)dp[i][j][0] = dp[i-1][j-1][0];
                dp[i][j][1] = dp[i-1][j][1];
            }
        }
    }
    cout << (dp[n][m][0]||dp[n][m][1]?"YES":"NO") << endl;
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