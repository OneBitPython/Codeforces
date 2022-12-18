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

vector<vector<int>>a;
int n;
bool check(int i, int j, int x){
    // check if a value in the range i
    for(int k = 1;k<=i;++k){
        for(int l = j;l<=n;++l){
            if(a[k][l]==1)return 1;
        }
    }
    return 0;
}
bool got(int i, int j){
    for(int k = i+1;k<=j;++k){
        if(a[i][k]==1)return 0;
    }
    return 1;
}
bool got2(int i, int j){
    for(int k = i;k<j;++k){
        if(a[k][j]==1)return 0;
    }
    return 1;
}
void solve()
{
    cin >> n;
    a = vector<vector<int>>(n+1, vector<int>(n+1));
    for(int i = 1;i<=n;++i){
        for(int j = i;j<=n;++j)cin >> a[i][j];
    }
    for(int i =1;i<=n;++i){
        for(int j = i;j<=n;++j){
            if(i==j && a[i][j]==2){
                cout << 0 << endl;
                return;
            }
            if(a[i][j]!=1)continue;
            for(int k = i;k<=j;++k){
                for(int l = k;l<=j;++l){
                    if(a[k][l] == 2){
                        cout << 0 << endl;
                        return;
                    }
                }
            }
        }
    }
    vector<vector<vector<vector<int>>>>dp(n+1, vector<vector<vector<int>>>(n+1, vector<vector<int>>(3, vector<int>(2))));
    for(int i = 1;i<=n;++i){
        int j = i;
        dp[i][j][1][0] = dp[i][j][1][1] = 1;
    }
    for(int i = 1;i<n;++i){
        int j = i+1;
        if(a[i][j]!=2)dp[i][j][1][0] = dp[i][j][1][1] = 1;
        if(!check(i,j,1))dp[i][j][2][0] = 2; // 01 or 10
    }
    int mod = 998244353 ;
    for(int gap = 3;gap<=n;++gap){
        for(int i = 1;i<=n;++i){
            int j = i+gap-1;
            if(j > n)break;
            if(a[i][j]!=2){
                dp[i][j][1][0] = dp[i][j][1][1] = 1;
            }
            // now you add a distinct value
            if(!check(i,j,1)){
                if(got(i,j))dp[i][j][2][0] = (dp[i+1][j][1][1]+dp[i+1][j][1][0])%mod;
                if(got2(i,j))dp[i][j][2][0] += (dp[i][j-1][1][1] + dp[i][j-1][1][0])%mod;
                dp[i][j][2][0] += (dp[i+1][j][2][0]*2)%mod;
                dp[i][j][2][0] += (dp[i][j-1][2][0]*2)%mod;
                dp[i][j][2][0]/=2;
            }
        }
    }
    int res = 0;
    dbg(dp[1][2]);
    dbg(dp[2][3]);
    dbg(dp[1][3]);
    for(int k = 1;k<=2;++k){
        res+=(dp[1][n][k][0]+dp[1][n][k][1])%mod;
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