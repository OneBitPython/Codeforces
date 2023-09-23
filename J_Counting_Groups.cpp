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


const int N = 101;
int dp[3*N][N][N][3];
int mod = 1e9+7;
vector<int>fact(5e5+5);
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
void pre(){
    fact[0] = 1;
    for(int i = 1;i<=5e5;++i)fact[i] = (fact[i-1]*i)%mod;

    for(int i = 0;i<3*N;++i){
        for(int j = 0;j<N;++j){
            for(int k = 0;k<N;++k){
                for(int l = 0;l<=2;++l)dp[i][j][k][l] = 0;
            }
        }
    }
    dp[1][1][0][0] = 1;
    dp[1][0][1][1] = 1;
    dp[1][0][0][2] = 1;

    for(int i = 2;i<3*N;++i){
        for(int j = 0;j<N;++j){
            for(int k = 0;k<N;++k){
                if((j+k)>i)break;
                int l = i-j-k;
                if(j){
                    if(k)dp[i][j][k][0] += dp[i-1][j-1][k][1];
                    if(l)dp[i][j][k][0] += dp[i-1][j-1][k][2];
                    dp[i][j][k][0]%=mod;
                }

                if(k){
                    if(j)dp[i][j][k][1] += dp[i-1][j][k-1][0];
                    if(l)dp[i][j][k][1] += dp[i-1][j][k-1][2];
                    dp[i][j][k][1]%=mod;
                }

                if(l){
                    if(k)dp[i][j][k][2] += dp[i-1][j][k][1];
                    if(j)dp[i][j][k][2] += dp[i-1][j][k][0];
                    dp[i][j][k][2]%=mod;
                }
            }
        }
    }
}

int ncr(int n, int r){
    return modDivide(fact[n],((fact[n-r]%mod)*fact[r])%mod);
}
void solve()
{
    int n,m,k;cin>> n >> m >> k;
    vector<int>c = {n,m,k};
    sort(all(c),greater<int>());
    if(c.back()==0){
        n = c[0];
        m = c[1];
        if(abs(n-m) > 1){
            cout << 0 << endl;
            return;
        }
        if(n==m)cout << 2 << endl;
        else cout << 1 << endl;
        return;
    }
    n = c[0];
    m = c[1];
    k = c[2];
    if(n > m+k){
        if(n>(m+k+1)){
            cout << 0 << endl;
            return;
        }
        cout << ncr(m+k,k) << endl;return;
    }
    if((k==1)){
        if((m+k)==n){
            m++;
            cout << ((4*m) +  (m-1)*2 - n - m)%mod << endl;
            return;
        }
        if((n+1)==(m+k)){
            cout << ((4*m)+(2) +  (m-1)*2)%mod << endl;
            return;
        }
    }
    cout << (dp[n+m+k][n][m][0]+dp[n+m+k][n][m][1]+dp[n+m+k][n][m][2]) %mod << endl;
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