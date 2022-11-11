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


int f(int a){
    return __builtin_popcount(a);
}
void solve()
{
    int n,m,k;
    cin >> n >> m >> k;
    vector<vector<int>>a(n+1, vector<int>(n+1));
    vector<int>c(n);
    for(int i = 0;i<n;++i)cin >> c[i];
    for(int i = 1;i<=k;++i){
        int u,v;
        cin >> u >> v;
        int c;
        cin >> c;
        a[--u][--v] = c;
    }
    int u = (1ll<<n);
    vector<vector<int>>dp(u, vector<int>(n));
    // dp[i][j] cost for a submask i if j is the first member of the mask
    int res = 0;
    for(int i = 1;i<u;++i){
        if(f(i) == 1){
            for(int j = 0;j<n;++j){
                if(i&(1ll<<j)){
                    dp[i][j] = c[j];
                }
                if(f(i) == m)res = max(res, dp[i][j]);
            }
        }    
    }
    for(int i = 1;i<u;++i){
        if(f(i) > 1){
            for(int j = 0;j<n;++j){
                if(!(i&(1ll<<j)))continue;
                int x = i-(1ll<<j);
                for(int k = 0;k<n;++k){
                    if(x&(1ll<<k)){
                        dp[i][j] = max(dp[i][j], a[j][k]+c[j]+dp[x][k]);
                    }
                }
                if(f(i) == m)res = max(res, dp[i][j]);

            }
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