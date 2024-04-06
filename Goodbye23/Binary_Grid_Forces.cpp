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

int N = 1e6;
vector<int>fact(N+1);
int mod = 1e9+7;
int mm(int a, int b){
    return ((a%mod)*(b%mod))%mod;
}
int gcdExtended(int a, int b, int *x, int *y);
//https://www.geeksforgeeks.org/modular-division/
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
int gcdExtended(int a, int b, int *x, int *y)
{
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


void pre(){
    fact[0] = 1;
    for(int i = 1;i<=N;++i)fact[i] = mm(fact[i-1],i);
}
int ncr(int n, int r){
    return modDivide(fact[n],mm(fact[n-r],fact[r]));
}
void solve()
{
    int n,m;
    cin >> n >> m;
    vector<vector<int>>a(n+1, vector<int>(m+1));
    for(int i= 1;i<=n;++i){
        string s;
        cin >> s;
        s = "0"+s;
        for(int j = 1;j<=m;++j)a[i][j] = s[j]-'0';
    }
    set<int>prev;
    for(int i = 1;i<=m;++i){
        if(a[n][i])prev.insert(i);
    }
    for(int i = n-1;i>=2;--i){
        set<int>curr;
        for(int j = 1;j<=m;++j){
            if(a[i][j])curr.insert(j);
        }
        int fst = 1e18, lst = -1;
        int j = 0;
        for(auto x : prev){
            if(curr.count(x) && fst==1e18)fst = j;
            if(curr.count(x))lst = j;
            j++;
        }
        j = 0;
        for(auto x : prev){
            if(curr.size() > 1 && prev.size() > 1){
                if(j > fst || j < lst)curr.insert(x);
            }
            j++;
        }
        prev = curr;
    }
    int cnt = 0;
    
    for(auto x : prev){
        if(a[1][x])cnt++;
    }
    cout << ncr(prev.size(), cnt)%mod << endl;
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