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


const int N = 201;
int dp[N][N][N];
void solve()
{
    int n,m,k;
    cin >> n >>m >> k;
    vector<int>a(n), b(m), c(k);
    for(int &u : a)cin >> u;
    for(int &u : b)cin >> u;
    for(int &u : c)cin >> u;
    sort(all(a), greater<int>());
    sort(all(b), greater<int>());
    sort(all(c), greater<int>());
    int res = 0;
    for(int i = 0;i<=n;++i){
        for(int j = 0;j<=m;++j){
            for(int l = 0;l<=k;++l){
                if(i > 0 && j > 0){
                    dp[i][j][l] = max(dp[i][j][l], dp[i-1][j-1][l]+(a[i-1]*b[j-1]));
                }
                if(j > 0 && l > 0){
                    dp[i][j][l] = max(dp[i][j][l], dp[i][j-1][l-1]+(b[j-1]*c[l-1]));
                }
                if(i > 0 && l > 0){
                    dp[i][j][l] = max(dp[i][j][l], dp[i-1][j][l-1]+(a[i-1]*c[l-1]));
                }
                res = max(res, dp[i][j][l]);
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