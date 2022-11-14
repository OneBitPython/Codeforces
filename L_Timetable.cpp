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
    int n,m,x;
    cin >> n >> m >> x;
    vector<string>a(n+1);
    for(int i = 1;i<=n;++i)cin >> a[i];
    vector<vector<int>>dp(n+1, vector<int>(x+1)), dp2(n+5, vector<int>(m+5,1e18));
    // dp2[i][j] min hours to stay in class if you change j values
    // dp[i][j] min cost uptill i if you attend j lectures in total 
    for(int i = 1;i<=n;++i){
        int changed = 0;
        for(int j = 0;j<m;++j){
            if(a[i][j] == '0')continue;
            int c = changed;
            for(int k = m-1;k>=j;--k){
                if(a[i][k] == '0')continue;
                dp2[i][c] = min(dp2[i][c],k-j+1);
                c++;
            }
            changed++;
        }
        dp2[i][changed] = 0;
    }
    for(int i = 1;i<=n;++i){
        for(int j = 0;j<=x;++j){
            dp[i][j] = 1e18;
            for(int k = 0;k<=j;++k){
                if(i == 1 && j!=k)continue;
                if(k > m)continue;
                dp[i][j] = min(dp[i][j], dp[i-1][j-k]+dp2[i][k]);
            }
        }
    }
    int res = 1e18;
    for(int i = 0;i<=x;++i)res = min(res, dp[n][i]);
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