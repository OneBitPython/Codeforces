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


int n,K,mod;
int ma(int a, int b,int m=mod){
    return (a+b)%m;
}
int mm(int a, int b,int m=mod){
    return (a*b)%m;
}
int ms(int a, int b,int m=mod){
    return ((((a%m)-(b%m))%m)+m)%m;
}
void solve()
{
    cin >> n >> K >>mod;
    int res = K;
    for(int i = 2;i<=n;++i)res = mm(res,K);
    for(int sum = 0;sum<K;++sum){
        vector<vector<int>>dp(n+1,vector<int>(K));
        dp[0][0] = 1;
        for(int i = 1;i<=n;++i){
            for(int j = 0;j<K;++j){
                if(ma(j,j,K)==sum)continue;
                for(int m = 0;m<K;++m){
                    dp[i][ma(m,j,K)] = ma(dp[i][ma(m,j,K)],dp[i-1][m]);
                }
            }
        }
        res = ms(res,dp[n][sum]);
    }
    cout << res;
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