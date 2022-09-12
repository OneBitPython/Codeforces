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
    int n,x;
    cin >> n >> x;
    vector<int>a(n+1);
    for(int i = 1;i<=n;++i)cin >> a[i];
    int s = n * x +  1;
    vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(n+1, vector<int>(s+1)));
    for(int j = 1;j<=n;++j){
        for(int k = 1;k<=s;++k){
            dp[1][j][k] = dp[1][j-1][k] + (a[j]==k);
        }
    }
    for(int i = 2;i<=n;++i){
        for(int j = i;j<=n;++j){
            for(int k = 1;k<=s;++k){
                dp[i][j][k] += dp[i][j-1][k];
                if(k>=a[j]) dp[i][j][k] += dp[i-1][j-1][k-a[j]];
            }
        }
    }
    int res = 0;
    for(int i = 1;i<=n;++i){
        for(int k = 1;k<=s;++k){
            if(k%i!=0)continue;
            int val = k/i;
            if(val == x)res+=dp[i][n][k];
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