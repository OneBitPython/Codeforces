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

const int N = 501;
int dp[3][N][N];

void solve()
{
    int n;
    cin >> n;
    vector<int>a(n+1);
    for(int i = 1;i<=n;++i)cin >> a[i];
    for(int i = 0;i<=2;++i){
        for(int j= 0;j<=n;++j){
            for(int k= 0;k<=n;++k)dp[i][j][k] = 1e9;
        }
    }
    /*
    
dp[i][j][k] minimum sum of sizes of sequences in prefix i, if you have j groups and last untaken element of a group is at position k.

dp[i][j][k] = dp[i-1][j][k]+1

if(a[i] > a[k])
dp[i][j][i] = dp[i-1][j][k]

dp[1][1][0] = 1
dp[1][0][1] = 0
    */
    dp[1][1][0] = 1;
    dp[1][0][1] = 0;
    for(int i= 2;i<=n;++i){
        int c = (i%2), p = 1-c;
        for(int j= 0;j<=n;++j){
            for(int k = 0;k<=n;++k)dp[c][j][k] = 1e9;
        }
        for(int j = 0;j<=i;++j){
            for(int k = 0;k<i;++k){
                if(k!=(i-1))dp[c][j][k] = min(dp[c][j][k],dp[p][j][k]+1); // add to taken sequence
                else{   
                    if(a[i] > a[i-1])dp[c][j][i] = min(dp[c][j][i],dp[p][j][k]); // add to untaken sequence
                }
                if(a[i] > a[k] && k!=(i-1)){
                    dp[c][j][i] = min(dp[c][j][i],dp[p][j][k]); // break the sequence
                }
                if(j){
                    dp[c][j][k] = min(dp[c][j][k],dp[p][j-1][k]+1); // start a new sequence

                }
            }
        }
    }
    // 5 1 2
    // 6 1 6
    

    int res = 1e9;
    for(int k = 0;k<=n;++k)res = min(res, dp[n%2][0][k]);
    
    for(int j = 1;j<=n;++j){
        for(int k = 0;k<=n;++k)res = min(res, dp[n%2][j][k]);
        cout << res << ' ';
    }
    cout << endl;
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