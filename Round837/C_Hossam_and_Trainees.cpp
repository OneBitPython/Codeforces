#include <bits/stdc++.h>
using namespace std;

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

int N = 31623;
vector<bool>isprime(N+1,1);
vector<int>prime;
void pre(){
    isprime[0] = isprime[1] = 0;
    for(int i = 2;i<=N;++i){
        if(!isprime[i])continue;
        for(int j = i*i;j<=N;j+=i)isprime[j] = 0;
    }
    for(int i= 1;i<=N;++i){
        if(isprime[i])prime.pb(i);
    }
}


void solve()
{
    int n;
    cin >> n;
    int c = 0;
    vector<int>a(n);
    
    for(int i = 0;i<n;++i)cin >>a[i];
    
    map<int,int>g;
    for(int i = 0;i<n;++i){
        vector<int>p;
        int y = a[i];
        for(auto x : prime){
            if(a[i]%x==0){
                p.pb(x);
                while(y%x==0)y/=x;
            }
        }
        if(y > 2)p.pb(y);
        int m = p.size();
        for(int j : p){
            if(g[j]){
                cout << "YES" << endl;
                return;
            }
            g[j]++;
        }
    }
    cout << "NO" << endl;
}   

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    pre();
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // freopen("error.txt", "w", stderr);
    // #endif

    int T=1;
    cin >> T;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}