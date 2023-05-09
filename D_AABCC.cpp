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
    cin>> n;
    int N = 1e6;
    vector<int>prime(N+1,1);
    prime[0] = prime[1] = 0;
    for(int i = 2;i<=N;++i){
        if(prime[i]){
            for(int j = i*i;j<=N;j+=i)prime[j] = 0;
        }
    }
    // brute over a and c, find the valid values of b
    vector<int>p={0};
    for(int i = 1;i<=N;++i){
        if(prime[i])p.pb(i);
    }
    int res = 0;
    int m = p.size();
    for(int i = 1;i<m;++i){
        int a = p[i];
        for(int j = i+1;j<m;++j){
            int c = p[j];

            if((a*a*c*c*a) > n)break;
            int l = n/(a*c*a*c);
            int L = a+1, R = min(c-1,l);
            if(R < L)continue;
            int cnt = upper_bound(all(p),R)-p.begin()-1;
            cnt-=(lower_bound(all(p),L)-p.begin()-1);
            res+=cnt;
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