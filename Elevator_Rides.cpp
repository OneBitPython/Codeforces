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
    int n,t;
    cin >> n >> t;
    vector<int>a(n);
    for(int &u : a)cin >> u;
    int u = (1ll<<n);
    vector<vector<int>>dp(u, vector<int>(2));
    for(int i = 0;i<n;++i)dp[1ll<<i][0] = 1, dp[1ll<<i][1] = a[i];
    for(int i = 0;i<u;++i){
        if(__builtin_popcount(i)<=1) continue;
        dp[i][0] = 1e18;
        dp[i][1] = 1e18;
        for(int j = 0;j<n;++j){
            if(i&(1ll<<j)){
                int x = i - (1ll<<j);
                if(dp[x][1]+a[j] > t){
                    if(dp[x][0]+1 < dp[i][0]){
                        dp[i][0] = dp[x][0]+1;
                        dp[i][1] = a[j];
                    }else if(dp[x][0]+1==dp[i][0] && a[j]<dp[i][1]){
                        dp[i][0] = dp[x][0]+1;
                        dp[i][1] = a[j];
                    }
                }else{
                    if(dp[x][0] < dp[i][0]){
                        dp[i][0] = dp[x][0];
                        dp[i][1] = dp[x][1]+a[j];
                    }else if(dp[x][0]==dp[i][0] && dp[x][1]+a[j]<dp[i][1]){
                        dp[i][0] = dp[x][0];
                        dp[i][1] = dp[x][1]+a[j];
                    }
                }
            }
        }
    }
    // for(int i = 0;i<u;++i){
    //     dbg(dp[i],i);
    // }
    cout << dp[u-1][0] << endl;
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
    // cin >> T;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}