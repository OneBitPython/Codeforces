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

// gfg code for modular division
int gcdExtended(int a, int b, int *x, int *y);
 
// Function to find modulo inverse of b. It returns
// -1 when inverse doesn't
int modInverse(int b, int m)
{
    int x, y; // used in extended GCD algorithm
    int g = gcdExtended(b, m, &x, &y);
 
    // Return -1 if b and m are not co-prime
    if (g != 1)
        return -1;
 
    // m is added to handle negative x
    return (x%m + m) % m;
}
 
// Function to compute a/b under modulo m
int md(int a, int b, int m=mod)
{
    a = a % m;
    int inv = modInverse(b, m);
    return(inv * a) % m;
}
 
// C function for extended Euclidean Algorithm (used to
// find modular inverse.
int gcdExtended(int a, int b, int *x, int *y)
{
    // Base Case
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }
 
    int x1, y1; // To store results of recursive call
    int gcd = gcdExtended(b%a, a, &x1, &y1);
 
    // Update x and y using results of recursive
    // call
    *x = y1 - (b/a) * x1;
    *y = x1;
 
    return gcd;
}

int ma(int a, int b){
    return ((a%mod)+(b%mod))%mod;
}
int mm(int a, int b){
    return ((a%mod)*(b%mod))%mod;
}
int sum(int n,int a){
    return md(mm(n,2*a + (n-1)*2),2);
}
void solve()
{
    int l,r;
    cin >> l>> r;
    vector<vector<int>>dp(61, vector<int>(2)); // dp[i][0] number of values in the range, dp[i][1] starting value of range
    dp[0] = {1,1};
    dp[1] = {2,2};
    for(int i = 2;i<=60;++i){
        dp[i][0] = (2*dp[i-1][0]);
        dp[i][1] = (dp[i-2][1]+(2*dp[i-2][0]));
    }
    int tot = 0;
    int res = 0;
    for(int i = 0;i<=60;++i){
        int start = tot+1, end = tot+dp[i][0];
        if(start <= l && r <= end){
            int s = dp[i][1]+(2*(l-start));
            cout << sum(r-l+1,s) << endl;
            return;
        }
        tot+=dp[i][0];
        if(tot > r)break;
    }

    tot = 0;
    for(int i = 0;i<=60;++i){
        int start = tot+1, end = tot+dp[i][0];

        if(l >= start && r >= end && l <= end){
            int exclude = (l-start);
            int start = dp[i][1]+(2*exclude);
            int rem = (dp[i][0]-exclude);
            res=ma(res,sum(rem,start));
            break;
        }
        tot = (tot+dp[i][0]);
        if(tot > r)break;
    }
    tot = 0;
    for(int i = 0;i<=60;++i){
        int start = tot+1, end = tot+dp[i][0];

        if(start > l && r > end){
            // include this whole range
            res=ma(res,sum(dp[i][0],dp[i][1]));
        }
        
        tot = (tot+dp[i][0]);
        if(tot > r)break;
    }
    tot = 0;
    for(int i = 0;i<=60;++i){
        int start = tot+1, end = tot+dp[i][0];

        if(start >= l && end >= r){
            int include = (r-start+1);
            int start = dp[i][1];
            res=ma(res,sum(include,start));
            break;
        }
        tot = (tot+dp[i][0]);
        if(tot > r)break;
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