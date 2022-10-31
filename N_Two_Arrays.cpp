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

int mod = 1e9+7;
int ma(int a,int b){
    return ((a%mod)+(b%mod))%mod;
}
int ms(int a,int  b){
    return ((((a%mod)-(b%mod))%mod) + mod) % mod;
}
int f(vector<vector<int>>&pref,int a,int b, int A, int B){
    return ma(ms(ms(pref[A][B],pref[a-1][B]),pref[A][b-1]),pref[a-1][b-1]);
}

void solve()
{
    int n,m;
    cin >> n >> m;
    vector<vector<vector<int>>>dp(m+1,vector<vector<int>>(n+1,vector<int>(n+1))), pref(m+1,vector<vector<int>>(n+1,vector<int>(n+1)));
    // dp[i][j][k] number of sequences of length i which have a[i] = j and b[i] = k
    int res = 0;
    for(int i = 1;i<=n;++i){
        for(int j = i;j<=n;++j){
            dp[1][i][j] = 1;
            pref[1][i][j] = ma(ms(ma(pref[1][i-1][j],pref[1][i][j-1]),pref[1][i-1][j-1]),1);
            if(m==1)res+=1;
        }
    }
    res%=mod;
    for(int i = 2;i<=m;++i){
        for(int j = 1;j<=n;++j){
            for(int k = j;k<=n;++k){
                int val = f(pref[i-1],1,k,j,n);
                pref[i][j][k] = ma(ms(ma(pref[i][j-1][k],pref[i][j][k-1]),pref[i][j-1][k-1]),val);
                dp[i][j][k] = val;
                if(i==m)res=ma(res,dp[i][j][k]);
            }
        }
    }
    cout << res%mod;
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