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

int sum(int n,int a, int d){
    return ((2*a+(n-1)*d) * n)/2;
}
int p = 31;
int m = 92124023;
vector<int>hf,hb;
int gcdExtended(int a, int b, int *x, int *y);
 
// Function to find modulo inverse of b. It returns
// -1 when inverse doesn't
int mm(int a, int b);
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
int modDivide(int a, int b, int m)
{
    a = a % m;
    int inv = modInverse(b, m);
    return (mm(inv,a)) % m;
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
int ms(int a, int b){
    return ((((a%m)-(b%m))%m)+m)%m;
}
vector<int>pp(3e5+5);
int n;
void pre(){
    pp[0] = 1;
    for(int i = 1;i<=(3e5);++i)pp[i] = mm(pp[i-1],p);
}
void comp(const string &s, int n){
    for(int i= 1;i<=n;++i){
        hf[i] = ma(hf[i-1],mm(pp[i-1],s[i]-'a'));
    }
    for(int i = n;i>=1;--i){
        hb[i] = ma(hb[i+1],mm(pp[n-i],s[i]-'a'));
    }
}

int hashf(int i, int j,vector<int>&a){
    int x = ms(a[j],a[i-1]);
    return modDivide(x,pp[i-1],m);
}
int hashb(int i, int j,vector<int>&a){
    int x = ms(a[i],a[j+1]);
    return modDivide(x,pp[n-j],m);
}
void solve()
{
    int q;
    cin >> n >> q;
    string s;cin >> s;
    s = "0"+s;
    hf = vector<int>(n+1);
    hb = vector<int>(n+2);
    vector<vector<int>>pe(n+1,vector<int>(27)), po(n+1, vector<int>(27));
    for(int i = 1;i<=n;++i){
        pe[i] = pe[i-1];
        po[i] = po[i-1];
        if(i%2){
            po[i][s[i]-'a']++;
        }else pe[i][s[i]-'a']++;
    }
    comp(s,n);
    while(q--){
        int l,r;
        cin >> l >> r;
        int k = r-l+1;
        int res = sum(k,1,1);
        int ce = k/2, co = k/2;
        if(k%2){
            if(l%2)co++;
            else ce++;
        }
        bool got1 = 0, got2 = 0,got3 = 0;
        for(int i = 0;i<=25;++i){
            int v1 = pe[r][i] - pe[l-1][i], v2 = po[r][i] - po[l-1][i];
            if(v1==ce)got1 = 1;
            if(v2==co)got2 = 1;
            if(v1+v2 == k)got3 = 1;
        }
        if(got1 && got2){
            // all odd values are gone
            // n < (k+1)/2
            res-=sum((k+1)/2,1,2);
            res++;
            if(k%2)res+=k;
        }
        if(got3){
            // all even values are gone
            int nn = (k+1)/2;
            if(k%2)nn--;
            res-=sum(nn,2,2);
            if(k%2==0)res+=k;
        }
        if(hashf(l,r,hf)==hashb(l,r,hb))res-=k;
        cout << res-1 << endl;
    }
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