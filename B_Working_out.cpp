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
    int n,m;
    cin >> n >> m;
    vector<vector<int>>a(n+4, vector<int>(m+4));
    vector<vector<vector<int>>>dp(n+4,vector<vector<int>>(m+4,vector<int>(4)));
    for(int i = 1;i<=n;++i){
        for(int j = 1;j<=m;++j)cin >> a[i][j];
    }
    /*
    the boy can go right and down starting from (1,1), he ends at (n,m)
    the girl can go right and up starting from (n,1), she ends at (1,m)
    they should meet only in one square
    in the square that they meet, the boy should only move right to that square if the girl moves up
    in the square that they meet, the boy should only move down to that square if the girl moves to the right

    dp[i][j][0] cost from (1,1) to (i,j) going right and down
    dp[i][j][1] cost from (i,j) to (n,m) going right and down
    dp[i][j][2] cost from (n,1) to (i,j) going up and right
    dp[i][j][3] cost from (i,j) to (1,m) going up and right


    */
    for(int i = 1;i<=n;++i){
        for(int j = 1;j<=m;++j){
            dp[i][j][0] = max(dp[i-1][j][0],dp[i][j-1][0])+a[i][j];
        }
    }
    for(int i = n;i>=1;--i){
        for(int j = m;j>=1;--j){
            dp[i][j][1] = max(dp[i+1][j][1],dp[i][j+1][1])+a[i][j];
        }
    }
    for(int i = n;i>=1;--i){
        for(int j = 1;j<=m;++j){
            dp[i][j][2] = max(dp[i][j-1][2], dp[i+1][j][2])+a[i][j];
        }
    }
    for(int i = 1;i<=n;++i){
        for(int j = m;j>=1;--j){
            dp[i][j][3] = max(dp[i-1][j][3],dp[i][j+1][3])+a[i][j];
        }
    }
    int res = 0;
    for(int i = 2;i<n;++i){
        for(int j = 2;j<m;++j){
            // boy comes from right, girl comes from the bottom
            int c1 = dp[i][j-1][0] + dp[i+1][j][2] + dp[i][j+1][1] + dp[i-1][j][3];
            // boy comes from the top girl comes from the right
            int c2 = dp[i-1][j][0] + dp[i+1][j][1] + dp[i][j-1][2] + dp[i][j+1][3];
            res = max({res,c1,c2});
        }
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