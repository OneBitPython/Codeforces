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


int mxn = 4e6;
vector<int>fact(mxn);

int m = 998244353;
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
int modDivide(int a, int b, int m=m)
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
    return ((a%m)+(b%m))%m;
}
int mm(int a, int b){
    return ((a%m)*(b%m))%m;
}
void pre(){
    fact[0] = 1;
    for(int i = 1;i<mxn;++i)fact[i] = mm(i,fact[i-1]);
}

int ncr(int n, int r){
    return modDivide(fact[n],mm(fact[n-r],fact[r]));
}
int sp(int c, int k){
    // number of ways of summing k numbers upto c
    if(k==0){
        if(c==0)return 1;
        return 0;
    }
    return ncr(c+k-1,k-1);
}
int c1,c2,c3,c4;

int o(){
    if(c1==0)return 0;
    return mm(sp(c3,c1),sp(c4,c2));
}
int two(){
    if(c2==0)return 0;
    return mm(sp(c3,c1),sp(c4,c2));
}
int th(){
    // make sure first bracket is not 0
    if(c3==0)return 0;
    int res = 0;
    for(int i = 1;i<=c3;++i)res = ma(res, sp(c3-i,c1));
    return mm(res,sp(c4,c2));
}
int f(){
    int res = 0;
    if(c4==0)return 0;
    for(int i = 1;i<=c4;++i)res = ma(res, sp(c4-i,c2));
    return mm(sp(c3,c1),res);
}

void solve()
{
    cin >> c1 >> c2 >> c3 >> c4;
    int res = 0;
    if(c1==c2)res = (o()+two()+th()+f())%m;
    else if(c1==(c2+1))res = (o()+f())%m;
    else if(c1+1 == c2)res = (two()+th())%m;
    if(c1+c2+c3+c4 ==0 )res = 1;
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
    cin >> T;
    pre();
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}