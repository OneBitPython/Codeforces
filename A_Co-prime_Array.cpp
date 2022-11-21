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
    vector<int>a(n);
    for(int &u : a)cin >> u;
    int mxn = 1e5;
    vector<bool>isprime(mxn+1,1);
    isprime[0] = isprime[1] = 0;
    for(int i =2;i*i<=mxn;++i){
        if(isprime[i]){
            for(int j = i*i;j<=mxn;j+=i)isprime[j] = 0;
        }
    }
    vector<int>prime;
    for(int i = 2;i<=mxn;++i){
        if(isprime[i])prime.pb(i);
    }
    int k= 0;
    vector<int>res;
    for(int i = 0;i<n-1;++i){
        if(__gcd(a[i],a[i+1])==1){
            res.pb(a[i]);
            continue;
        }
        res.pb(a[i]);
        for(auto x: prime){
            if(__gcd(a[i],x)==1 && __gcd(x,a[i+1])==1){
                res.pb(x);
                k++;
                break;
            }
        }
    }
    res.pb(a.back());
    cout << k << endl;
    for(auto x : res)cout << x << ' ';
}   

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif

    int T=1;
    // cin >> T;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}