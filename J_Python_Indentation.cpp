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
    int n;
    cin >> n;
    vector<char>a(n+1);
    for(int i = 1;i<=n;++i)cin >> a[i];
    vector<vector<int>>dp(n+1, vector<int>(n+1)); //dp[i][j] cost uptill line i if ith line is at indent = j
    dp[1][0] = 1;
    int res = 0;
    int sum = 1;
    int m = 1e9+7;
    for(int i = 2;i<=n;++i){
        int s = 0;
        for(int j = 0;j<i;++j){
            if(a[i-1] == 's'){
                dp[i][j] += sum;
                dp[i][j] %= m;
                sum = (((sum-dp[i-1][j])%m) + m) % m;
            }else{
                if(j > 0)dp[i][j]+=dp[i-1][j-1];
                dp[i][j]%=m;
            }
            s+=dp[i][j];
            s%=m;
            if(i==n){
                res+=dp[i][j];
                res%=m;
            }
        }
        sum = s;
    }
    if(n==1)res = 1;
    cout <<  res;
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