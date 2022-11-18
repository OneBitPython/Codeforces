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
    int n,h;
    cin >> n >> h;
    vector<int>a(n+1);
    for(int i = 1;i<=n;++i)cin >> a[i];
    sort(all(a));
    vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(3, vector<int>(2)));
    // dp[i][j][k] max cost till i if you take j greens and k blues
    for(int j = 0;j<=2;++j){
        for(int k = 0;k<=1;++k)dp[0][j][k] = h;
    }
    int res = 0;
    for(int i = 1;i<=n;++i){
        for(int j = 0;j<=2;++j){
            for(int k = 0;k<=1;++k){
                // you take j green's till i and k blues till i
                for(int l = 0;l<=j;++l){
                    for(int m = 0;m<=k;++m){
                        int get = dp[i-1][j-l][k-m];
                        bool took = 0;
                        if(get > a[i]){
                            get+=(a[i]/2);
                            took = 1;
                        }
                        get*=(pow(2,l));
                        get*=(pow(3,m));
                        if(get > a[i] && !took){
                            get+=(a[i]/2);
                        }
                        dp[i][j][k] = max({dp[i][j][k],dp[i-1][j][k],get});
                    }
                }
                if(dp[i][j][k] > a[i])res = i;
            }
        }
        
    }
    cout << res << endl;
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
    cin >> T;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}