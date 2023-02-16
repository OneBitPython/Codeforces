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

int mxn = 4e5;
vector<int>fact(mxn+1);
int mod = 998244353;
int gcdExtended(int a, int b, int *x, int *y);
 
// https://www.geeksforgeeks.org/modular-division/
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

int ma(int a, int b){
    return ((a%mod)+(b%mod))%mod;
}
int mm(int a, int b){
    return ((a%mod)*(b%mod))%mod;
}
void pre(){
    fact[0] = 1;
    for(int i = 1;i<=mxn;++i){
        fact[i] = mm(fact[i-1],i);
    }
}

int ncr(int n, int r){
    return modDivide(fact[n],mm(fact[n-r],fact[r]));
}

void solve()
{
    int n;
    cin >> n;
    int g = n/3;
    vector<vector<pair<int,int>>>adj(n+1);
    for(int i = 1;i<=n;++i){
        int w;
        cin>> w;
        if((i%3) == 1)adj[i].pb({w,i+1}), adj[i+1].pb({w, i});
        if((i%3) == 2)adj[i-1].pb({w,i+1}), adj[i+1].pb({w, i-1});
        if((i%3) == 0)adj[i].pb({w,i-1}), adj[i-1].pb({w, i});

    }
    int res = ncr(g,g/2) % mod;
    for(int i = 1;i<=n;i+=3){
        vector<int>w;
        
        int mx = -1e18;
        for(int j = i;j<=i+2;++j){
            int c = 0;
            for(auto x : adj[j])c+=x.first;
            mx = max(mx, c);
            w.pb(c);
        }
        int pos = 0;
        for(auto x : w){
            if(x==mx)pos++;
        }
        res = mm(res, pos);
    }
    cout << res;
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
    pre();
    // cin >> T;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}