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


const int N = 51;
int dp[N][N][N][N];
vector<vector<int>>pref(N+1,vector<int>(N+1));
int sum(int a, int b, int A, int B){
    return pref[A][B]+pref[a-1][b-1]-pref[A][b-1]-pref[a-1][B];
}
void solve()
{
    int n,m;
    cin >> n >> m;
    vector<vector<int>>a(n+1, vector<int>(m+1));
    for(int i = 1;i<=n;++i){
        for(int j = 1;j<=m;++j)cin >> a[i][j],pref[i][j] = a[i][j] + pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1];
    }
    for(int x = 1;x<=n;++x){
        for(int y = 1;y<=m;++y){
            for(int i = 1;i<=n;++i){
                for(int j = 1;j<=m;++j){
                    int k = i+x-1, l = j+y-1;
                    if(k > n || l > m)break;
                    if(x==1 && y == 1){
                        dp[i][j][k][l] = 0;
                        continue;
                    }
                    dp[i][j][k][l] = 1e18;
                    int T = sum(i,j,k,l);
                    for(int z = (l-1);z>=j;--z){
                        dp[i][j][k][l] = min(dp[i][j][k][l], dp[i][j][k][z]+dp[i][z+1][k][l]+T);
                    }
                    for(int z = (k-1);z>=i;--z){
                        dp[i][j][k][l] = min(dp[i][j][k][l], dp[i][j][z][l] + dp[z+1][j][k][l]+T);
                    }
                }
            }
        }
    }
    cout << dp[1][1][n][m] << endl;
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