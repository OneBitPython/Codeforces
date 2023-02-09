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

int m = 1e9+7;
int mm(int a, int b){
    return ((a%m)*(b%m))%m;
}
int ma(int a, int b){
    return ((a%m)+(b%m))%m;
}
int ms(int a, int b){
    return ((((a%m)-(b%m))%m) + m)% m;
}
//https://www.geeksforgeeks.org/compute-ncrp-using-fermat-little-theorem/in O(log y) */
unsigned long long power(unsigned long long x, 
                                  int y, int p)
{
    unsigned long long res = 1; // Initialize result
  
    x = x % p; // Update x if it is more than or
    // equal to p
  
    while (y > 0) 
    {
      
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % p;
  
        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}
  
// Returns n^(-1) mod p
unsigned long long modInverse(unsigned long long n,  
                                            int p)
{
    return power(n, p - 2, p);
}
  
// Returns nCr % p using Fermat's little
// theorem.
unsigned long long ncr(unsigned long long n,
                                 int r, int p=m)
{
    // If n<r, then nCr should return 0
    if (n < r)
        return 0;
    // Base case
    if (r == 0)
        return 1;
  
    // Fill factorial array so that we
    // can find all factorial of r, n
    // and n-r
    unsigned long long fac[n + 1];
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = (fac[i - 1] * i) % p;
  
    return (fac[n] * modInverse(fac[r], p) % p
            * modInverse(fac[n - r], p) % p)
           % p;
}
void solve()
{
    int n;
    cin >> n;
    vector<int>a(n+1);
    for(int i = 1;i<=n;++i)cin >> a[i];
    vector<int>p(n+1);
    p[0] = 1;
    for(int i = 1;i<=n;++i){
        p[i] = mm(p[i-1],2);
    }
    int res = 0;
    for(int i =2;i<=n;++i)res = ma(res, ncr(n,i));
    vector<int>suff(n+2);
    for(int i = n;i>=1;--i){
        suff[i] = ma(suff[i+1],p[n-i]);
    }
    vector<int>pref(n+1);
    for(int i = 1;i<=n;++i)pref[i] = ma(pref[i-1],p[i-1]);
    for(int i = 2;i<n;++i){
        // find contrib of the ith index
        // ith index contributes to the number of subsets in which i goes left and the next value goes right
        int sum1 = 0;
        for(int j = i+1;j<n;++j){
            // assume jth index goes right, it'll only go right if d(j,k)<d(i,j)
            int bench = a[j]-a[i];
            // find the last value such that a[k]-a[j] < bench ie a[k] < bench+a[j]
            int val = lower_bound(all(a),bench+a[j])-a.begin()-1;
            if(val==j)continue;
            
            int curr = ms(suff[j+1],suff[val+1]);
            // now find the number of l (l < i) such that d(l,i) <= d(i,j)
            // a[i]-a[l] <= bench
            // a[i]-bench <= a[l]
            // a[l] >= a[i]-bench
            val = lower_bound(a.begin()+1,a.end(), a[i]-bench) - a.begin();
            int curr2 = ms(pref[i-1],pref[val-1]);
            res = ma(res, mm(curr, curr2));
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