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
int mxn = 5001;
int ma(int a, int b){
    return ((a%mod)+(b%mod))%mod;
}
int mm(int a, int b){
    return ((a%mod)*(b%mod))%mod;
}
vector<int>fact(mxn+1);
void pre(){
    fact[0] = 1;
    for(int i = 1;i<=mxn;++i)fact[i] = mm(fact[i-1],i);
}
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
int modDivide(int a, int b, int m=mod)
{
    a = a % m;
    int inv = modInverse(b, m);
    return (inv * a) % m;
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


int ncr(int n, int r){
    return modDivide(fact[n],mm(fact[n-r],fact[r]));
}
void solve()
{
    int n,k;
    cin >> n >> k;
    vector<int>a(n+1);
    for(int i=1;i<=n;++i)cin >> a[i];
    vector<int>mx(n+1); // max groups you can form till here
    vector<int>pref(n+1); // pref mx
    for(int i = 1;i<=n;++i){
        int c = 0;
        for(int j = i;j>=0;--j){
            c+=(a[i]==a[j]);
            if(c==k){
                mx[i] = 1+pref[j-1];
                break;
            }
        }
        pref[i] = max(pref[i-1],mx[i]);
    }
    if(pref.back()==0){
        cout << 1 << endl;
        return;
    }
    int m = pref.back();
    vector<int>dp(n+1);
    dp[0] = 1;
    int res = 0;
    for(int i = 1;i<=n;++i){
        int c = 1;
        for(int j = i-1;j>=0;--j){
            if(c >=k && mx[j]+1==mx[i])dp[i] = ma(mm(dp[j],ncr(c-1,k-1)),dp[i]);
            c+=(a[i]==a[j]);
        }
        if(mx[i]==m)res = ma(res,dp[i]);
    }

    cout <<res%mod << endl;
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
    cin >> T;
    pre();
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}